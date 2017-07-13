//
//  Grid.h
//  wolf_and_sheep
//
//  Created by _nEgATron on 17/06/05.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#ifndef GRID_H
#define GRID_H

#include<iostream>
using std::cout;using std::endl;

#include <ctime>
#include <cstdlib>
class Wolf;
class Sheep;
class Ground;

class Grid{
    
public:
    Grid(int=10,int=5,int=20);
    ~Grid();
    
    Ground* getGrd(int,int);

    int findLocal(int,int);
    int cont(int,int,int);
    Grid& addN(int,int);

    Grid& add(int,int,int);
    Grid& remove(int,int);
    Grid& display();
    Grid& refresh();

    int nWolf,nSheep,nDay;

protected:
    int randInt(int,int);
    Grid& init(int inWolf,int inSheep);

private:
    int nLong;
    Ground** pG;
    
};

#endif /* Grid_h */
