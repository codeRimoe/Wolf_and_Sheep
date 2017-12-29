//
//  Animal.h
//  wolf_and_sheep

//  Author: Yue H.W. Luo 
//  Mail: yue.rimoe@gmail.com 
//  License : http://www.apache.org/licenses/LICENSE-2.0 
//  More detial: http://blog.rimoe.ml/2017/06/09/post01/ 

//  this header define a class animal
//  which is the base class of wolf and sheep.
//
//  Created by _nEgATron on 17/06/04.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#ifndef ANIMAL_H
#define ANIMAL_H

// here define some const
// BIRTH  : the loop time for creating a new baby animal object
// LIFE   : animal will die after the time
// STARVE : animal will die after the time if it didn't eat

#define WOLF_BIRTH 8
#define WOLF_LIFE 40
#define WOLF_STARVE 3
#define SHEEP_BIRTH 3
#define SHEEP_LIFE 30
#define SHEEP_STARVE 3

class Grid;
class Ground;

class Animal{
    
public:
    Animal(int=10,int=10,int=10,int=10);
    virtual ~Animal();
    
    //get parameters
    int getLife();
    int getHunger();
    int getX();
    int getY();
    
    //set parameters
    Animal& setLife(int);
    Animal& setHunger(int);
    Animal& setX(int);
    Animal& setY(int);

    virtual bool birth()=0;                //return true when it is able to bear a baby
    virtual int getType()=0;               //return 1:wolf 2:sheep
    virtual int search(Grid*)=0;           //search for the best way to move
    virtual Animal& eat(int,int,Grid*)=0;  //eat sheep or grass
    
    int moved;                             //movable:1 moved:0
    
    int search0(Grid*);                    //return the value of 3*3 local area
    Animal& move(int,int,Grid*);           //move to (x,y)
    Animal& moveDir(int,Grid*);            //move one step(0:(x-1,y-1) 1:(x,y-1) etc.)
    Animal& birth(int,Grid*);              //bear a baby animal
    int die(Grid*);                        //delete the animal object
    Animal& grow(Grid*);                   //grow when after one step
    
protected:
    int life,hunger,x,y;
    
};

#endif /* Animal_h */

