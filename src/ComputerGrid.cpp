//
// Created by sungj on 10/24/2019.
//

#include "ComputerGrid.h"

void ComputerGrid::setRandomShips()
{
    Ships.clear();

    bool place2 = true;
    bool place3 = true;
    bool place4 = true;
    bool place5 = true;

    Ship Tempship1;
    Ship Tempship2;
    Ship Tempship3;
    Ship Tempship4;
    Ship Tempship5;

    Tempship1.setType("Carrier");
    Tempship1.setSize("Carrier");

    if (rand() % 2 == 0)
    {
        Tempship1.setDirection("V");
        int row = rand() % 6;
        int column = rand() % 6;
        Tempship1.setEndPts(row, column, "V");

        for (int j = 0; j < 5; j++)
        {
            privateBoard[row + j][column] = 'C';
        }
    }

    else
    {
        Tempship1.setDirection("H");

        int row = rand() % 6;
        int column = rand() % 6;
        Tempship1.setEndPts(row, column, "H");

        for (int j = 0; j < 5; j++)
        {
            privateBoard[row][column + j] = 'C';
        }
    }

    Ships.push_back(Tempship1);


    Tempship2.setType("Battleship");
    Tempship2.setSize("Battleship");

    while(place2)
    {
        int counter2 = 0;

        if (rand() % 2 == 0)
        {
            Tempship2.setDirection("V");
            int row = rand() % 7;
            int column = rand() % 7;
            Tempship2.setEndPts(row, column, "V");

            for (int j = 0; j < 4; j++)
            {
                if (privateBoard[row + j][column] == 'C')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row + index][column] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row + j][column] = 'B';
                counter2++;
            }

            if(counter2 == 4)
            {
                place2 = false;
            }
        }
        else
        {
            Tempship2.setDirection("H");
            int row = rand() % 7;
            int column = rand() % 7;
            Tempship2.setEndPts(row, column, "H");

            for (int j = 0; j < 4; j++)
            {
                if (privateBoard[row][column + j] == 'C')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row][column + index] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row][column + j] = 'B';
                counter2++;
            }

            if(counter2 == 4)
            {
                place2 = false;
            }
        }
    }

    Ships.push_back(Tempship2);


    Tempship3.setType("Cruiser");
    Tempship3.setSize("Cruiser");

    while(place3)
    {
        int counter3 = 0;

        if (rand() % 2 == 0)
        {
            Tempship3.setDirection("V");
            int row = rand() % 8;
            int column = rand() % 8;
            Tempship3.setEndPts(row, column, "V");

            for (int j = 0; j < 3; j++)
            {
                if (privateBoard[row + j][column] == 'C' || privateBoard[row + j][column] == 'B')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row + index][column] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row + j][column] = 'R';
                counter3++;
            }

            if(counter3 == 3)
            {
                place3 = false;
            }
        }
        else
        {
            Tempship3.setDirection("H");
            int row = rand() % 8;
            int column = rand() % 8;
            Tempship3.setEndPts(row, column, "H");

            for (int j = 0; j < 3; j++)
            {
                if (privateBoard[row][column + j] == 'C' || privateBoard[row][column + j] == 'B')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row][column + index] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row][column + j] = 'R';
                counter3++;
            }

            if(counter3 == 3)
            {
                place3 = false;
            }
        }
    }

    Ships.push_back(Tempship3);


    Tempship4.setType("Submarine");
    Tempship4.setSize("Submarine");

    while(place4)
    {
        int counter4 = 0;

        if (rand() % 2 == 0)
        {
            Tempship4.setDirection("V");
            int row = rand() % 8;
            int column = rand() % 8;
            Tempship4.setEndPts(row, column, "V");

            for (int j = 0; j < 3; j++)
            {
                if (privateBoard[row + j][column] == 'C' || privateBoard[row + j][column] == 'B' || privateBoard[row + j][column] == 'R')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row + index][column] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row + j][column] = 'S';
                counter4++;
            }

            if(counter4 == 3)
            {
                place4 = false;
            }
        }

        else
        {
            Tempship4.setDirection("H");
            int row = rand() % 8;
            int column = rand() % 8;
            Tempship4.setEndPts(row, column, "H");

            for (int j = 0; j < 3; j++)
            {
                if (privateBoard[row][column + j] == 'C' || privateBoard[row][column + j] == 'B' || privateBoard[row][column + j] == 'R')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row][column + index] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row][column + j] = 'S';
                counter4++;
            }

            if(counter4 == 3)
            {
                place4 = false;
            }
        }
    }

    Ships.push_back(Tempship4);


    Tempship5.setType("Destroyer");
    Tempship5.setSize("Destroyer");

    while(place5)
    {
        int counter5 = 0;

        if (rand() % 2 == 0)
        {
            Tempship5.setDirection("V");
            int row = rand() % 9;
            int column = rand() % 9;
            Tempship5.setEndPts(row, column, "V");

            for (int j = 0; j < 2; j++)
            {
                if (privateBoard[row + j][column] == 'C' || privateBoard[row + j][column] == 'B' || privateBoard[row + j][column] == 'R' || privateBoard[row + j][column] == 'S')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row + index][column] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row + j][column] = 'D';
                counter5++;
            }

            if(counter5 == 2)
            {
                place5 = false;
            }
        }

        else
        {
            Tempship5.setDirection("H");
            int row = rand() % 9;
            int column = rand() % 9;
            Tempship5.setEndPts(row, column, "H");

            for (int j = 0; j < 2; j++)
            {
                if (privateBoard[row][column + j] == 'C' || privateBoard[row + j][column] == 'B' || privateBoard[row + j][column] == 'R' || privateBoard[row + j][column] == 'S')
                {
                    int index = j-1;

                    while(index >= 0)
                    {
                        privateBoard[row][column + index] = ' ';
                        index--;
                    }
                    break;
                }

                privateBoard[row][column + j] = 'D';
                counter5++;
            }

            if(counter5 == 2)
            {
                place5 = false;
            }
        }
    }

    Ships.push_back(Tempship5);

    NumofShips = 5;
}



