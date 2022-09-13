#ifndef FIRETREE_H
#define FIRETREE_H

#include <QWidget>
#include"plant.h"
class FireTree : public Plant
{
    Q_OBJECT
public:
    explicit FireTree(QWidget *parent,int x,int y);
    void make_action();
signals:

public slots:
};

#endif // FIRETREE_H
