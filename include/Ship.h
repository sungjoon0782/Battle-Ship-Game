//
// Created by sungj on 10/24/2019.
//

#ifndef OOP_FINAL_SHIP_H
#define OOP_FINAL_SHIP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ship
{
private:
    string direction;
    string type;
    char Column;
    int Row;
    vector<vector<int>> endPoints;
    bool sunk;
    int size;

public:
    Ship();
    Ship(string _direction, string _type, char _Column, int _Row);

    string getDirection()const{return direction;}
    string getType()const{return type;}
    vector<vector<int>> getEndPts()const{return endPoints;}
    bool isSunk()const{return sunk;}
    char getColLocation()const{return Column;}
    int getRowLocation()const{return Row;}
    int getSize()const{return size;}

    void setDirection(string newDir){direction = newDir;}
    void setType(string newType){type = newType;}
    void setSize(string newType);
    void setStrPts(int _Row, char _Column);
    void setEndPts(int _Row, int _Column, string newDir);
    void itsSunk(){sunk = true;}
};


#endif //OOP_FINAL_SHIP_H
