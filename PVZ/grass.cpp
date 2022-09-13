#include "grass.h"

grass::grass(QWidget *parent,int line,int cross,Sun* SUN) : QWidget(parent),zoms()
{
    occupied=false;
    eatable=false;
    rehance=false;
    _x=x_base+x_gap*cross;
    _y=y_base+y_gap*line;
    _line=line;
    _cross=cross;

    sun=SUN;
}

bool grass::In(int x,int y)
{
    return (_x<x&&x<(_x+x_gap))&&(_y<y&&x<(_y+y_gap));
}

bool grass::Anchor(Plants type)
{
    if(type==_SHOVEL)
        {
            //qDebug()<<"enter shovel";
            if(plant&&occupied)
            {
                emit this->plant->died();
                eatable=false;
                occupied=false;
                rehance=false;
                plant=NULL;
                return true;
            }
        }
    if(occupied)
        return false;
    if(type==_SunFlower)
    {
        if(!sun->cost(50))
            return false;
        plant=new SunFlower(this->parentWidget(),_x,_y,sun);
        eatable=true;
    }
    else if(type==_NutWall)
    {
        if(!sun->cost(100))
            return false;
        plant=new NutWall(this->parentWidget(),_x,_y);
        eatable=true;
    }
    else if(type==_PeaShooter)
    {
        if(!sun->cost(100))
            return false;
        plant=new PeaShooter(this->parentWidget(),_x,_y);
        eatable=true;
    }
    else if(type==_Repeater)
    {
        if(!sun->cost(200))
            return false;
        plant=new Repeater(this->parentWidget(),_x,_y);
        eatable=true;
    }
    else if(type==_SpikeRock)
    {
        if(!sun->cost(150))
            return false;
        plant=new SpikeRock(this->parentWidget(),_x,_y);
        eatable=false;
    }
    else if(type==_FireTree)
    {
        if(!sun->cost(150))
            return false;
        plant=new FireTree(this->parentWidget(),_x,_y);
        eatable=true;
        rehance=true;

    }
    else if(type==_CherryBomb)
    {
        if(!sun->cost(150))
            return false;
        plant=new CherryBomb(this->parentWidget(),_x,_y);
        eatable=false;
    }
    else if(type==_StarFruit)
    {
        if(!sun->cost(200))
            return false;
        plant=new StarFruit(this->parentWidget(),_x,_y);
        eatable=true;
    }
    else return false;

    connect(plant,&Plant::died,[=](){
        //qDebug()<<"died";
        plant->label->close();
        delete plant;
        plant=NULL;
        eatable=false;
        occupied=false;
        rehance=false;
    });
    occupied=true;
    return true;
}
QPair<int,int> grass::Locate(int x,int y)
{
    QPair<int,int> pair;
    pair.second=(x-x_base)/x_gap;
    pair.first=(y-y_base)/y_gap;
    return pair;
}

void grass::anchor_zombie(zombies* newzom)
{
    this->zoms.push_front(newzom);
}

void grass::delete_zombie(zombies* newzom)
{
    this->zoms.removeOne(newzom);
}
bool grass::hit_first(int power)
{
    this->zoms.first()->hited(power);
}

bool grass::hit_all(int power)
{
    QLinkedList<zombies*>::iterator iter;
    for (iter=zoms.begin();iter!=zoms.end();iter++)
        (*iter)->hited(power);
}
bool grass::hit_all_F(int power)
{
    QLinkedList<zombies*>::iterator iter;
    for (iter=zoms.begin();iter!=zoms.end();iter++)
    {
        (*iter)->Get_fire();
        (*iter)->hited(power);
    }
}
bool grass::hit_all_G(int power)
{
    QLinkedList<zombies*>::iterator iter;
    for (iter=zoms.begin();iter!=zoms.end();iter++)
        if((*iter)->In_ground())(*iter)->hited(power);
}

bool grass::has_zom()
{
    return !zoms.empty();
}

int grass::firs_zom_x()
{
    if(zoms.empty())
    {
        qDebug()<<"Error:the zoms arry of grass is empty!!!!!!";
        return 0;
    }
    return this->zoms.first()->meet_place();
}
bool grass::line_has_zom(int line)
{
    bool res=false;
    for(int i=0;i<15;++i)
    {
        res=res||(grass_arry[line][i]->has_zom());
    }
    return res;
}
