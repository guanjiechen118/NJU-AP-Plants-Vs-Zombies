#include "bullet.h"

Bullet::Bullet(QWidget *parent,int x,int y,QString STR,QString DIE_STR) : QWidget(parent)
{
    cont=0;
    rehanced=false;
    state=BULLET_ALIVE;
    str=STR;//":/Pea.gif";
    died_str=DIE_STR;//":/PeaHit.gif";
    speed=6;
    FPS_gap=3;
    power=15;
    timer=new QTimer(this);
    timer->start(30);
    label = new QLabel(parent);
    label->move(x,y);
    _x=x;
    _y=y;
    label->resize(80,40);
    movie = new QMovie(str);
    movie->start();
    label->setMovie(movie);
    label->setScaledContents(true);
    label->show();
    connect(timer,&QTimer::timeout,[=](){
        if(state==BULLET_ALIVE)
        {
            ++cont;
            move();
            if(cont>=FPS_gap)
            {
                cont=0;
                make_action();
            }
        }
    });
    connect(this,&Bullet::died,[=](){
        delete movie;
        movie=new QMovie(died_str);
        movie->start();
        label->setMovie(movie);
        state=BULLET_DIED;
        cont=0;
        connect(timer,&QTimer::timeout,[=](){
            ++cont;
            if(cont==20)
            {
                label->close();
                delete timer;
                //qDebug()<<"died";
                delete this;
            }
        });
    });
}

Bullet::~Bullet()
{
    //qDebug()<<"parent deleted\n";
}

//defult function
void Bullet::move()
{
    //qDebug()<<"move";
    _x+=speed;
    label->move(_x,_y);
}
void Bullet::make_action()
{
    QPair<int,int> pair;
    pair=grass::Locate(_x,_y);
    if(pair.second<0 || pair.first<0 ||pair.first>4 ||pair.second>=18)
    {
        emit died();
        return;
    }
    if(grass_arry[pair.first][pair.second]->Is_rehance()&&!rehanced)
    {
        delete movie;
        movie=new QMovie(":/PeaFire.gif");
        movie->start();
        label->setMovie(movie);
        label->resize(80,40);
        rehanced=true;
        power*=2;
    }
    if(pair.second<18&&(grass_arry[pair.first][pair.second]->has_zom()))
    {
        grass_arry[pair.first][pair.second]->hit_first(power);
        //qDebug()<<"hit zombie at :"<<pair.first<<" "<<pair.second<<" there has zom?:"<<grass_arry[pair.first][pair.second]->has_zom();
        emit died();
    }
    else
        if(pair.second>=18)
        {
            //qDebug()<<"over 18";
            emit died();
        }

}


