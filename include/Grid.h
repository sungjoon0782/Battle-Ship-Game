//
// Created by sungj on 10/24/2019.
//

#ifndef OOP_FINAL_GRID_H
#define OOP_FINAL_GRID_H

#include "Ship.h"
#include <vector>

class Grid {
protected:
    vector<vector<char>> privateBoard;
    vector<vector<char>> shownBoard;
    vector<Ship> Ships;
    int NumofShips;

public:
    Grid();
    Grid(vector<Ship> &ships);
    int getCell(int row, int column);
    int getNumShips(){return NumofShips;}
    vector<Ship> getShips() {return Ships;}
    vector<vector<char>> getPrivateBoard(){return privateBoard;}
    vector<vector<char>> getShownBoard(){return shownBoard;}
    void printPrivateGrid();
    void printShownGrid();
    void printBoth(Grid comp);
    void setShip(char newDir, string newType, int x1, int y1);
    bool checkSunk();
    void aShipSunk(){NumofShips--;}
    void attackBoard(int row, int column);
};


#endif //OOP_FINAL_GRID_H
