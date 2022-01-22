//
// Created by sungj on 10/28/2019.
//

#include "Player.h"

Player::Player()
{
    playerGrid = Grid();
}

Player::Player(Grid &aGrid)
{
    playerGrid = aGrid;
}