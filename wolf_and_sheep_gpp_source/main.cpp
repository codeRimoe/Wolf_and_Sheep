//
//  main.cpp
//  wolf_and_sheep
//
//  Created by _nEgATron on 17/06/04.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#include <iostream>

#include "Grid.h"
#include "Ground.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
using std::cout;using std::endl;using std::cin;
int main() {
    int nWolf,nSheep,nGrid;
    system("clear");
    cout << "Welcome to the grassland!"<<endl
         << "This programme is in order to simulate the state of animal number on grassland."<<endl
         << "========================="<<endl
         << "Please input the length of the grassland side:";
    cin >> nGrid;
    cout << "Please input the number of wolf:";
    cin >> nWolf;
    cout << "Please input the number of sheep:";
    cin >> nSheep;
    
    Grid ggg(nGrid,nWolf,nSheep);
    
    cout << "Everything is set-up-ed."<<endl<<"Press <Enter> to Start"<<endl;
    
    while(1){
        ggg.refresh();
        ggg.display();
    }
    
    return 0;
}
