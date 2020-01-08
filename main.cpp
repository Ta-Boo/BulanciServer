#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "Comunication/ComunicationManager/ComunicationManager.h"

int main(int argc, char *argv[])
{

    ComunicationManager comunicationManager;
    PlayerData player = PlayerData(50, 80, 800, 600, TOP, BOT, 600, 300, 1);
    comunicationManager.update(player.toString());
    std::cout << comunicationManager.players[50].toString() <<std::endl;
    PlayerData newone = comunicationManager.constructPlayer(player.toString());
    newone.hp = 10000;
    comunicationManager.update(newone.toString());
    std::cout << comunicationManager.players[50].toString() <<std::endl;

//    std::cout << newone.toString() <<std::endl;
//
//    int a = 10;

//    if(comunicationManager.openSockets(atoi(argv[1]), argc)){
//        return 1;
//    };
//    comunicationManager.activateSockets();

    return 0;
}