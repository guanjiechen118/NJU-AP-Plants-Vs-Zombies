#include "peashooter.h"

PeaShooter::PeaShooter(QWidget *parent,int x,int y) : Plant(parent,x,y,":/Peashooter.gif")
{
    HP=150;
    FPS_gap=30*2;
}
void PeaShooter::make_action()
{
    if(!grass::line_has_zom(line)) return;
    new Bullet(this->parentWidget(),_x,_y);
}
