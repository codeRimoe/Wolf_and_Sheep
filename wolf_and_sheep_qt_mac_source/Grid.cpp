//
//  Grid.cpp
//  wolf_and_sheep
//
//  Created by _nEgATron on 17/06/05.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//


#include "Grid.h"
#include "Ground.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include <unistd.h>

Grid::Grid(int inLong,int inWolf,int inSheep):nWolf(inWolf),nSheep(inSheep),nLong(inLong){
    pG=new Ground*[inLong+2];
    for(int i=0;i<inLong+2;i++)
        pG[i]=new Ground[inLong+2];
    for(int i=0;i<inLong+2;i++){
        pG[0][i].setType(3);
        pG[i][0].setType(3);
        pG[inLong+1][i].setType(3);
        pG[i][inLong+1].setType(3);
    }
    init(nWolf,nSheep);
}
Grid::~Grid(){
    for(int i=0;i<nLong+2;i++){
        delete[] pG[i];
    }
    delete[] pG;
}

Ground* Grid::getGrd(int X,int Y){
    return &this->pG[X][Y];
}

int Grid::findLocal(int X,int Y){
    int result=0,t=1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            result+=t*this->getGrd(X+i,Y+j)->getType();
            t*=10;
        }
    }
    return result;
}

int Grid::cont(int X,int Y,int type){
    int temp=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(this->getGrd(X+i,Y+j)->getType()==type)
                temp++;
        }
    }
    return temp;
}

Grid& Grid::addN(int type, int addNum){
    switch (type) {
        case 1:nWolf+=addNum;break;
        case 2:nSheep+=addNum;break;
        default:break;
    }
    return *this;
}

Grid& Grid::add(int X,int Y,int Type){
    switch (Type) {
        case 1:pG[X][Y].setAni(new Wolf(X,Y));nWolf++;break;
        case 2:pG[X][Y].setAni(new Sheep(X,Y));nSheep++;break;
        default:break;
    }
    pG[X][Y].setType(Type);
    return *this;
}

Grid& Grid::remove(int X,int Y){
    if(pG[X][Y].getAni()){
        addN(pG[X][Y].getAni()->getType(), -1);
        delete pG[X][Y].getAni();
    }
    pG[X][Y].setAni(NULL);
    pG[X][Y].setType(0);
    return *this;
}

Grid& Grid::display(){
    system("clear");
    for(int i=0;i<nLong+2;i++){
        for(int j=0;j<nLong+2;j++)
            cout<<pG[i][j].getType()<<' ';
        cout<<endl;
    }
    cout<<"Time :"<<nDay<<endl
        <<"Wolf :"<<this->nWolf<<"\t\t"<<nWolf*100.0/(nWolf+nSheep)<<"%,"<<nWolf*100.0/(nLong*nLong)<<"%"<<endl
        <<"Sheep:"<<this->nSheep<<"\t\t"<<nSheep*100.0/(nWolf+nSheep)<<"%,"<<nSheep*100.0/(nLong*nLong)<<"%"<<endl
        <<"0-GrassLand 1-Wolf 2-Sheep 3-Unarrivable"<<endl
        <<"Press <Ctrl-C> to Exit."<<endl<<"Created by H.W. Luo,"<<endl<<"All rights reserved."<<endl;
    usleep(500000);
    return *this;
}

Grid& Grid::refresh(){
    for(int i=1;i<=nLong;i++)
        for(int j=1;j<=nLong;j++){
            Animal* pAni=pG[i][j].getAni();
            if(pAni)
                pAni->moved=1;
        }
    for(int i=1;i<=nLong;i++)
        for(int j=1;j<=nLong;j++){
            Animal* pAni=pG[i][j].getAni();
            pG[i][j].grow();
            if(pAni)
                if(pAni->moved){
                    pAni->moveDir(pAni->search(this),this);
                    if(pAni&&pAni->birth()){
                        pAni->birth(pAni->search0(this),this);
                    }
                    pAni->grow(this);
//                    this->display();
                }
        }
    nDay++;
    return *this;
}


int Grid::randInt(int x,int y){
    int r;
    r = (rand() % (y-x+1)) + 1;
    return r;
}

Grid& Grid::init(int inWolf,int inSheep){
    srand((unsigned int)time(0));
    this->nWolf=0,this->nSheep=0,this->nDay=0;
    for(int i=0;i<inWolf;i++){
        int x=randInt(1, nLong),y=randInt(1, nLong);
        while(pG[x][y].getType())
            x=randInt(1, nLong),y=randInt(1, nLong);
        add(x,y,1);
    }
    for(int i=0;i<inSheep;i++){
        int x=randInt(1, nLong),y=randInt(1, nLong);
        while(pG[x][y].getType())
            x=randInt(1, nLong),y=randInt(1, nLong);
        add(x,y,2);
    }
    return *this;
}
