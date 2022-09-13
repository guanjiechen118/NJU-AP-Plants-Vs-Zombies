#include "zombies.h"

zombies::zombies(QWidget *parent,int line,int cross,QString STR,QString DIE) : QWidget(parent)
{
    //zombies_win();
    burn = false;
    type=GROUND;
    _line=line;
    _cross=cross;
    grass_arry[_line][_cross]->anchor_zombie(this);
    state=WALKING;
    FPS_gap=30;//defult gap
    move_gap=1;
    QTimer* timer=new QTimer(this);
    timer->start(FPS);
    str=STR;
    die_str=DIE;
    Burn_str=":/BurnDie.gif";
    place_x=x_base+x_gap*cross;
    place_y=y_base+y_gap*line+50;
    pix_x=place_x-ZOMWID/2-20;pix_y=place_y-110;
    label = new QLabel(parent);
    label->move(pix_x,pix_y);
    label->resize(ZOMWID,ZOMHEI);
    movie = new QMovie(str);
    movie->start();
    label->setMovie(movie);
    label->show();
    back = new QLabel(parent);
    hp_label=new QLabel(parent);
    back->resize(ZOMWID,20);
    hp_label->resize(ZOMWID-4,16);
    back->move(pix_x,pix_y);
    hp_label->move(pix_x+2,pix_y+2);
    back->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");
    hp_label->setStyleSheet("QLabel{background-color:rgb(255,0,0);}");
    back->show();
    hp_label->show();
    cont=0;
    connect(timer,&QTimer::timeout,[=](){
        back->move(pix_x,pix_y);
        hp_label->move(pix_x+2,pix_y+2);
        hp_label->resize((ZOMWID-4)*HP/Full_HP,16);
        if(state!=DIED)//the judge works only when the zombie is alive
        {
            if(HP<0)
            {
                emit died();
            }
            else
            {
                ++cont;
                if(cont%move_gap==0)
                {
                    move();
                    label->show();
                    QPair<int,int> pair;
                    pair=grass::Locate(place_x,place_y);
                    if(pair.second>=0)
                    {

                            grass_arry[_line][_cross]->delete_zombie(this);
                            grass_arry[pair.first][pair.second]->anchor_zombie(this);
                            _line=pair.first;
                            _cross=pair.second;
                    }
                    else
                    {
                        zombies_win();
                    }
                }
                if(cont>=FPS_gap)
                {
                    cont=0;
                    make_actions();
                    after_action();
                }
            }
        }
    });
    connect(this,&zombies::died,[=](){
        QPair<int,int> pair;
        pair=grass::Locate(place_x,place_y);
        grass_arry[pair.first][pair.second]->delete_zombie(this);
        //qDebug()<<"zombie died at:"<<pair.first<<" "<<pair.second<<" the grass has zombie?"<< grass_arry[pair.first][pair.second]->has_zom();
        delete movie;
        if(!burn)
        movie = new QMovie(die_str);
        else movie =new QMovie(Burn_str);
        movie->start();
        state=DIED;//zero reperesent death
        label->setMovie(movie);
        cont=0;
        connect(timer,&QTimer::timeout,[=](){
            ++cont;
            if(cont==30*3)
            {
                label->close();
                back->close();
                hp_label->close();
                delete this;
            }
        });
    });
}
void zombies::move()//defule function
{
    place_x-=speed;
    pix_x-=speed;
    label->move(pix_x,pix_y);
    label->show();
}
void zombies::eat_plant()
{
    QPair<int,int> pair;
    pair=grass::Locate(place_x,place_y);
    if(!(0<=pair.first&&pair.first<5&&pair.second>=0&&pair.second<9))
        return;
    if(grass_arry[pair.first][pair.second]->plant && grass_arry[pair.first][pair.second]->Is_eatable())
        grass_arry[pair.first][pair.second]->plant->eaten();
}
bool zombies::near_plant()
{
    //qDebug()<<"the zombie is near the plant\n";
    QPair<int,int> pair;
    pair=grass::Locate(place_x,place_y);
    //qDebug()<<"the pair.first is:"<<pair.first<<"the pair.second is:"<<pair.second<<endl;
    if(0<=pair.first&&pair.first<5&&pair.second>=0&&pair.second<9)
    {
        //qDebug()<<grass_arry[pair.first][pair.second]->Is_occupied();
        return(grass_arry[pair.first][pair.second]->Is_occupied());
    }
    else
        return false;
}
void zombies::after_action()
{
    //default doing nothing
}
bool zombies::In_grass()
{
    QPair<int,int> pair;
    pair=grass::Locate(place_x,place_y);
    return (0<=pair.first&&pair.first<5&&pair.second>=0&&pair.second<9);
}
void zombies::zombies_win()
{
    qDebug()<<"zombie win";
    FPS=2000000;
    QLabel* end = new QLabel(this->parentWidget());
    end->resize(1400,700);
    QMovie* m=new QMovie(":/ZombiesWon.png");
    m->start();
    end->setMovie(m);
    end->show();
}
zombies::~zombies(){}
