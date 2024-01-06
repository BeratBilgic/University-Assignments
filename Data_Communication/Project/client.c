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
#include <sys/stat.h>
#include "errorDetectionUtils.h"

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
void createlogfile();
void writelogfile(char str[256], char username[256]);
void sendMERRCommand(int sockfd);
void createCONNCommand(char *username, const char * clientIP, char *output);
int parseBuffer(char buffer[MAXDATALEN], uint8_t *checksum, uint8_t *crc);

FILE *file; // log file

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

	createlogfile();

	// 3. Connect
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("client connect error\n");
		exit(0);
	}
	else
	{
		printf("\n To send a private message use the format: 'user->message'\n"); 
		printf("%s Connected To Server\n", username);
		printf("\r You Joined Chat as %s", username);

		char connCommand[25];	
		createCONNCommand(username, clientIp, connCommand);
		send(sockfd, connCommand, strlen(connCommand), 0);

		pthread_create(&thr2, NULL, (void *)chatwrite, (void *)sockfd); // thread to write
		pthread_create(&thr1, NULL, (void *)chatread, (void *)sockfd);	// thread to read
		pthread_join(thr2, NULL);
		pthread_join(thr1, NULL);
		fclose(file);
	}

	return 0;
} /* end of Main */

/* chatwrite - writes to socket
 * for PM look for -> and update the message look
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
		fflush(file);
		fgets(buffer, MAXDATALEN - 1, stdin);
		if (strlen(buffer) - 1 > sizeof(buffer))
		{
			printf("buffer size full\t enter within %zu characters\n", sizeof(buffer));
			bzero(buffer, MAXDATALEN);
			fpurge(stdin);
		}

		writelogfile(buffer, username); 			// write entry into log file

        if (strstr(buffer, "->")){
			char bufferMESGFormat[MAXDATALEN];
			convertToMESGFormat(buffer, bufferMESGFormat);
			n = send(sockfd, bufferMESGFormat, strlen(bufferMESGFormat), 0);
			bzero(bufferMESGFormat, MAXDATALEN);
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
				uint8_t checksum;
    			uint8_t crc;
    			int checkFormat = parseBuffer(buffer, &checksum, &crc);

				printf("\n%s ", buffer);
            	writelogfile(buffer, NULL);

				if (checkFormat && (checksum != calculateChecksum(buffer) || crc != calculateCRC(buffer)))
				{
					printf("Error detected in the received message. MERR command sent.\n");
					writelogfile("Error detected in the received message. MERR command sent.\n", NULL);
                    sendMERRCommand(sockfd); // Send MERR command to the server
				}

            	fflush(file);
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

// Function to convert the format from "a->naber" to "MESG|a|naber"
void convertToMESGFormat(const char *input, char *output) {
    char *token;
    char *temp; // Used for strtok_r
    char delimiter[] = "->";

    // Make a non-const copy of the input string
    char tempInput[strlen(input) + 1];
    strcpy(tempInput, input);

    // Extract the first part (a)
    token = strtok_r(tempInput, delimiter, &temp);
    if (token != NULL) {
        strcat(output, "MESG|");
        strcat(output, token);
    }

    // Extract the second part (naber)
    token = strtok_r(NULL, delimiter, &temp);
    if (token != NULL) {
        strcat(output, "|");
        strcat(output, token);
    }
}

void createlogfile(){
	char fname[100];
	int rc;
	time_t temp;
	struct tm *timeptr;

	struct stat st = {0};

	// Ensure the "logs" directory exists
	if (stat("logs", &st) == -1) {
    	if (mkdir("logs", 0700) == -1) {
            perror("Error creating logs directory");
            exit(EXIT_FAILURE);
        }
	}

	// Set up the Conversation History File name with DateTime And User Name
	temp = time(NULL);
	timeptr = localtime(&temp);
	rc = strftime(fname,sizeof(fname),"logs/%b_%d_%Y_Log_File", timeptr);
	//printf("%d characters in Date Time String \n%s\n",rc,fname);
	
	fname[rc]='-';
	int i = 0;
	while(i < strlen(username)){
		fname[rc+i+1]=username[i];
		i++;
	}
	fname[rc+i+1]='\0';
	
	file = fopen(fname,"a+"); // append file, add text to a file or create a file if it does not exist.
}

void writelogfile(char str[256], char username[256])
{
	char fname[100];
	int rc;
	time_t temp;
	struct tm *timeptr;

	// add the current date and time
	temp = time(NULL);
	timeptr = localtime(&temp);
	rc = strftime(fname, sizeof(fname), "%a, %b %d %r", timeptr);
	fprintf(file, "%s || ", fname);

	if (username != NULL)
	{
		fprintf(file, "%s || ", username);
	}

	fprintf(file, "%s", str); // add received text into the log file
}

// Function to send the "MERR" command to the server
void sendMERRCommand(int sockfd) {
    char errorCommand[] = "MERR";
    send(sockfd, errorCommand, strlen(errorCommand), 0);
}

/*
   createCONNCommand - Creates a formatted CONN command with the given username and client IP.
   Parameters:
     - username: The username to include in the command.
     - clientIP: The client's IP address to include in the command.
     - output: The buffer to store the resulting CONN command.
*/
void createCONNCommand(char *username, const char * clientIP, char *output)
{
    snprintf(output, MAXDATALEN, "CONN|%s|%s", username, clientIP);
}

int parseBuffer(char buffer[MAXDATALEN], uint8_t *checksum, uint8_t *crc) {
    // Copy the original buffer for potential rollback
    char originalBuffer[MAXDATALEN];
    strcpy(originalBuffer, buffer);

    // Split the data based on the '|' character
    char *token = strtok(buffer, "|");

    // Assign the parsed data to the parameters
    if (token != NULL) {
        token = strtok(NULL, "|"); // Skip message part

        if (token != NULL) {
            // Try to convert string to uint8_t for checksum
            *checksum = (uint8_t)strtoul(token, NULL, 0);
            token = strtok(NULL, "|");

            if (token != NULL) {
                // Try to convert string to uint8_t for crc
                *crc = (uint8_t)strtoul(token, NULL, 0);
                return 1; // Return 1 if the format is valid
            }
        }
    }
    
    // If the format is not valid, rollback to the original buffer
    strcpy(buffer, originalBuffer);
    return 0; // Return 0 if the format is not valid
}