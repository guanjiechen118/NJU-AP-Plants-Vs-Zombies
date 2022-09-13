#include "plant.h"

Plant::Plant(QWidget *parent,int X,int Y,QString STR) : QWidget(parent)
{
    cont=0;
    FPS_gap=2*30;
    _x=X;_y=Y;
    cross=(_x-x_base)/x_gap;
    line=(_y-y_base)/y_gap;
    str=STR;
    timer=new QTimer(this);
    timer->start(FPS);
    label = new QLabel(parent);
    label->move(_x,_y);
    label->resize(80,80);
    movie = new QMovie(str);
    movie->start();
    label->setMovie(movie);
    label->setScaledContents(true);
    label->show();
    connect(this,&Plant::update,[=](){
        delete movie;
        movie = new QMovie(str);
        movie->start();
        label->setMovie(movie);
        label->setScaledContents(true);
        label->resize(80,80);
        label->show();
    });
    connect(timer,&QTimer::timeout,[=](){
       ++cont;
        if(HP<=0)
            emit died();
        if(cont>=FPS_gap)
        {
            cont=0;
            make_action();
        }
    });

}

