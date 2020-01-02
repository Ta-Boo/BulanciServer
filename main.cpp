#include <sys/socket.h>
#include <netinet/in.h>
#include "Comunication/ComunicationManager/ComunicationManager.h"

int main(int argc, char *argv[])
{


    ComunicationManager comunicationManager = {};
    if(comunicationManager.openSockets(atoi(argv[1]), argc)){
        return 1;
    };
    comunicationManager.activateSockets();

    return 0;
}