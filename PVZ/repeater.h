#ifndef REPEATER_H
#define REPEATER_H

#include <QWidget>
#include"plant.h"
#include"bullet.h"
class Repeater : public Plant
{
    Q_OBJECT
public:
    explicit Repeater(QWidget *parent,int X,int Y);
    void make_action();
signals:

public slots:
};

#endif // REPEATER_H
