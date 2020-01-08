//
// Created by tobo on 1/7/20.
//

#include "PlayerData.h"



PlayerData::PlayerData() {

}

PlayerData::PlayerData(PlayerData const &player) {
    id = player.id;
    hp = player.hp;
    pX = player.pX;
    pY = player.pY;
    facing = player.facing;
    bulletFacing = player.bulletFacing;
    bulletX = player.bulletX;
    bulletY = player.bulletY;
    exit  = player.exit;
}


string PlayerData::toString() {
    string final;
    final += to_string(id);
    final += "|";
    final += to_string(hp);
    final += "|";
    final += to_string(facing);
    final += "|";
    final += to_string(pX);
    final += "|";
    final += to_string(pY);
    final += "|";
    final += to_string(bulletFacing);
    final += "|";
    final += to_string(bulletX);
    final += "|";
    final += to_string(bulletY);
    final += "|";
    final += to_string(exit);
    return final;
}

PlayerData::PlayerData(int id, int hp, int pX, int pY, Facing facing, Facing bulletFacing, int bulletX, int bulletY, int exit)
        : id(id), hp(hp), pX(pX), pY(pY), facing(facing), bulletFacing(bulletFacing), bulletX(bulletX),
          bulletY(bulletY), exit(exit) {}
