gcc server.c -o server
./server  
./server 8080 (optional param)

gcc client.c -o client
./client  
./client 0.0.0.0 (optional param)