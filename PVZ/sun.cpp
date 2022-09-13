#include "sun.h"
#include<QMovie>
#include<vector>
#include<QPushButton>
#define gap 5000
#define cross_gap 105
#define line_gap 120
#define x_base 330
#define y_base 200
Sun::Sun(QWidget *parent,int sum) : QWidget(parent),unclicked_sun(0)
{
    this->setFixedSize(0,0);
    this->setParent(parent);
    this->Sun_sum=sum;
    pix.load(":/Sun.gif");
    this->label = new QLabel;
    this->label->setParent(parent);
    this->label->move(100,100);
    QSize size(200,50);
    this->label->resize(size);
    QFont font ("Microsoft YaHei",13,75);
    this->label->setFont(font);
    this->update();
    id1 = startTimer(FPS);
    id2 = startTimer(15000);
}
 void Sun::produce_sun(int x,int y,bool state)
 {
     //qDebug()<<x<<" "<<y;
     if(unclicked_sun==45)
     {
         qDebug()<<"Too much sun uncollected!";
         return;
     }
     ++unclicked_sun;
     QPushButton* bnt = new QPushButton((QWidget*)this->parent());
     bnt->move(x,y);
     QSize size(100,100);
     bnt->resize(size);
     bnt->setIcon(pix);
     bnt->setIconSize(size);
     bnt->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
     sun one_sun;
     one_sun.btn=bnt;
     one_sun.x=x;
     one_sun.y=y;
     one_sun.state=state;
     sun_vec.push_back(one_sun);
     bnt->show();
     connect(bnt,&QPushButton::clicked,[=](){
         this->add();
         std::vector<sun>::iterator iter = sun_vec.begin();
         while(iter->btn!=bnt)
             ++iter;
         sun_vec.erase(iter);
         --unclicked_sun;
         bnt->close();
     });
 }
void Sun::timely_produce_sun()
{
    produce_sun(100+rand()%1000,150,true);
}
 void Sun::timerEvent(QTimerEvent * ev)// ev1 is FPSms , ev2 is 5000ms
 {
     if(ev->timerId()==id1)
     {
         for(int i=0 ; i < sun_vec.size();++i)
         if(sun_vec[i].y<650 && sun_vec[i].state)
         {
             sun_vec[i].btn->move(sun_vec[i].x,sun_vec[i].y);
             sun_vec[i].y+=2;
         }
         else if(!sun_vec[i].state)
         {
             if(sun_vec[i].y<sun_vec[i].y/(line_gap/2)*(line_gap/2)+(line_gap/2-10))
             {
                 sun_vec[i].btn->move(sun_vec[i].x,sun_vec[i].y);
                 sun_vec[i].y+=2;
                 sun_vec[i].x+=2;
             }
         }

     }
     if(ev->timerId()==id2)
     {
         timely_produce_sun();
     }
 }
