#include "bullet.h"

Star::Star(QWidget *parent,int x,int y,int _state) :Bullet(parent,x,y,":/Star.gif",":/Star.gif")
{
    label->resize(50,50);
    speed = 6;
    power=10;
    mystate=_state;
}
void Star::move()
{
    switch(mystate)
    {
    case 0:
    {
        _x+=speed;
        _y+=speed/3;
        label->move(_x,_y);
        break;
    }
    case 1:
    {
        _x+=speed;
        _y-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 2:
    {
        _y+=speed;
        _x-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 3:
    {
        _y-=speed;
        _x-=speed/3;
        label->move(_x,_y);
        break;
    }
    case 4:
    {
        _x-=speed;
        label->move(_x,_y);
        break;
    }
    }
}
Star::~Star()
{
    qDebug()<<"son deleted\n";
}
