//
// Created by tobo on 12/30/19.
//

#ifndef BULANCISERVER_SOCKET_H
#define BULANCISERVER_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>


class Socket {
    int sockfd, newsockfd, secondsockfd;
    socklen_t cli_len;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[256];

public:
    Socket();
    int openSocket(int port, int argc);
    char* sendMessage();
    char* messageRecieved();
    ~Socket();

};


#endif //BULANCISERVER_SOCKET_H
