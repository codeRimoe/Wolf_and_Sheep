//
//  Sheep.h
//  wolf_and_sheep

//  Author: Yue H.W. Luo 
//  Mail: yue.rimoe@gmail.com 
//  License : http://www.apache.org/licenses/LICENSE-2.0 
//  More detial: http://blog.rimoe.ml/2017/06/09/post01/ 

//  Created by _nEgATron on 17/06/05.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#include "Animal.h"

#ifndef SHEEP_H
#define SHEEP_H

class Animal;

class Sheep:public Animal{
public:
    Sheep(int inX=10,int inY=10,int inLife=SHEEP_LIFE,int inHunger=SHEEP_STARVE){
        this->life=inLife;
        this->hunger=inHunger,x=inX,y=inY;
    }
    ~Sheep(){
    }
    
    int search(Grid *pG){
        int temp0=pG->findLocal(this->x, this->y),t=1,weight=1,dir=4;
        int temp[9]={0};
        for(int i=0;i<9;i++){
            temp[i]=temp0/t%10;
            t*=10;
        }
        for(int i=0;i<9;i++){
            int tWeight=1+rand()%3;
            if(temp[i]==0){
                tWeight+=pG->getGrd(this->x+i/3-1, this->x+i%3-1)->getGrass();
                tWeight+=10*(8*pG->cont(this->x+i/3-1, this->x+i%3-1,1));
                if(temp[8-1]==1)
                    tWeight+=100;
            }
            else
                tWeight=0;
            if(tWeight>weight){
                weight=tWeight;
                dir=i;
            }
        }
        return dir;
    }
    
    bool birth(){
        return !((SHEEP_LIFE+1-this->life)%SHEEP_BIRTH);
    }
    
    Animal& eat(int inX,int inY,Grid* inG){
        Ground *pG=inG->getGrd(inX,inY);
        if(pG->getType()==0){
            if(pG->getGrass()>=3){
                this->hunger=SHEEP_STARVE;
                pG->setGrass(-3);
            }
        }
        return *this;
    }
    
    int getType(){
        return 2;
    }
    
};

#endif /* Sheep_h */
