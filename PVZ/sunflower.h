#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include <QWidget>
#include"plant.h"
#include"sun.h"
class SunFlower :public Plant
{
    Q_OBJECT
public:
    explicit SunFlower(QWidget *parent,int X,int Y,Sun* SUN);
    void make_action();
signals:

public slots:
private:
    Sun* sun;
};

#endif // SUNFLOWER_H
