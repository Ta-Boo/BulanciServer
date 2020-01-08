//
// Created by tobo on 12/30/19.
//

#ifndef BULANCISERVER_COMUNICATIONMANAGER_H
#define BULANCISERVER_COMUNICATIONMANAGER_H
#define PLAYERS_COUNT 2


#include "../Socket/Socket.h"
#include "../Data/PlayerData.h"
#include <thread>
#include <map>
#include <boost/algorithm/string.hpp>


using namespace std;

class ComunicationManager {
public:
    int clients[PLAYERS_COUNT + 1]{};
    socklen_t cli_len{};
    struct sockaddr_in serv_addr{}, cli_addr{};

    thread threads[PLAYERS_COUNT];
    map<int, PlayerData> players;
    bool processingMessage = false;
    pthread_cond_t messageProcessed;
    pthread_mutex_t mutex;



public:
    ComunicationManager();
    int openSockets(int port, int argc);
    void activateSockets();
    void listenForMessages(int client);
    PlayerData constructPlayer(string message);
    void sendMessageToClients(char* message);
    void update(string message);
    ~ComunicationManager();


};


#endif //BULANCISERVER_COMUNICATIONMANAGER_H
