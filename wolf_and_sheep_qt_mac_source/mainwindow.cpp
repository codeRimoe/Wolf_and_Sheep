//  QT UI
//  Author: Yue H.W. Luo 
//  Mail: yue.rimoe@gmail.com 
//  License : http://www.apache.org/licenses/LICENSE-2.0 
//  More detial: http://blog.rimoe.ml/2017/06/09/post01/ 

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Grid.h"
#include "Ground.h"
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <qtimer.h>
#include <time.h>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nWolf=30,nSheep=300,nLong=30;
    img[0]=new QImage(":/jpg/resource/green4.png");
    img[1]=new QImage(":/jpg/resource/green3.png");
    img[2]=new QImage(":/jpg/resource/green2.png");
    img[3]=new QImage(":/jpg/resource/green.png");
    img[4]=new QImage(":/jpg/resource/wolf.jpg");
    img[5]=new QImage(":/jpg/resource/sheep.jpg");
    QIcon *icon = new QIcon(":/jpg/favicon.ico");
    timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(loop()));//关联定时器计满信号和相应的槽函数
    timer->setInterval(500);
    ui->mainToolBar->setFixedHeight(0);
    connect(ui->actionStart,SIGNAL(triggered(bool)),this,SLOT(start()));
    connect(ui->actionStop,SIGNAL(triggered(bool)),this,SLOT(stop()));
    connect(ui->actionPause,SIGNAL(triggered(bool)),this,SLOT(pause()));
    connect(ui->actionAbout_Me,SIGNAL(triggered(bool)),this,SLOT(intro()));
    connect(ui->actionAbout_App,SIGNAL(triggered(bool)),this,SLOT(aboutme()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(setting()));
    currentTimeLabel = new QLabel;
    Label_St = new QLabel;
    mtimer = new QTimer(this);
    mtimer->start(1000); // 每次发射timeout信号时间间隔为1秒
    connect(mtimer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
    msgBox = new QMessageBox("", "", QMessageBox::Information, QMessageBox::Ok | QMessageBox::Default, 0, 0);
    msgBox->setWindowIcon(*icon);
}

int MainWindow::displayQt(){
    for(int i=1;i<=nLong;i++){
        for(int j=1;j<=nLong;j++){
            int _temp=pGrid->getGrd(i,j)->getType();
            if(_temp==0)
                pScreen[i-1][j-1]->setPixmap(QPixmap::fromImage((*img[pGrid->getGrd(i,j)->getGrass()/2])));
            else
                pScreen[i-1][j-1]->setPixmap(QPixmap::fromImage((*img[_temp+3])));
        }
    }
    QString ShowLb="Wolf:"+QString::number(pGrid->nWolf,10)
                  +"["+QString::number(pGrid->nWolf*100.0/(pGrid->nWolf+pGrid->nSheep))+"%,"
                  +QString::number(pGrid->nWolf*100.0/(nLong*nLong))+"%]"
                  +"   Sheep:"+QString::number(pGrid->nSheep,10)
                  +"["+QString::number(pGrid->nSheep*100.0/(pGrid->nWolf+pGrid->nSheep))+"%,"
                  +QString::number(pGrid->nSheep*100.0/(nLong*nLong))+"%]"
                  +"\nTime:"+QString::number(pGrid->nDay,10)
                  +"   Created by H.W. Luo,All rights reserved.";
    Label_St->setText(ShowLb);
    ui->statusBar->addWidget(Label_St);
    return 0;
}

void MainWindow::timeUpdate(){
    QDateTime CurrentTime = QDateTime::currentDateTime();
    QString Timestr = CurrentTime.toString("  yyyy-MM-dd \n  hh:mm:ss  "); // 设置显示的格式
    currentTimeLabel->setText(Timestr);
    ui->statusBar->addWidget(currentTimeLabel);

    QString ShowLb="\n   Created by H.W. Luo,All rights reserved.";
    Label_St->setText(ShowLb);
    ui->statusBar->addWidget(Label_St);
}

void MainWindow::loop(){
    this->pGrid->refresh();
    this->displayQt();
}

void MainWindow::setSize(int X,int Y){
    this->setFixedSize(X,Y);
    this->setMaximumSize(X,Y);
    this->setMinimumSize(X,Y);
    ui->mainToolBar->setFixedHeight(0);
}

void MainWindow::start(){
    pGrid=new Grid(nLong,nWolf,nSheep);
    QLabel ***head=new QLabel**[nLong];
    for(int i=0;i<nLong;i++){
        head[i]=new QLabel*[nLong];
        for(int j=0;j<nLong;j++){
            head[i][j]=new QLabel(this);
            head[i][j]->setGeometry(10+i*25,10+j*25,25,25);
            head[i][j]->setPixmap(QPixmap::fromImage((*img[0])));
            head[i][j]->show();
        }
    }
    pScreen=head;
    this->setSize(25*nLong+20,25*nLong+60);
    mtimer->stop();
    timer->start();
    ui->cover->setFixedSize(25*nLong+20,25*nLong+60);
    ui->actionStart->setEnabled(false);
    ui->actionStop->setEnabled(true);
    ui->actionPause->setEnabled(true);
}

void MainWindow::stop(){
    timer->stop();
    mtimer->start();
    if(pGrid)delete pGrid;
    pGrid=NULL;
    for(int i=0;i<nLong;i++){
        for(int j=0;j<nLong;j++){
            delete pScreen[i][j];
        }
        if(pScreen[i])delete []pScreen[i];
     }
    if(pScreen)delete []pScreen;
    pScreen=NULL;
    this->setSize(400,225);
    ui->cover->setFixedSize(0,0);
    ui->actionStart->setEnabled(true);
    ui->actionStop->setEnabled(false);
    ui->actionPause->setEnabled(false);
}

void MainWindow::pause(){
    if(timer->isActive()){
        timer->stop();
        mtimer->start();
        ui->actionStart->setEnabled(true);
        ui->actionPause->setEnabled(false);
    }
    else{
        timer->start();
        mtimer->stop();
    }
}

void MainWindow::setting(){
    nLong=ui->spinBox_3->value();
    nWolf=ui->spinBox_1->value();
    nSheep=ui->spinBox_2->value();
    msgBox->setWindowTitle("Set up success!");
    msgBox->setText("The parameter setting is done.\nPress \"Menu > Start(control+S)\" to Start!");
    msgBox->show();
}

void MainWindow::intro(){
    msgBox->setWindowTitle("About");
    msgBox->setText("This programme is developd by H.W. Luo.\nGo to http://rimoe.ml to get more information about author.");
    msgBox->show();
}

void MainWindow::aboutme(){
    msgBox->setWindowTitle("Introduction");
    msgBox->setText("This programme is used to simulate the number change of Wolf and Sheep on the virtual grassland.\nWolf will starve if it can't catch a sheep for several time, and Sheep will be eaten if it was caught by awolf\nSheep will starve if it have no grass to eat, and grass will grow every time-step.\nBoth Wolf and Sheep will die because of getting old, and baby will be born every cycle time.");
    msgBox->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0;i<6;i++)
        delete img[i];
    delete timer;
    delete mtimer;
    delete msgBox;
}
