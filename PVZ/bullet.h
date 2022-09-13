#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<zombies.h>
#include"QPair"
extern int FPS;
enum BULLET_STATE{BULLET_DIED,BULLET_ALIVE};
extern grass* grass_arry[5][20];
class Bullet : public QWidget
{
    Q_OBJECT
public:
    explicit Bullet(QWidget *parent,int x,int y,QString str1=":/Pea.gif",QString str2=":/PeaHit.gif");
    ~Bullet();
    virtual void make_action();
    virtual void move();
signals:
    void died();
public slots:
protected:
    int power;
    int speed;
    int FPS_gap;
    int _x;
    int _y;
    bool rehanced;
    QString str;
    QString died_str;
    QTimer* timer;
    QLabel* label;
    QMovie* movie;
    int cont;
    BULLET_STATE state;
};
class Star : public Bullet
{
    Q_OBJECT
public:
    explicit Star(QWidget *parent,int x,int y,int _state);
    ~Star();
    void move();
private:
    int mystate;
signals:

public slots:
};
#endif // BULLET_H
