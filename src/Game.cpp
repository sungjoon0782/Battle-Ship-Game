//
// Created by sungj on 11/25/2019.
//

#include "Game.h"
#include "ComputerGrid.h"

Game::Game()
{
    User = Player();
    Computer = Player();
}

Game::Game(Player &a)
{
    ComputerGrid compGrid;
    compGrid.setRandomShips();

    Player computer(compGrid);

    User = a;
    Computer = computer;
}

void Game::PlayGame()
{
    ComputerGrid compGrid;
    compGrid.setRandomShips();
    Player computer(compGrid);
    Computer = computer;

    char answer;
    bool check = false;

    Grid playerGrid = User.getGrid();
    Grid computerGrid = Computer.getGrid();

    //cout << "Player's Grid: " << endl;
    //playerGrid.printShownGrid();
    //cout << endl;

    //cout << "Computer's Grid: " << endl;
    //computerGrid.printShownGrid();
    //cout << endl;

    //cout << "Player's Grid: " << endl;
    //playerGrid.printPrivateGrid();
    //cout << endl;

    //cout << "Computer's Grid: " << endl;
    //computerGrid.printPrivateGrid();
    //cout << endl;

    playerGrid.printBoth(computerGrid);


    while(1)
    {
        cout << "It's your turn. Attack computer!" << endl;
        PattackC(computerGrid);

        while(computerGrid.getNumShips() == 0)
        {
            if (!check)
            {
                playerGrid.printBoth(computerGrid);

                cout << "You won!" << endl;
                cout << "Do you want to play a new game? {Y/N} ";
                cin >> answer;
                switch (answer)
                {
                    case 'Y':
                    case 'y': {
                        PlayGame();
                    }   break;

                    case 'N':
                    case 'n':
                        exit(0);

                    default:
                        check = false;
                        break;
                }
            }
        }

        cout << "It's computer's turn. Computer attacked a random location." << endl;
        CattackP(playerGrid);

        while(playerGrid.getNumShips() == 0)
        {
            if (!check)
            {
                playerGrid.printBoth(computerGrid);

                cout << "Computer won :(" << endl;
                cout << "Do you want to play a new game? {Y/N} ";
                cin >> answer;
                switch (answer)
                {
                    case 'Y':
                    case 'y':
                    {
                        PlayGame();
                    }
                    break;

                    case 'N':
                    case 'n':
                        exit(0);

                    default:
                        check = false;
                        break;
                }
            }
        }

        playerGrid.printBoth(computerGrid);
    }

}

void Game::PattackC(Grid &cGrid)
{
    char column;
    int row;
    bool attack = false;

    cout << "Enter the location you want to attack (Ex. A1, B6, G3): " << endl;
    cin >> column >> row;

    int realColumn = column - 'A';
    int realRow = row - 1;

    if(cGrid.getCell(realRow, realColumn) == 'X')
    {
        cout << "That location is already attacked." << endl;
        cout << "Attack another location." << endl;
        PattackC(cGrid);
    }

    else
    {
        for (int i = 0; i < 5; i++)
        {
            vector<vector<int>> endPts = cGrid.getShips()[i].getEndPts();

            if (cGrid.getShips()[i].getDirection() == "V")
            {
                if ((endPts[0][1] == realColumn) && (endPts[0][0] <= realRow) && (endPts[1][0] >= realRow))
                {
                    int startRow = endPts[0][0];
                    int startColumn = endPts[0][1];

                    cGrid.getShips()[i].itsSunk();
                    for (int j = 0; j < cGrid.getShips()[i].getSize(); j++)
                    {
                        cGrid.attackBoard(startRow + j, startColumn);
                    }

                    cout << "You successfully attacked " << cGrid.getShips()[i].getType() << " ship!"
                         << endl;
                    cGrid.aShipSunk();
                    attack = true;
                }

                else
                {
                    cGrid.attackBoard(realRow, realColumn);
                }
            }
            else
            {
                if ((endPts[0][0] == realRow) && (endPts[0][1] <= realColumn) && (endPts[1][1] >= realColumn))
                {
                    int startRow = endPts[0][0];
                    int startColumn = endPts[0][1];

                    cGrid.getShips()[i].itsSunk();
                    for (int j = 0; j < cGrid.getShips()[i].getSize(); j++)
                    {
                        cGrid.attackBoard(startRow, startColumn + j);
                    }

                    cout << "You successfully attacked " << cGrid.getShips()[i].getType() << " ship!"
                         << endl;
                    cGrid.aShipSunk();
                    attack = true;
                }

                else
                {
                    cGrid.attackBoard(realRow, realColumn);
                }
            }
        }

        if(attack == false)
        {
            cGrid.attackBoard(realRow, realColumn);
            cout << "You failed to attack." << endl << endl;
        }

    }

}


void Game::CattackP(Grid &pGrid) {

    bool attack = false;
    int realColumn = rand() % 10;
    int realRow = rand() % 10;

    char column = realColumn + 'A';
    int row = realRow + 1;

    if (pGrid.getCell(realRow, realColumn) == 'X')
    {
        CattackP(pGrid);
    }

    else
    {
        cout << "Computer attacked " << column << row << "." << endl;

        for (int i = 0; i < 5; i++)
        {
            vector<vector<int>> endPts = pGrid.getShips()[i].getEndPts();

            if (pGrid.getShips()[i].getDirection() == "V")
            {
                if ((endPts[0][1] == realColumn) && (endPts[0][0] <= realRow) && (endPts[1][0] >= realRow))
                {
                    int startRow = endPts[0][0];
                    int startColumn = endPts[0][1];

                    pGrid.getShips()[i].itsSunk();
                    for (int j = 0; j < pGrid.getShips()[i].getSize(); j++) {
                        pGrid.attackBoard(startRow + j, startColumn);
                    }

                    cout << "Computer successfully attacked " << pGrid.getShips()[i].getType() << " ship!"
                         << endl;
                    pGrid.aShipSunk();
                    attack = true;
                }

                else { pGrid.attackBoard(realRow, realColumn); }
            }
            else
            {
                if ((endPts[0][0] == realRow) && (endPts[0][1] <= realColumn) && (endPts[1][1] >= realColumn))
                {
                    int startRow = endPts[0][0];
                    int startColumn = endPts[0][1];

                    pGrid.getShips()[i].itsSunk();
                    for (int j = 0; j < pGrid.getShips()[i].getSize(); j++) {
                        pGrid.attackBoard(startRow, startColumn + j);
                    }

                    cout << "Computer successfully attacked " << pGrid.getShips()[i].getType() << " ship!"
                         << endl;
                    pGrid.aShipSunk();
                    attack = true;
                }

                else
                {
                    pGrid.attackBoard(realRow, realColumn);
                }
            }
        }
        if (attack == false) {
            pGrid.attackBoard(realRow, realColumn);
            cout << "Computer failed to attack." << endl << endl;
        }
    }
}