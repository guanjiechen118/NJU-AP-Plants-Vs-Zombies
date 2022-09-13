#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include <QWidget>
#include"plant.h"
#include"bullet.h"
extern int FPS;
class PeaShooter : public Plant
{
    Q_OBJECT
public:
    explicit PeaShooter(QWidget *parent,int X,int Y);
    void make_action();
signals:

public slots:
};

#endif // PEASHOOTER_H
