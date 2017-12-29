//
//  Ground.cpp
//  wolf_and_sheep

//  Author: Yue H.W. Luo 
//  Mail: yue.rimoe@gmail.com 
//  License : http://www.apache.org/licenses/LICENSE-2.0 
//  More detial: http://blog.rimoe.ml/2017/06/09/post01/ 

//  Created by _nEgATron on 17/06/05.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#include "Ground.h"
#include "Animal.h"
#include <iostream>


Ground::Ground(){
    this->ani=NULL;
    this->grass=MAX_GRASS;
    this->aniType=0;
};
Ground::~Ground(){
    Animal *_temp=this->getAni();
    if(_temp){
        delete _temp;
        setAni(NULL);
        setType(0);
    }
};


Ground& Ground::setAni(Animal* inAni){
    this->ani=inAni;
    return *this;
}
Ground& Ground::setType(int inType){
    this->aniType=inType;
    return *this;
}
Ground& Ground::setGrass(int inGrass){
    this->grass+=inGrass;
    if(this->grass<0) this->grass=0;
    else if(this->grass>MAX_GRASS) this->grass=MAX_GRASS;
    return *this;
}


Animal* Ground::getAni(){
    return ani;
}
int Ground::getType(){
    return aniType;
}
int Ground::getGrass(){
    return grass;
}


int Ground::grow(){
    if(grass<MAX_GRASS)
        this->grass++;
    else this->grass=MAX_GRASS;
    return this->grass;
}

int Ground::find0(){
    int s=0,t=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<=3;j++){
            s+=this->aniType*t;
            t*=10;
        }
    }
    return s;
}
