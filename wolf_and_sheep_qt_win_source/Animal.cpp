//
//  Animal.cpp
//  wolf_and_sheep
//
//  this header define a class animal
//  which is the base class of wolf and sheep.
//
//  Created by _nEgATron on 17/06/05.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#include <iostream>

#include "Animal.h"
#include "Ground.h"
#include "Grid.h"

Animal::Animal(int inLife,int inHunger,int inX,int inY){
    life=inLife,hunger=inHunger,x=inX,y=inY;
}
Animal::~Animal(){
}
int Animal::getLife(){
    return this->life;
}
int Animal::getHunger(){
    return this->hunger;
}
int Animal::getX(){
    return this->x;
}
int Animal::getY(){
    return this->y;
}


Animal& Animal::setLife(int inLife){
    this->life=inLife;
    return *this;
}
Animal& Animal::setHunger(int inHunger){
    this->hunger=inHunger;
    return *this;
}
Animal& Animal::setX(int inX){
    this->x=inX;
    return *this;
}
Animal& Animal::setY(int inY){
    this->y=inY;
    return *this;
}

int Animal::search0(Grid *inG){
    return search(inG);
}

Animal& Animal::move(int inX,int inY,Grid* inG){
    Ground *pG=inG->getGrd(this->x,this->y);
    pG->setAni(NULL);
    pG->setType(0);
    this->x=inX;
    this->y=inY;
    pG=inG->getGrd(this->x,this->y);
    pG->setAni(this);
    pG->setType(this->getType());
    moved=1;
    return *this;
}

Animal& Animal::moveDir(int D,Grid*pG){
        int X=this->x+D/3-1,Y=this->y+D%3-1;
        if(pG->getGrd(X,Y)->getType()!=1)
            this->eat(X,Y,pG);
        this->move(X,Y,pG);
    return *this;
}

Animal& Animal::birth(int D,Grid *inG){
    if(D==4)
        return *this;
    int X=this->x+D/3-1,Y=this->y+D%3-1;
    Ground *pG=inG->getGrd(X,Y);
    if((pG->getType()==3)||(pG->getType()==1))
        return *this;
    else if(pG->getType()==2)
        pG->getAni()->die(inG);
    inG->add(X, Y, this->getType());
    return *this;
}


int Animal::die(Grid *inG){
    inG->remove(this->x, this->y);
    return 0;
}

Animal& Animal::grow(Grid* inG){
    moved=0;
    hunger--;
    life--;
    if((life<=0)||(hunger<=0))this->die(inG);
    return *this;
}
