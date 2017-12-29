//
//  Ground.h
//  wolf_and_sheep

//  Author: Yue H.W. Luo 
//  Mail: yue.rimoe@gmail.com 
//  License : http://www.apache.org/licenses/LICENSE-2.0 
//  More detial: http://blog.rimoe.ml/2017/06/09/post01/ 

//  Ground is a units of Grids,
//  it record the animal memory-location on this unit, and the number of grass in the unit
//
//  Created by _nEgATron on 17/06/04.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#ifndef GROUND_H
#define GROUND_H

#define MAX_GRASS 7

#include <iostream>

class Animal;

class Ground{
    
public:
    Ground();
    ~Ground();
    
    Ground& setAni(Animal*);
    Ground& setType(int);
    Ground& setGrass(int);
    Animal* getAni();
    int getType();
    int getGrass();
    
    int grow();
    int find0();

private:
    Animal *ani;
    int aniType;
    int grass;
    
};


#endif /* Ground_h */
