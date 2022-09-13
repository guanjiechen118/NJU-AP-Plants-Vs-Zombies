#include "starfruit.h"

StarFruit::StarFruit(QWidget *parent,int X,int Y) : Plant(parent,X,Y,":/Starfruit.gif")
{
    HP=150;
    FPS_gap=30*1.5;
}
void StarFruit::make_action()
{
    if(!grass::line_has_zom(line)) return;
    new Star(this->parentWidget(),_x,_y,0);
    new Star(this->parentWidget(),_x,_y,1);
    new Star(this->parentWidget(),_x,_y,2);
    new Star(this->parentWidget(),_x,_y,3);
    new Star(this->parentWidget(),_x,_y,4);
}
