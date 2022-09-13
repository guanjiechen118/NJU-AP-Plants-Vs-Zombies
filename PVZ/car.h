#ifndef CAR_H
#define CAR_H

#include <QWidget>
#include "bullet.h"
class Car : public Bullet
{
    Q_OBJECT
public:
    explicit Car(QWidget *parent,int x,int y);
    virtual void make_action();
    virtual void move();
    bool triggered;
signals:

public slots:
};

#endif // CAR_H
