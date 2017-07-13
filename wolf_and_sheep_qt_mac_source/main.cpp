//
//  main.cpp
//  wolf_and_sheep
//
//  Created by _nEgATron on 17/06/04.
//  Copyright © 2017年 _nEgATron. All rights reserved.
//

#include <iostream>
#include <QApplication>
#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Grid.h"
#include "Ground.h"
#include "Animal.h"
#include "Wolf.h"
using std::cout;using std::endl;using std::cin;
int main(int argc,char*argv[]) {
    QApplication app(argc,argv);
    MainWindow win;
    win.show();
    return app.exec();
}
