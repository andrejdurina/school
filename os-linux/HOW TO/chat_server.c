#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <arpa/inet.h> 
#include <unistd.h> 

main()
{
	int k , strana;
    // vytvorenie socketu
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1)
    {
        printf("cannot create socket!\n");
        return 0;
    }

    // nastavenie socketu
    struct sockaddr_in server;  
    memset(&server, 0, sizeof(server));  
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;  
    server.sin_port = htons(58322);  
    if (bind(sock_desc, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
        printf("cannot bind socket!\n");
        close(sock_desc);  
        return 0;
    }
    	
    if (listen(sock_desc, 2) != 0)
    {
        printf("cannot listen on socket!\n");
        close(sock_desc);  
        return 0;
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    socklen_t len = sizeof(client);
    int temp_sock_desc = accept(sock_desc, (struct sockaddr*)&client, &len);
    if (temp_sock_desc == -1)
    {
        printf("cannot accept client!\n");
        close(sock_desc);
        return 0;
    }

        k = recv(temp_sock_desc, &strana, sizeof(int), 0);
        if (recv == -1)
        {
            printf("\ncannot read from client!\n");
        }

        if (recv == 0)
        {
            printf("\nclient disconnected.\n");
        }

	strana=strana*strana;
	k=send(temp_sock_desc,&strana,sizeof(int),0);

    close(temp_sock_desc);
    close(sock_desc);
//    close(Second_sock_desc);
    printf("server disconnected\n");
    return 0;
} 
