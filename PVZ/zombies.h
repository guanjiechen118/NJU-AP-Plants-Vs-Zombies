#ifndef ZOMBIES_H
#define ZOMBIES_H
#include<QString>
#include <QWidget>
#include "grass.h"
#include<QMovie>
#include<QDebug>
#define ZOMWID 150
#define ZOMHEI 150
extern int FPS;
extern grass* grass_arry[5][20];

enum ZOMBIE_STATE{DIED,WALKING,EATING,UP,DOWN};
enum ZOMBIE_TYPE{AIR,GROUND};
class zombies : public QWidget
{
    Q_OBJECT
public:
    explicit zombies(QWidget *parent,int line,int cross,QString STR,QString DIE=":/ZombieDie.gif");
    virtual ~zombies();
    virtual void make_actions()=0;
    virtual void after_action();
    virtual void move();
    bool near_plant();
    bool In_grass();
    void eat_plant();
    void hited(int num)
    {
        HP-=num;
    }
    int meet_place()
    {
        return place_x+ZOMWID/3;
    }
    bool In_ground(){return type==GROUND;}
    void Get_fire()
    {
        burn=true;
    }

signals:
    void died();
public slots:
protected:
    QString str;
    QString die_str;
    QString Burn_str;
    QLabel* label;
    QMovie* movie;
    QLabel* hp_label;
    QLabel* back;
    int Full_HP;
    int HP;
    int speed;
    int FPS_gap;
    int move_gap;
    int pix_x;
    int pix_y;
    int place_x;
    int place_y;
    int _line;
    int _cross;
    ZOMBIE_STATE state;//0 is died , the rest is alive or other state;
    ZOMBIE_TYPE type;
    int cont;
    bool burn;
private:
    void zombies_win();
};

#endif // ZOMBIES_H
