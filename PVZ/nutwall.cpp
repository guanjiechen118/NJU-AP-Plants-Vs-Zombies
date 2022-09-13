#include "nutwall.h"

NutWall::NutWall(QWidget *parent,int X,int Y) : Plant(parent,X,Y,":/WallNut.gif")
{
    state=0;
    HP=1000;
    power=0;
    FPS_gap=30;
}

void NutWall::make_action()
{
    if(HP<500&&250<=HP&&state!=1)
    {
        state=1;
        delete movie;
        movie=new QMovie(":/Wallnut_1.gif");
        movie->start();
        label->setMovie(movie);
    }
    else if(HP<250&&state!=2)
    {
        state=2;
        delete movie;
        movie=new QMovie(":/Wallnut_2.gif");
        movie->start();
        label->setMovie(movie);
    }
}
