//
// Created by sungj on 10/24/2019.
//

#include "Grid.h"
#include "Exception.h"
Grid::Grid()
{
    privateBoard.resize(10, vector<char>(10, ' '));
    shownBoard.resize(10, vector<char>(10, ' '));
    NumofShips = 0;
}

Grid::Grid(vector<Ship> &ships)
{
    Ships = ships;
    privateBoard.resize(10, vector<char>(10, ' '));
    shownBoard.resize(10, vector<char>(10, ' '));
    NumofShips = 0;

    for(int i = 0 ; i < 5; i++)
    {
        vector<vector<int>> endPts = Ships[i].getEndPts();

        int row = endPts[0][0];
        int column = endPts[0][1];

        try
        {
            if (Ships[i].getDirection() == "V")
            {
                if(Ships[i].getType() == "Carrier")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row + j][column] == 'B'
                         || privateBoard[row + j][column] == 'R'
                         || privateBoard[row + j][column] == 'S'
                         || privateBoard[row + j][column] == 'D')
                        { throw OverLap(); }
                        privateBoard[row + j][column] = 'C';
                    }
                }

                else if(Ships[i].getType() == "Battleship")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row + j][column] == 'C'
                         || privateBoard[row + j][column] == 'R'
                         || privateBoard[row + j][column] == 'S'
                         || privateBoard[row + j][column] == 'D')
                        { throw OverLap(); }

                        privateBoard[row + j][column] = 'B';
                    }
                }

                else if(Ships[i].getType() == "Cruiser")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row + j][column] == 'C'
                         || privateBoard[row + j][column] == 'B'
                         || privateBoard[row + j][column] == 'S'
                         || privateBoard[row + j][column] == 'D')
                        { throw OverLap(); }

                        privateBoard[row + j][column] = 'R';
                    }
                }

                else if(Ships[i].getType() == "Submarine")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row + j][column] == 'C'
                         || privateBoard[row + j][column] == 'R'
                         || privateBoard[row + j][column] == 'B'
                         || privateBoard[row + j][column] == 'D')
                        { throw OverLap(); }

                        privateBoard[row + j][column] = 'S';
                    }
                }

                else if(Ships[i].getType() == "Destroyer")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row + j][column] == 'C'
                         || privateBoard[row + j][column] == 'R'
                         || privateBoard[row + j][column] == 'S'
                         || privateBoard[row + j][column] == 'B')
                        { throw OverLap(); }

                        privateBoard[row + j][column] = 'D';
                    }
                }
            }

            if (Ships[i].getDirection() == "H")
            {
                if(Ships[i].getType() == "Carrier")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row][column + j] == 'B'
                         || privateBoard[row][column + j] == 'R'
                         || privateBoard[row][column + j] == 'S'
                         || privateBoard[row][column + j] == 'D')
                        { throw OverLap(); }
                        privateBoard[row][column + j] = 'C';
                    }
                }

                else if(Ships[i].getType() == "Battleship")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row][column + j] == 'C'
                            || privateBoard[row][column + j] == 'R'
                            || privateBoard[row][column + j] == 'S'
                            || privateBoard[row][column + j] == 'D')
                        { throw OverLap(); }

                        privateBoard[row][column + j] = 'B';
                    }
                }

                else if(Ships[i].getType() == "Cruiser")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row][column + j] == 'C'
                            || privateBoard[row][column + j] == 'B'
                            || privateBoard[row][column + j] == 'S'
                            || privateBoard[row][column + j] == 'D')
                        { throw OverLap(); }

                        privateBoard[row][column + j] = 'R';
                    }
                }

                else if(Ships[i].getType() == "Submarine")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row][column + j] == 'C'
                            || privateBoard[row][column + j] == 'R'
                            || privateBoard[row][column + j] == 'B'
                            || privateBoard[row][column + j] == 'D')
                        { throw OverLap(); }

                        privateBoard[row][column + j] = 'S';
                    }
                }

                else if(Ships[i].getType() == "Destroyer")
                {
                    for (int j = 0; j < Ships[i].getSize(); j++)
                    {
                        if (privateBoard[row][column + j] == 'C'
                            || privateBoard[row][column + j] == 'R'
                            || privateBoard[row][column + j] == 'S'
                            || privateBoard[row][column + j] == 'B')
                        { throw OverLap(); }

                        privateBoard[row][column + j] = 'D';
                    }
                }
            }
        }

        catch(OverLap)
        {
            cout << "This ship is overlapped with another ship. Wrong input file." << endl;
            exit(0);
        }

        NumofShips++;
    }
}

