#ifndef PLAYSENCE_H
#define PLAYSENCE_H
#include <QMainWindow>
#include <QMainWindow>
#include<QPainter>
#include<QMenuBar>
#include<QMenu>
#include<QDebug>
#include<QPushButton>
#include<QSize>
#include<QLabel>
#include<QString>
#include<QFont>
#include<QTimer>
#include<QMouseEvent>
#include"sun.h"
#include"sunflower.h"
#include"grass.h"
#include"car.h"
#include"clever_zombie.h"
#include"airzombie.h"
#include"card.h"
#define x_base 300
#define y_base 180
#define x_gap 92
#define y_gap 100
class Card;
extern int FPS;
extern grass* grass_arry[5][20];
namespace Ui {
class playSence;
}

class playSence : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
    explicit playSence(QWidget *parent = 0);
    ~playSence();
    void mousePressEvent(QMouseEvent *event);
    void generate_zombies();
    void Display();
private:
    Ui::playSence *ui;
    QTimer* timer;
    Sun* sun;
    Card* cards;
    int cont;
    int conter;
};

#endif // PLAYSENCE_H
