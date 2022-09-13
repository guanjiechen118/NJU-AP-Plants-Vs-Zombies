#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include <QWidget>
#include"plant.h"
#include"grass.h"
class CherryBomb : public Plant
{
    Q_OBJECT
public:
    explicit CherryBomb(QWidget *parent,int x,int y);
    void make_action();
signals:

public slots:
};

#endif // CHERRYBOMB_H
