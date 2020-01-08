//
// Created by tobo on 1/7/20.
//

#ifndef BULANCISERVER_PLAYERDATA_H
#define BULANCISERVER_PLAYERDATA_H

#include <string>

using namespace std;
enum Facing {TOP, RIGHT, BOT, LEFT};


class PlayerData {
public:
    int id;
    int hp;
    int pX;
    int pY;
    Facing facing;

    Facing bulletFacing;
    int bulletX;
    int bulletY;
    int exit = 0;
    string toString();

    PlayerData();
    PlayerData(PlayerData const &player);

    PlayerData(int id, int hp, int pX, int pY, Facing facing, Facing bulletFacing, int bulletX, int bulletY, int exit);

};


#endif //BULANCISERVER_PLAYERDATA_H
