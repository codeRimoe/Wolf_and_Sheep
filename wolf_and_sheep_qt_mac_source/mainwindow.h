#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class Grid;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void build();

    int displayQt();

protected:
    void setSize(int,int);
    void state(int);

private:
    Ui::MainWindow *ui;
    QImage *img[6];
    QLabel ***pScreen;
    QLabel *currentTimeLabel,*Label_St;
    QTimer *timer,*mtimer;
    QMessageBox *msgBox;
    Grid *pGrid;
    int nWolf,nSheep,nLong;

private slots:
    void timeUpdate();
    void loop();
    void setting();
    void start();
    void stop();
    void pause();
    void aboutme();
    void intro();
};

#endif // MAINWINDOW_H
