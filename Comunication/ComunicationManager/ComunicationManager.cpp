//
// Created by tobo on 12/30/19.
//

#include <iostream>
#include "ComunicationManager.h"

ComunicationManager::ComunicationManager()  {
    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&messageProcessed, nullptr);
}

ComunicationManager::~ComunicationManager() {
    for (int conection : clients) {
        close(conection);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&messageProcessed);
}

int ComunicationManager::openSockets(int port, int argc) {

    if (argc < 2)
    {
        fprintf(stderr,"usage bad port\n");
        return 1;
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    clients[0] = socket(AF_INET, SOCK_STREAM, 0);
    if (clients[0] < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    if (bind(clients[0], (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket address");
        return 2;
    }

    listen(clients[0], 5);
    cli_len = sizeof(cli_addr);
    for (int i = 1; i <= PLAYER_COUNT; ++i) {
        printf("Waiting for %i. client to connect \n" , i);
        clients[i] = accept(clients[0], (struct sockaddr*)&cli_addr, &cli_len);
        if (clients[i] < 0)
        {
            perror("ERROR on accept");
            return 3;
        }
        printf("%i. client sucessfully ocnnected to the server\n" , i);
    }

    printf("Socket successfully opened\n");
    return 0;
}


void ComunicationManager::activateSockets() {
    //todo create threads, which  will listen to messages
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        threads[i] = thread(&ComunicationManager::listenForMessages,this,clients[i+1]);
    }
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        threads[i].join();
    }
}


void ComunicationManager::listenForMessages(int client) {
    char received[256]= "START";
    while( true ) {
        bzero(received,256);
        read(client, received, 255);
        if (strcmp(received, "EXIT") == 0 ) {
            strcpy(received, "FINISH");
            sendMessageToClients(received);
            break;
        }
        sendMessageToClients(received);
    }
}

void ComunicationManager::sendMessageToClients(char* message) {
    cout << "posielam : " << message <<endl;

    for (int i = 1; i <= PLAYER_COUNT; ++i) {
        write(clients[i], message, strlen(message)+1);
    }
    processingMessage = false;
    pthread_cond_signal(&messageProcessed);
}



