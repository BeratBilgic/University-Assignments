#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <arpa/inet.h>

#define PORTNUM 8080 /* default port number */
#define MAXDATALEN 256

/*====== Global Variables ======*/
int sockfd;					  // socket file descriptor
int n;						  // number of bytes received/sent
struct sockaddr_in serv_addr; // server address  structure
char buffer[MAXDATALEN];
char username[10];

/*====== Functions ======*/
void *quitproc();
void *chatwrite(int);
void *chatread(int);
void *ctrlzhandler();
void convertToMESGFormat(const char *input, char *output);

int main(int argc, char *argv[])
{
	const char * clientIp;

	pthread_t thr1, thr2; // two threads, one to read socket, one to write socket
	
	/* optional or default ip address argument */
	if (argc == 2)
		clientIp = argv[1];
	else
		clientIp = "127.0.0.1"; /*if ip address not given as argument then using default ip address */

	// 1. Socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("client socket error\n");
	else
	{
		// printf("Socket Created\n");
	}

	// 2. Server Information
	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORTNUM);
	serv_addr.sin_addr.s_addr = inet_addr(clientIp);

	// Get the Client Username
	bzero(username, 10);
	printf("\nUserName: ");
	fgets(username, 10, stdin);
	fpurge(stdin);
	username[strlen(username) - 1] = ':';

	// 3. Connect
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("client connect error\n");
		exit(0);
	}
	else
	{
		printf("\n To send a private message use the format: '@user message'\n"); 
		printf("%s Connected To Server\n", username);
		printf("\r You Joined Chat as %s", buffer - 1);

		send(sockfd, username, strlen(username), 0);

		pthread_create(&thr2, NULL, (void *)chatwrite, (void *)sockfd); // thread to write
		pthread_create(&thr1, NULL, (void *)chatread, (void *)sockfd);	// thread to read
		pthread_join(thr2, NULL);
		pthread_join(thr1, NULL);
	}

	return 0;
} /* end of Main */

/* chatwrite - writes to socket
 * for PM look for @ and update the message look
 */
void *chatwrite(int sockfd)
{
	char fname[100];
	int rc;
	time_t temp;
	struct tm *timeptr;

	// Write to Socket
	while (1)
	{
		printf("%s", username);

		fgets(buffer, MAXDATALEN - 1, stdin);
		if (strlen(buffer) - 1 > sizeof(buffer))
		{
			printf("buffer size full\t enter within %zu characters\n", sizeof(buffer));
			bzero(buffer, MAXDATALEN);
			fpurge(stdin);
		}

		if (buffer[0] == '@'){
			char bufferMESGFormat[256];
			convertToMESGFormat(buffer, bufferMESGFormat);
			n = send(sockfd, bufferMESGFormat, strlen(bufferMESGFormat), 0);
		}else{
			n = send(sockfd, buffer, strlen(buffer), 0);
		}

		if (strncmp(buffer, "GONE", 4) == 0)
			exit(0);

		bzero(buffer, MAXDATALEN);
	} /* end of while */
	return NULL;
} /* end chatwrite */

/* chatread - reads message from the socket
 */
void *chatread(int sockfd)
{
	// Read from Socket

	// Signal handler
	if (signal(SIGTSTP, (void *)ctrlzhandler) == 0)

		while (1)
		{
			n = recv(sockfd, buffer, MAXDATALEN - 1, 0);
			if (n == 0)
			{
				// no bytes recieved
				printf("\nServer is Down\n\n");
				exit(0);
			}
			if (n > 0)
			{
				printf("\n%s ", buffer);

				bzero(buffer, MAXDATALEN);
			}
		} // end of while

	return NULL;
} /* end chatread */

void *ctrlzhandler()
{
	// Signal handler for ctrl+z
	printf("\rType 'GONE' to exit\n");

	return NULL;
}

// This function converts a message from "@username message" to '@user message' format
void convertToMESGFormat(const char *input, char *output) {
    const char *usernameStart = strchr(input, '@'); // Find the @ symbol
    const char *messageStart = strchr(input, ' ');  // Find the first space
    
    if (usernameStart != NULL && messageStart != NULL) {
        int usernameIndex = usernameStart - input + 1; // Skip the @ symbol
        int messageIndex = messageStart - input;
        
        // Copy the "MESG|" part to the output buffer
        strncpy(output, "MESG|", 5);
        
        // Concatenate the username to the output buffer
        strncat(output, input + usernameIndex, messageIndex - usernameIndex);
        
        // Concatenate the rest of the message in the desired format
        snprintf(output + strlen(output), 256 - strlen(output), "|%s", input + messageIndex + 1);
    } else {
        // Error case: not a valid message format
        snprintf(output, 256, "Invalid message format");
    }
}
