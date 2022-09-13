#include "cherrybomb.h"

CherryBomb::CherryBomb(QWidget *parent,int x,int y) : Plant(parent,x,y,":/CherryBomb.gif")
{
    movie->setSpeed(50);
    movie->start();
    label->setMovie(movie);
    label->resize(120,80);
    power=1000;
    HP=100;
    FPS_gap=30;
}
void CherryBomb::make_action()
{
    label->resize(150,150);
    delete movie;
    movie=new QMovie(":/Boom.gif");
    label->move(_x,_y-40);
    movie->setSpeed(60);
    movie->start();
    label->setMovie(movie);
    QPair<int,int> pair;
    pair=grass::Locate(_x,_y);
    grass_arry[pair.first][pair.second]->hit_all_F(power);
    if(pair.second-1>=0) grass_arry[pair.first][pair.second-1]->hit_all_F(power);
    grass_arry[pair.first][pair.second+1]->hit_all_F(power);
    if(pair.first-1>=0)
    {
        grass_arry[pair.first-1][pair.second]->hit_all_F(power);
        if(pair.second-1>=0) grass_arry[pair.first-1][pair.second-1]->hit_all_F(power);
        grass_arry[pair.first-1][pair.second+1]->hit_all_F(power);
    }
    if(pair.first+1<5)
    {
        grass_arry[pair.first+1][pair.second]->hit_all_F(power);
        if(pair.second-1>=0) grass_arry[pair.first+1][pair.second-1]->hit_all_F(power);
        grass_arry[pair.first+1][pair.second+1]->hit_all_F(power);
    }
    cont=0;
    connect(timer,&QTimer::timeout,[=](){
        ++cont;
        if(cont==FPS_gap/2)
        {
            emit died();
        }
    });
}