void Grid::printPrivateGrid()
{
    cout << "   " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << "J" << endl;
    cout << "1  " << privateBoard[0][0] << " " << privateBoard[0][1] << " " << privateBoard[0][2] << " " << privateBoard[0][3] << " " << privateBoard[0][4] << " " << privateBoard[0][5] << " " << privateBoard[0][6] << " " << privateBoard[0][7] << " " << privateBoard[0][8] << " " << privateBoard[0][9] << endl;
    cout << "2  " << privateBoard[1][0] << " " << privateBoard[1][1] << " " << privateBoard[1][2] << " " << privateBoard[1][3] << " " << privateBoard[1][4] << " " << privateBoard[1][5] << " " << privateBoard[1][6] << " " << privateBoard[1][7] << " " << privateBoard[1][8] << " " << privateBoard[1][9] << endl;
    cout << "3  " << privateBoard[2][0] << " " << privateBoard[2][1] << " " << privateBoard[2][2] << " " << privateBoard[2][3] << " " << privateBoard[2][4] << " " << privateBoard[2][5] << " " << privateBoard[2][6] << " " << privateBoard[2][7] << " " << privateBoard[2][8] << " " << privateBoard[2][9] << endl;
    cout << "4  " << privateBoard[3][0] << " " << privateBoard[3][1] << " " << privateBoard[3][2] << " " << privateBoard[3][3] << " " << privateBoard[3][4] << " " << privateBoard[3][5] << " " << privateBoard[3][6] << " " << privateBoard[3][7] << " " << privateBoard[3][8] << " " << privateBoard[3][9] << endl;
    cout << "5  " << privateBoard[4][0] << " " << privateBoard[4][1] << " " << privateBoard[4][2] << " " << privateBoard[4][3] << " " << privateBoard[4][4] << " " << privateBoard[4][5] << " " << privateBoard[4][6] << " " << privateBoard[4][7] << " " << privateBoard[4][8] << " " << privateBoard[4][9] << endl;
    cout << "6  " << privateBoard[5][0] << " " << privateBoard[5][1] << " " << privateBoard[5][2] << " " << privateBoard[5][3] << " " << privateBoard[5][4] << " " << privateBoard[5][5] << " " << privateBoard[5][6] << " " << privateBoard[5][7] << " " << privateBoard[5][8] << " " << privateBoard[5][9] << endl;
    cout << "7  " << privateBoard[6][0] << " " << privateBoard[6][1] << " " << privateBoard[6][2] << " " << privateBoard[6][3] << " " << privateBoard[6][4] << " " << privateBoard[6][5] << " " << privateBoard[6][6] << " " << privateBoard[6][7] << " " << privateBoard[6][8] << " " << privateBoard[6][9] << endl;
    cout << "8  " << privateBoard[7][0] << " " << privateBoard[7][1] << " " << privateBoard[7][2] << " " << privateBoard[7][3] << " " << privateBoard[7][4] << " " << privateBoard[7][5] << " " << privateBoard[7][6] << " " << privateBoard[7][7] << " " << privateBoard[7][8] << " " << privateBoard[7][9] << endl;
    cout << "9  " << privateBoard[8][0] << " " << privateBoard[8][1] << " " << privateBoard[8][2] << " " << privateBoard[8][3] << " " << privateBoard[8][4] << " " << privateBoard[8][5] << " " << privateBoard[8][6] << " " << privateBoard[8][7] << " " << privateBoard[8][8] << " " << privateBoard[8][9] << endl;
    cout << "10 " << privateBoard[9][0] << " " << privateBoard[9][1] << " " << privateBoard[9][2] << " " << privateBoard[9][3] << " " << privateBoard[9][4] << " " << privateBoard[9][5] << " " << privateBoard[9][6] << " " << privateBoard[9][7] << " " << privateBoard[9][8] << " " << privateBoard[9][9] << endl;
}

