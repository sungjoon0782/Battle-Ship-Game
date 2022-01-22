//
// Created by sungj on 10/24/2019.
//

#include "Ship.h"
#include "Exception.h"
#include <cstdlib>

Ship::Ship()
{
    direction = " ";
    type = " ";
    Column = ' ';
    Row = 0;
    endPoints = {{0, 0}, {0, 0}};
    sunk = false;
    size = 0;
}

Ship::Ship(string _direction, string _type, char _Column, int _Row)
{
    direction = _direction;
    type = _type;
    Column = _Column;
    Row = _Row;
}

void Ship::setSize(string newType)
{
    if(newType == "Carrier")
    {
        size = 5;
    }

    if(newType == "Battleship")
    {
        size = 4;
    }


    if(newType == "Cruiser")
    {
        size = 3;
    }

    if(newType == "Submarine")
    {
        size = 3;
    }

    if(newType == "Destroyer")
    {
        size = 2;
    }

}

void Ship::setStrPts(int _Row, char _Column)
{
    Column = _Column;
    Row = _Row;
}

void Ship::setEndPts(int _Row, int _Column, string newDir)
{
    endPoints[0][0] = _Row;
    endPoints[0][1] = _Column;

    try
    {
        if (newDir == "V")
        {
            endPoints[1][0] = _Row + size - 1;
            endPoints[1][1] = _Column;
        }

        else if (newDir == "H")
        {
            endPoints[1][0] = _Row;
            endPoints[1][1] = _Column + size - 1;
        }

        if (endPoints[1][0] > 9 || endPoints[1][1] > 9)
        {throw OutofGrid();}
    }

    catch(OutofGrid)
    {
        cout << "This ship is placed out of the grid. Wrong input file." << endl;
        exit(0);
    }
}