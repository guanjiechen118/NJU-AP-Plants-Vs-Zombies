#include "playsence.h"
#include "ui_playsence.h"

playSence::playSence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playSence)
{
    cont=0;
    conter=0;
    this->setWindowIcon(QIcon(":/mainlogo.png"));
    this->setWindowTitle("Plants vs Zombies");
    this->setFixedSize(1400,700);

    //播放开场动画
    static QLabel* startMovie=new QLabel(this);
    startMovie->resize(1400,600);
    startMovie->move(500,100);
    QMovie* _movie = new QMovie(":/ZombieNote1.png");
    _movie->start();
    startMovie->setMovie(_movie);
    startMovie->show();
    QTimer* temp =new QTimer;
    temp->setSingleShot(true);
    temp->start(6000);
    connect(temp,&QTimer::timeout,[=](){
        startMovie->close();
        delete startMovie;
        Display();
    });


    ui->setupUi(this);
    timer=new QTimer(this);
    timer->start(FPS);
    sun = new Sun(this,3000);
    for(int i=0;i<5;++i)
        for(int j=0;j<20;++j)
            grass_arry[i][j]=new grass(this,i,j,sun);
    cards=new Card(this);
    cards->AddCard(_SunFlower,50,":/SunFlower.gif");
    cards->AddCard(_Repeater,200,":/Repeater.gif");
    cards->AddCard(_PeaShooter,100,":/Peashooter.gif");
    cards->AddCard(_NutWall,100,":/WallNut.gif");
    cards->AddCard(_FireTree,150,":/FireTree.gif");
    cards->AddCard(_CherryBomb,150,":/CherryBomb.gif");
    cards->AddCard(_SpikeRock,150,":/Spikerock0.png");
    cards->AddCard(_StarFruit,200,":/Starfruit.gif");
    cards->AddTool(_SHOVEL,":/Shovel.png");
    generate_zombies();
    for(int i=0;i<5;++i)
        new Car(this,x_base-x_gap,y_base+i*y_gap);
}

playSence::~playSence()
{
    delete ui;
}
void playSence::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/background1.jpg");
    painter.drawPixmap(0,100,this->width()+200,this->height()-100,pix);
    pix.load(":/SunBack.png");
    painter.drawPixmap(10,100,175,50,pix);
}
void playSence::mousePressEvent(QMouseEvent *event)
{
    //qDebug()<<"mouse pressed";
    if(cards->selected_one==_NONE)
    {
        qDebug()<<"is none";
        return;

    }
        QPair<int,int> pair = grass::Locate(event->x(),event->y());
    if(0<=pair.first&&pair.first<5&&pair.second>=0&&pair.second<9)
      {
           if(grass_arry[pair.first][pair.second]->Anchor(cards->selected_one))
           {
                qDebug()<<"栽种植物成功！";
                emit cards->disabled();
                return;//匹配成功会在disable函数中完成重置，不能在这里做重置，否则会报错
           }
           else
           {
               cont=0;
               QLabel* reminder=new QLabel(this);
               reminder->move(event->x(),event->y());
               reminder->resize(60,20);
               reminder->setText("阳光不足");
               reminder->show();
               connect(timer,&QTimer::timeout,[=](){
                   ++cont;
                   if(cont>=30)
                   {
                       reminder->hide();
                       //delete reminder;
                       cont=0;
                   }
               });
           }
      }
    else
    {
        qDebug()<<"match failed";
    }
    cards->index=-1;
    cards->selected_one=_NONE;
    return;
}
void playSence::generate_zombies()
{
    int place=qrand()%5;
    int type=qrand()%25;

    if(type==0||type==1||type==2)
        new AirZombie(this,place,12);
    else if(type==3||type==5||type==6)
        for(int i=0;i<5;++i)
            new clever_zombie(this,i,12);
    else if(type==4||type==7||type==8)
        for(int i=0;i<5;++i)
            new AirZombie(this,i,12);
    else new clever_zombie(this,place,12);
}
void playSence::Display()
{
    for(int i=0;i<4;++i)
             grass_arry[i][1]->Anchor(_SunFlower);
    for(int i=0;i<4;++i)
             grass_arry[i][0]->Anchor(_Repeater);
    for(int i=0;i<4;++i)
             grass_arry[i][2]->Anchor(_PeaShooter);
    for(int i=0;i<3;++i)
        grass_arry[i*2][8]->Anchor(_SpikeRock);
    for(int i=0;i<2;++i)
        grass_arry[i*2+1][6]->Anchor(_FireTree);

    grass_arry[0][3]->Anchor(_StarFruit);
    grass_arry[2][3]->Anchor(_StarFruit);
    grass_arry[4][3]->Anchor(_StarFruit);

    grass_arry[1][7]->Anchor(_NutWall);
    grass_arry[3][7]->Anchor(_NutWall);

    for(int i=0;i<5;++i)
    {
        new clever_zombie(this,i,13);
        new clever_zombie(this,i,14);
        new clever_zombie(this,i,15);
    }

    connect(timer,&QTimer::timeout,[=](){
       ++conter;
        static bool flag =true;
       if(conter>=30*6)
       {
           conter=0;
           if(flag)
           {
               for(int i=0;i<5;++i)
               {
                   new AirZombie(this,i,14);
                   flag=false;
               }
           }
           else
           generate_zombies();
       }
    });
}