void Grid::printShownGrid()
{
    cout << "   " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << "J" << endl;
    cout << "1  " << shownBoard[0][0] << " " << shownBoard[0][1] << " " << shownBoard[0][2] << " " << shownBoard[0][3] << " " << shownBoard[0][4] << " " << shownBoard[0][5] << " " << shownBoard[0][6] << " " << shownBoard[0][7] << " " << shownBoard[0][8] << " " << shownBoard[0][9] << endl;
    cout << "2  " << shownBoard[1][0] << " " << shownBoard[1][1] << " " << shownBoard[1][2] << " " << shownBoard[1][3] << " " << shownBoard[1][4] << " " << shownBoard[1][5] << " " << shownBoard[1][6] << " " << shownBoard[1][7] << " " << shownBoard[1][8] << " " << shownBoard[1][9] << endl;
    cout << "3  " << shownBoard[2][0] << " " << shownBoard[2][1] << " " << shownBoard[2][2] << " " << shownBoard[2][3] << " " << shownBoard[2][4] << " " << shownBoard[2][5] << " " << shownBoard[2][6] << " " << shownBoard[2][7] << " " << shownBoard[2][8] << " " << shownBoard[2][9] << endl;
    cout << "4  " << shownBoard[3][0] << " " << shownBoard[3][1] << " " << shownBoard[3][2] << " " << shownBoard[3][3] << " " << shownBoard[3][4] << " " << shownBoard[3][5] << " " << shownBoard[3][6] << " " << shownBoard[3][7] << " " << shownBoard[3][8] << " " << shownBoard[3][9] << endl;
    cout << "5  " << shownBoard[4][0] << " " << shownBoard[4][1] << " " << shownBoard[4][2] << " " << shownBoard[4][3] << " " << shownBoard[4][4] << " " << shownBoard[4][5] << " " << shownBoard[4][6] << " " << shownBoard[4][7] << " " << shownBoard[4][8] << " " << shownBoard[4][9] << endl;
    cout << "6  " << shownBoard[5][0] << " " << shownBoard[5][1] << " " << shownBoard[5][2] << " " << shownBoard[5][3] << " " << shownBoard[5][4] << " " << shownBoard[5][5] << " " << shownBoard[5][6] << " " << shownBoard[5][7] << " " << shownBoard[5][8] << " " << shownBoard[5][9] << endl;
    cout << "7  " << shownBoard[6][0] << " " << shownBoard[6][1] << " " << shownBoard[6][2] << " " << shownBoard[6][3] << " " << shownBoard[6][4] << " " << shownBoard[6][5] << " " << shownBoard[6][6] << " " << shownBoard[6][7] << " " << shownBoard[6][8] << " " << shownBoard[6][9] << endl;
    cout << "8  " << shownBoard[7][0] << " " << shownBoard[7][1] << " " << shownBoard[7][2] << " " << shownBoard[7][3] << " " << shownBoard[7][4] << " " << shownBoard[7][5] << " " << shownBoard[7][6] << " " << shownBoard[7][7] << " " << shownBoard[7][8] << " " << shownBoard[7][9] << endl;
    cout << "9  " << shownBoard[8][0] << " " << shownBoard[8][1] << " " << shownBoard[8][2] << " " << shownBoard[8][3] << " " << shownBoard[8][4] << " " << shownBoard[8][5] << " " << shownBoard[8][6] << " " << shownBoard[8][7] << " " << shownBoard[8][8] << " " << shownBoard[8][9] << endl;
    cout << "10 " << shownBoard[9][0] << " " << shownBoard[9][1] << " " << shownBoard[9][2] << " " << shownBoard[9][3] << " " << shownBoard[9][4] << " " << shownBoard[9][5] << " " << shownBoard[9][6] << " " << shownBoard[9][7] << " " << shownBoard[9][8] << " " << shownBoard[9][9] << endl;
}

void Grid::attackBoard(int row, int column)
{
    shownBoard[row][column] = 'X';
}

int Grid::getCell(int row, int column)
{
    return shownBoard[row][column];
}

