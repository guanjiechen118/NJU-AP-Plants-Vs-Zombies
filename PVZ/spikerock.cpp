#include "spikerock.h"

SpikeRock::SpikeRock(QWidget *parent,int x,int y) : Plant(parent,x,y,":/Spikerock0.png")
{
    label->resize(80,60);
    HP=150;
    power=5;
    FPS_gap=30*1;
}
void SpikeRock::make_action()
{
    QPair<int,int> pair;
    pair=grass::Locate(_x,_y);
    if(grass_arry[pair.first][pair.second]->has_zom())
    {
        label->resize(100,80);
        grass_arry[pair.first][pair.second]->hit_all_G(power);
        qDebug()<<"Spike hit!";
    }
   else label->resize(80,60);
}
