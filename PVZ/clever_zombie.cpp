#include "clever_zombie.h"

clever_zombie::clever_zombie(QWidget *parent,int line,int cross) :zombies(parent,line,cross,":/Zombie.gif",":/ZombieDie.gif")
{
    HP = 200;
    Full_HP=200;
    speed=1;
    FPS_gap=15;
}
void clever_zombie::move()
{
    switch(state)
    {
    case WALKING:
    {   place_x-=speed;
        pix_x-=speed;
        label->move(pix_x,pix_y);
        break;}
    case UP:{
        place_y-=3*speed;
        pix_y-=3*speed;
        label->move(pix_x,pix_y);
        break;}
    case DOWN:{
        place_y+=3*speed;
        pix_y+=3*speed;
        label->move(pix_x,pix_y);
        break;}
    }
}
void clever_zombie::make_actions()
{
    if(!In_grass())
       {
        state=WALKING;
        return;
       }
    QPair<int,int> pair = grass::Locate(place_x,place_y);
    if(near_plant())
    {
        if((pair.first+1)<5 && !grass_arry[pair.first+1][pair.second]->Is_occupied())
        {
            if(state==EATING)
            {
                delete movie;
                movie = new QMovie(str);
                movie->start();
                label->setMovie(movie);
            }
            state=DOWN;
            return;
        }
        else if((pair.first-1)>=0 && !grass_arry[pair.first-1][pair.second]->Is_occupied())
        {
            if(state==EATING)
            {
                delete movie;
                movie = new QMovie(str);
                movie->start();
                label->setMovie(movie);
            }
            state=UP;
            return;
        }
        if(grass_arry[pair.first][pair.second]->Is_eatable())
        {
            if(state==EATING)
            {
                this->eat_plant();
                return;
            }
            else state=EATING;
            delete movie;
            movie = new QMovie(":/ZombieAttack.gif");
            movie->start();
            label->setMovie(movie);
            this->eat_plant();
            return;
        }
        else state=WALKING;
    }
    else
        if(state==EATING)
        {
            state=WALKING;
            delete movie;
            movie = new QMovie(str);
            movie->start();
            label->setMovie(movie);
        }
    state=WALKING;
}

