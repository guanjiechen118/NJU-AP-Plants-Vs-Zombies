#ifndef NUTWALL_H
#define NUTWALL_H

#include <QWidget>
#include"plant.h"
class NutWall : public Plant
{
    Q_OBJECT
public:
    explicit NutWall(QWidget *parent,int X,int Y);
    void make_action();
    int state;//0 is health, 1 is injuried, 2 is deeeeply injuried
signals:

public slots:
};

#endif // NUTWALL_H
