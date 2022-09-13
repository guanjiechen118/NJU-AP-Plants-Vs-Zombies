#ifndef STARFRUIT_H
#define STARFRUIT_H

#include <QWidget>
#include"plant.h"
#include"bullet.h"
class StarFruit : public Plant
{
    Q_OBJECT
public:
    explicit StarFruit(QWidget *parent ,int x,int y);
    void make_action();
signals:

public slots:
};

#endif // STARFRUIT_H
