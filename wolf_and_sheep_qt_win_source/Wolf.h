//
//  Wolf.h
//  wolf_and_sheep
//
//  Created by _nEgATron on 17/06/04.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"
class Animal;
class Wolf:public Animal{
    
public:
    Wolf(int inX=10,int inY=10,int inLife=WOLF_LIFE,int inHunger=WOLF_STARVE){
        this->life=inLife;
        this->hunger=inHunger,x=inX,y=inY;
    }
    ~Wolf(){
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
            if(temp[i]==2){
                tWeight+=100;
                tWeight+=10*pG->cont(this->x+(i/3)-1, this->x+i%3-1,2);
            }
            else if(temp[i]==0)
                tWeight+=10*pG->cont(this->x+(i/3)-1, this->x+i%3-1,2);
            else if((temp[i]==1)||(temp[i]==3))
                tWeight=0;
            if(tWeight>weight){
                weight=tWeight;
                dir=i;
            }
        }
        return dir;
    }
    
    int search0(Grid* inG){
        int D=0,DX=rand()%10;
        int X=this->x+D/3-1,Y=this->y+D/3-1;
        while(inG->getGrd(X, Y)->getType()){
            D++;
            if(D>=10)break;
            X=this->x+D/3-1,Y=this->y+D/3-1;
        }
        if(D>=10)D=search(inG);
        if(D==4)D=DX;
        return D;
    }
    
    int getType(){
        return 1;
    }
    
    bool birth(){
        return !((WOLF_LIFE+1-this->life)%WOLF_BIRTH);
    }
    
    Animal& eat(int inX,int inY,Grid* inG){
        Animal *pAni=inG->getGrd(inX,inY)->getAni();
        if(pAni){
            if(pAni->getType()==2){
                this->hunger=WOLF_STARVE;
                pAni->die(inG);
            }
        }
        return *this;
    }
};

#endif /* Wolf_h */
