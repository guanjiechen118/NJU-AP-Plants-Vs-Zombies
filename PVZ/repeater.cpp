#include "repeater.h"

Repeater::Repeater(QWidget *parent,int x,int y) : Plant(parent,x,y,":/Repeater.gif")
{
    HP=150;
    FPS_gap=30*1;
}
void Repeater::make_action()
{
    if(!grass::line_has_zom(line)) return;
    new Bullet(this->parentWidget(),_x,_y);
}
