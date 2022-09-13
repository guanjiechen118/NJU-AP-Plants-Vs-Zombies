#include "airzombie.h"

AirZombie::AirZombie(QWidget *parent,int x,int y) : zombies(parent,x,y,":/AirZombie.png")
{
    fire = new QLabel(parent);
    fire->move(pix_x,180+100*y+50);
    fire->resize(80,60);
    fire_movie = new QMovie(":/Fire.gif");
    fire_movie->start();
    fire->setMovie(fire_movie);
    fire->show();
    HP=200;
    Full_HP=200;
    FPS_gap=20;
    speed=1;
    type=AIR;
    down20up=true;
}
void AirZombie::make_actions()
{
    down20up=!down20up;
    eat_plant();
    eat_plant();
    eat_plant();
    eat_plant();
    eat_plant();
}
void AirZombie::move()
{
    place_x-=speed;
    pix_x-=speed;
    if(down20up)
    {
        place_y-=speed;
        pix_y-=speed;
        label->move(pix_x,pix_y);
    }
    else
    {
        place_y+=speed;
        pix_y+=speed;
        label->move(pix_x,pix_y);
    }
    fire->move(pix_x,180+100*_line+50);
}
AirZombie::~AirZombie()
{
    fire->hide();
    delete fire;
}
