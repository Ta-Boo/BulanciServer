//
// Created by tobo on 12/30/19.
//

#include "Socket.h"

Socket::Socket() {

}

int Socket::openSocket(int port, int argc) {
    if (argc < 2)
    {
        fprintf(stderr,"usage bad port\n");
        return 1;
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket address");
        return 2;
    }

    listen(sockfd, 5);
    cli_len = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_len);
    if (newsockfd < 0)
    {
        perror("ERROR on accept");
        return 3;
    }
    printf("Socket successfully opened ");
    return 0;
}

char *Socket::sendMessage() {
    char* recieved = "START";
    while( strcmp(recieved, "EXIT\n") != 0 ) {
        bzero(buffer,256);
        read(newsockfd, buffer, 255);
        recieved = buffer;
        printf("Here is the message: %s\n", recieved);
        const char* msg = "I got your message";
        if (strcmp(recieved, "EXIT\n") == 0 ) { msg = "EXITS";}
        write(newsockfd, msg, strlen(msg)+1);
    }
    return nullptr;
}

char *Socket::messageRecieved() {
    return nullptr;
}

Socket::~Socket() {
    close(newsockfd);
    close(sockfd);
}
