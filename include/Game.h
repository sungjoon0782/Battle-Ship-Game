//
// Created by sungj on 11/25/2019.
//
#ifndef OOP_FINAL_GAME_H
#define OOP_FINAL_GAME_H

#include "Player.h"

class Game {
private:
    Player User;
    Player Computer;

public:
    Game();
    Game(Player &a);
    void PlayGame();
    void PattackC(Grid &cGrid);
    void CattackP(Grid &pGrid);
};


#endif //OOP_FINAL_GAME_H
