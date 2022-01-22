//
// Created by sungj on 10/28/2019.
//

#ifndef OOP_FINAL_PLAYER_H
#define OOP_FINAL_PLAYER_H

#include "Grid.h"
class Player
{
private:
    Grid playerGrid;

public:
    Player();
    Player(Grid &aGrid);
    Grid getGrid(){return playerGrid;}
};

#endif //OOP_FINAL_PLAYER_H
