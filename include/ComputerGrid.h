//
// Created by sungj on 10/24/2019.
//

#ifndef OOP_FINAL_COMPUTERGRID_H
#define OOP_FINAL_COMPUTERGRID_H

#include "Grid.h"

class ComputerGrid : public Grid
{
public:
    ComputerGrid():Grid(){}
    void setRandomShips();
};


#endif //OOP_FINAL_COMPUTERGRID_H
