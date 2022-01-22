#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "ComputerGrid.h"
#include "Grid.h"
#include "Ship.h"
#include "Exception.h"
#include "Player.h"
#include <ctime>

/*void mainmenu()
{
    int OptNum = 0;

    while(1)
    {
        cout << "====== Welcome to Battleship Game ======" << endl;
        cout << "========================================" << endl;
        cout << "========================================" << endl;
        cout << "      1. Play a game with computer.     " << endl;
        cout << "      2. exit                           " << endl;
        cout << "========================================" << endl;
        cout << "========================================" << endl;
        cout << "Please choose one option: " << endl;
        cin >> OptNum;

        switch(OptNum)
        {
            case 1:

            case 2:
                exit(0);
            default:
                cout << "Please enter a right option number.";
        }
    }
}*/

int main()
{
    srand(time(0));

    string direction;
    string type;
    char column;
    string row;

    int realRow;
    int realColumn;

    vector<Ship> Ships;

    fstream input;
    input.open("input.csv");

    int i = 0;

    if (input.good()) {
        while (!input.eof()) {

            if(i == 5)
            {break;}

            Ship TempShip;

            getline(input, type, ',');
            input >> column;
            getline(input, row, ',');
            getline(input, direction);

            realColumn = column - 'A';
            realRow = stoi(row);
            realRow -= 1;

            TempShip.setType(type);
            TempShip.setSize(type);
            TempShip.setDirection(direction);
            TempShip.setStrPts(realRow + 1, column);
            TempShip.setEndPts(realRow, realColumn, direction);

            //cout << TempShip.getDirection() << " " << TempShip.getType() <<
            //TempShip.getColLocation() << TempShip.getRowLocation();

            //cout << "(" << TempShip.getEndPts()[0][0] << ", " << TempShip.getEndPts()[0][1] << "), ("
            //<< TempShip.getEndPts()[1][0] << ", " << TempShip.getEndPts()[1][1] << ")" << endl;

            Ships.push_back(TempShip);
            i++;
        }
    }
    //cout << "b" << endl;
    //cout << Ships[0].getColLocation() << endl;
    //cout << Ships[1].getColLocation() << endl;
    //cout << Ships[2].getColLocation() << endl;
    //cout << Ships[3].getColLocation() << endl;
    //cout << Ships[4].getColLocation() << endl;
    //cout << "c" << endl;

    Grid playerGrid(Ships);

    //vector<vector<int>> aVec = playerGrid.getShips()[0].getEndPts();

    //cout << playerGrid.getShips()[0].getEndPts()[0][0] << " "
    //<< playerGrid.getShips()[0].getEndPts()[0][1] << " "
    //<< playerGrid.getShips()[0].getEndPts()[1][0] << " "
    //<< playerGrid.getShips()[0].getEndPts()[1][1] << " " << endl;

    //for(int i = 0; i < 5; i++)
    //{
        //cout << Ships[i].getColLocation() << endl;

        //cout << playerGrid.getShips()[i].getColLocation() << endl;
        //cout << playerGrid.getShips()[i].getRowLocation() << endl;
        //cout << playerGrid.getShips()[i].getDirection() << endl;

        //cout << abcd[i].getType() << endl;
        //cout << abcd[i].getColLocation() << endl;
        //cout << abcd[i].getRowLocation() << endl;
        //cout << abcd[i].getDirection() << endl;
    //}
    //cout << "c" << endl;

    Player aPlayer(playerGrid);

    Game aGame(aPlayer);

    int OptNum = 0;

    while(1)
    {
        cout << "====== Welcome to Battleship Game ======" << endl;
        cout << "========================================" << endl;
        cout << "========================================" << endl;
        cout << "      1. Play a game with computer.     " << endl;
        cout << "      2. exit                           " << endl;
        cout << "========================================" << endl;
        cout << "========================================" << endl;
        cout << "   You will attack a location of " << endl
             << "   computer's grid  at a time, and " << endl
             << "   computer will attack a location of" << endl
             << "   your grid randomly. If the attack" << endl
             << "   hits any ships, it will be marked " << endl
             << "   on the board. There are 5 ships for" << endl
             << "   each player." << endl << endl;
        cout << "Please choose one option: " << endl;
        cin >> OptNum;

        switch(OptNum)
        {
            case 1:
                {
                    aGame.PlayGame();
                }
                break;
            case 2:
                exit(0);
            default:
                cout << "Please enter a right option number.";
                break;
        }
    }



}