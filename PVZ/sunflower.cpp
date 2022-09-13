#include "sunflower.h"
#include"plant.h"
SunFlower::SunFlower(QWidget *parent,int X,int Y,Sun* SUN) : Plant(parent,X,Y,":/SunFlower.gif")
{
    HP=100;
    power=0;
    FPS_gap=30*15;
    sun=SUN;
}

void SunFlower::make_action()
{
    sun->produce_sun(_x,_y,false);
}
