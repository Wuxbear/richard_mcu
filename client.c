/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

#define IP_ADDRESS "127.0.0.1"
#define IP_PORT 8888

#define BUFFER_MAX_SIZE 256
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[BUFFER_MAX_SIZE] , server_reply[BUFFER_MAX_SIZE];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr( IP_ADDRESS );
    server.sin_family = AF_INET;
    server.sin_port = htons( IP_PORT );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
		if (0 == strcmp("quit", message)) {
			break;
		}
		
        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sock , server_reply , BUFFER_MAX_SIZE , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    close(sock);
    return 0;
}