void Grid::printBoth(Grid comp)
{
    cout << "Player's Grid:        " << "   " << "Computer's Grid: " << endl;
    cout << "   " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << "J" << "   " << "   " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << "J" << endl;
    cout << "1  " << shownBoard[0][0] << " " << shownBoard[0][1] << " " << shownBoard[0][2] << " " << shownBoard[0][3] << " " << shownBoard[0][4] << " " << shownBoard[0][5] << " " << shownBoard[0][6] << " " << shownBoard[0][7] << " " << shownBoard[0][8] << " " << shownBoard[0][9] << "   "
         << "1  " << comp.getShownBoard()[0][0] << " "  << comp.getShownBoard()[0][1] << " "  << comp.getShownBoard()[0][2] << " "  << comp.getShownBoard()[0][3] << " "  << comp.getShownBoard()[0][4] << " "  << comp.getShownBoard()[0][5] << " "  << comp.getShownBoard()[0][6] << " "  << comp.getShownBoard()[0][7] << " "  << comp.getShownBoard()[0][8] << " "  << comp.getShownBoard()[0][9] << endl;
    cout << "2  " << shownBoard[1][0] << " " << shownBoard[1][1] << " " << shownBoard[1][2] << " " << shownBoard[1][3] << " " << shownBoard[1][4] << " " << shownBoard[1][5] << " " << shownBoard[1][6] << " " << shownBoard[1][7] << " " << shownBoard[1][8] << " " << shownBoard[1][9] << "   "
         << "2  " << comp.getShownBoard()[1][0] << " "  << comp.getShownBoard()[1][1] << " "  << comp.getShownBoard()[1][2] << " "  << comp.getShownBoard()[1][3] << " "  << comp.getShownBoard()[1][4] << " "  << comp.getShownBoard()[1][5] << " "  << comp.getShownBoard()[1][6] << " "  << comp.getShownBoard()[1][7] << " "  << comp.getShownBoard()[1][8] << " "  << comp.getShownBoard()[1][9] << endl;
    cout << "3  " << shownBoard[2][0] << " " << shownBoard[2][1] << " " << shownBoard[2][2] << " " << shownBoard[2][3] << " " << shownBoard[2][4] << " " << shownBoard[2][5] << " " << shownBoard[2][6] << " " << shownBoard[2][7] << " " << shownBoard[2][8] << " " << shownBoard[2][9] << "   "
         << "3  " << comp.getShownBoard()[2][0] << " "  << comp.getShownBoard()[2][1] << " "  << comp.getShownBoard()[2][2] << " "  << comp.getShownBoard()[2][3] << " "  << comp.getShownBoard()[2][4] << " "  << comp.getShownBoard()[2][5] << " "  << comp.getShownBoard()[2][6] << " "  << comp.getShownBoard()[2][7] << " "  << comp.getShownBoard()[2][8] << " "  << comp.getShownBoard()[2][9] << endl;
    cout << "4  " << shownBoard[3][0] << " " << shownBoard[3][1] << " " << shownBoard[3][2] << " " << shownBoard[3][3] << " " << shownBoard[3][4] << " " << shownBoard[3][5] << " " << shownBoard[3][6] << " " << shownBoard[3][7] << " " << shownBoard[3][8] << " " << shownBoard[3][9] << "   "
         << "4  " << comp.getShownBoard()[3][0] << " "  << comp.getShownBoard()[3][1] << " "  << comp.getShownBoard()[3][2] << " "  << comp.getShownBoard()[3][3] << " "  << comp.getShownBoard()[3][4] << " "  << comp.getShownBoard()[3][5] << " "  << comp.getShownBoard()[3][6] << " "  << comp.getShownBoard()[3][7] << " "  << comp.getShownBoard()[3][8] << " "  << comp.getShownBoard()[3][9] << endl;
    cout << "5  " << shownBoard[4][0] << " " << shownBoard[4][1] << " " << shownBoard[4][2] << " " << shownBoard[4][3] << " " << shownBoard[4][4] << " " << shownBoard[4][5] << " " << shownBoard[4][6] << " " << shownBoard[4][7] << " " << shownBoard[4][8] << " " << shownBoard[4][9] << "   "
         << "5  " << comp.getShownBoard()[4][0] << " "  << comp.getShownBoard()[4][1] << " "  << comp.getShownBoard()[4][2] << " "  << comp.getShownBoard()[4][3] << " "  << comp.getShownBoard()[4][4] << " "  << comp.getShownBoard()[4][5] << " "  << comp.getShownBoard()[4][6] << " "  << comp.getShownBoard()[4][7] << " "  << comp.getShownBoard()[4][8] << " "  << comp.getShownBoard()[4][9] << endl;
    cout << "6  " << shownBoard[5][0] << " " << shownBoard[5][1] << " " << shownBoard[5][2] << " " << shownBoard[5][3] << " " << shownBoard[5][4] << " " << shownBoard[5][5] << " " << shownBoard[5][6] << " " << shownBoard[5][7] << " " << shownBoard[5][8] << " " << shownBoard[5][9] << "   "
         << "6  " << comp.getShownBoard()[5][0] << " "  << comp.getShownBoard()[5][1] << " "  << comp.getShownBoard()[5][2] << " "  << comp.getShownBoard()[5][3] << " "  << comp.getShownBoard()[5][4] << " "  << comp.getShownBoard()[5][5] << " "  << comp.getShownBoard()[5][6] << " "  << comp.getShownBoard()[5][7] << " "  << comp.getShownBoard()[5][8] << " "  << comp.getShownBoard()[5][9] << endl;
    cout << "7  " << shownBoard[6][0] << " " << shownBoard[6][1] << " " << shownBoard[6][2] << " " << shownBoard[6][3] << " " << shownBoard[6][4] << " " << shownBoard[6][5] << " " << shownBoard[6][6] << " " << shownBoard[6][7] << " " << shownBoard[6][8] << " " << shownBoard[6][9] << "   "
         << "7  " << comp.getShownBoard()[6][0] << " "  << comp.getShownBoard()[6][1] << " "  << comp.getShownBoard()[6][2] << " "  << comp.getShownBoard()[6][3] << " "  << comp.getShownBoard()[6][4] << " "  << comp.getShownBoard()[6][5] << " "  << comp.getShownBoard()[6][6] << " "  << comp.getShownBoard()[6][7] << " "  << comp.getShownBoard()[6][8] << " "  << comp.getShownBoard()[6][9] << endl;
    cout << "8  " << shownBoard[7][0] << " " << shownBoard[7][1] << " " << shownBoard[7][2] << " " << shownBoard[7][3] << " " << shownBoard[7][4] << " " << shownBoard[7][5] << " " << shownBoard[7][6] << " " << shownBoard[7][7] << " " << shownBoard[7][8] << " " << shownBoard[7][9] << "   "
         << "8  " << comp.getShownBoard()[7][0] << " "  << comp.getShownBoard()[7][1] << " "  << comp.getShownBoard()[7][2] << " "  << comp.getShownBoard()[7][3] << " "  << comp.getShownBoard()[7][4] << " "  << comp.getShownBoard()[7][5] << " "  << comp.getShownBoard()[7][6] << " "  << comp.getShownBoard()[7][7] << " "  << comp.getShownBoard()[7][8] << " "  << comp.getShownBoard()[7][9] << endl;
    cout << "9  " << shownBoard[8][0] << " " << shownBoard[8][1] << " " << shownBoard[8][2] << " " << shownBoard[8][3] << " " << shownBoard[8][4] << " " << shownBoard[8][5] << " " << shownBoard[8][6] << " " << shownBoard[8][7] << " " << shownBoard[8][8] << " " << shownBoard[8][9] << "   "
         << "9  " << comp.getShownBoard()[8][0] << " "  << comp.getShownBoard()[8][1] << " "  << comp.getShownBoard()[8][2] << " "  << comp.getShownBoard()[8][3] << " "  << comp.getShownBoard()[8][4] << " "  << comp.getShownBoard()[8][5] << " "  << comp.getShownBoard()[8][6] << " "  << comp.getShownBoard()[8][7] << " "  << comp.getShownBoard()[8][8] << " "  << comp.getShownBoard()[8][9] << endl;
    cout << "10 " << shownBoard[9][0] << " " << shownBoard[9][1] << " " << shownBoard[9][2] << " " << shownBoard[9][3] << " " << shownBoard[9][4] << " " << shownBoard[9][5] << " " << shownBoard[9][6] << " " << shownBoard[9][7] << " " << shownBoard[9][8] << " " << shownBoard[9][9] << "   "
         << "10 " << comp.getShownBoard()[9][0] << " "  << comp.getShownBoard()[9][1] << " "  << comp.getShownBoard()[9][2] << " "  << comp.getShownBoard()[9][3] << " "  << comp.getShownBoard()[9][4] << " "  << comp.getShownBoard()[9][5] << " "  << comp.getShownBoard()[9][6] << " "  << comp.getShownBoard()[9][7] << " "  << comp.getShownBoard()[9][8] << " "  << comp.getShownBoard()[9][9] << endl << endl;
}