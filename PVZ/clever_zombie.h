#ifndef CLEVER_ZOMBIE_H
#define CLEVER_ZOMBIE_H

#include <QWidget>
#include"zombies.h"
class clever_zombie :public zombies
{//nice!!!!!!!!!!!!!!
    Q_OBJECT
public:
    explicit clever_zombie(QWidget *parent,int line,int cross);
    void move();
    void make_actions();
signals:

public slots:
};

#endif // CLEVER_ZOMBIE_H
