#ifndef AIRZOMBIE_H
#define AIRZOMBIE_H

#include <QWidget>
#include"zombies.h"
#include"clever_zombie.h"
class AirZombie : public zombies
{
    Q_OBJECT
public:
    explicit AirZombie(QWidget *parent,int line ,int cross);
    ~AirZombie();
    void make_actions();
    void move();
    bool down20up;
signals:

public slots:
private:
    QLabel* fire;
    QMovie* fire_movie;
};

#endif // AIRZOMBIE_H
