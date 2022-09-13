#include "car.h"

Car::Car(QWidget *parent,int x,int y) :Bullet(parent,x,y,":/car.png",":/Boom.gif")
{
    label->resize(80,60);
    FPS_gap=30;
    power=99999;
    speed=10;
    triggered=false;
}

void Car::move()
{
    if(!triggered)
        return;
    _x+=speed;
    label->move(_x,_y);
    QPair<int,int> pair;
    pair=grass::Locate(_x,_y);
    if(pair.first>=0)
    {
        grass_arry[pair.first][pair.second]->hit_all(power);
    }
}
void Car::make_action()
{
    QPair<int,int> pair;
    pair=grass::Locate(_x,_y);
    //qDebug()<<grass_arry[pair.first][pair.second+1]->has_zom();
    //qDebug()<<pair.first<<" "<<pair.second<<"   "<<grass_arry[pair.first][pair.second+1]->has_zom();
    if(grass_arry[pair.first][pair.second+1]->has_zom())
    {
        //grass_arry[pair.first][pair.second+1]->hit_all(power);
        triggered=true;
    }
    else if(pair.second>=0 && grass_arry[pair.first][pair.second]->has_zom())
    {
        //grass_arry[pair.first][pair.second]->hit_all(power);
        triggered=true;
    }
    //qDebug()<<pair.second;
    if(pair.second>=9)
    {
        emit died();
    }
}
