//
// Created by tobo on 12/30/19.
//

#ifndef BULANCISERVER_COMUNICATIONMANAGER_H
#define BULANCISERVER_COMUNICATIONMANAGER_H
#define PLAYER_COUNT 2


#include "../Socket/Socket.h"
#include <thread>


using namespace std;

class ComunicationManager {
public:
    int clients[PLAYER_COUNT + 1]{};
    socklen_t cli_len{};
    struct sockaddr_in serv_addr{}, cli_addr{};


    thread threads[2];
    bool processingMessage = false;
    pthread_cond_t messageProcessed;
    pthread_mutex_t mutex;



public:
    ComunicationManager();
    int openSockets(int port, int argc);
    void activateSockets();
    void listenForMessages(int client);
    void sendMessageToClients(char* message);
    ~ComunicationManager();


};


#endif //BULANCISERVER_COMUNICATIONMANAGER_H
