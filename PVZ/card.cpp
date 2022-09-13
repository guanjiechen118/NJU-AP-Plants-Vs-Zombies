#include "card.h"

Card::Card(QWidget *parent) :  QWidget(parent),card_num(0)
{
    fresh_gap=20;
    connect(this,&Card::disabled,[=](){
        if(index>=0&&index<card_num)
        {
            buttons[index]->setDisabled(true);
            percent[index]=0;
            percent_label[index]->setText(QString::number(percent[index]).append('%'));
            percent_label[index]->show();
        }
        selected_one=_NONE;
        index=-1;
    });
    cont=0;
    timer = new QTimer(this);
    timer->start(FPS);
    connect(timer,&QTimer::timeout,[=](){
        ++cont;
        if(cont>=fresh_gap)
        {
            for(int i=0;i<card_num;++i)
            {
                percent[i]+=10;
                if(percent[i]<100)
                {
                    percent_label[i]->setText(QString::number(percent[i]).append('%'));
                    percent_label[i]->show();
                }
                else
                {
                    percent_label[i]->hide();
                    buttons[i]->setDisabled(false);
                }
            }
            cont=0;
        }
    });
}
bool Card::AddCard(Plants PlantType,int cost,QString path)
{
    int i = card_num;
    QPushButton* bnt = new QPushButton(this->parentWidget());
    bnt->move(80*card_num,20);
    buttons[card_num]=bnt;
    percent[card_num]=100;
    QSize size(80,80);
    bnt->resize(size);
    QPixmap pix;
    pix.load(path);
    bnt->setIcon(pix);
    bnt->setIconSize(size);
    bnt->show();

    QLabel* label = new QLabel(this->parentWidget());
    label->move(80*card_num,70);
    QSize size2(60,20);
    label->resize(size2);
    QFont font ("Microsoft YaHei",13,75);
    label->setFont(font);
    label->setText(QString::number(cost));

    percent_label[card_num] = new QLabel(this->parentWidget());
    percent_label[card_num]->move(80*card_num+20,30);
    QSize size3(80,30);
    percent_label[card_num]->resize(size3);
    percent_label[card_num]->setFont(font);
    QString str = QString::number(percent[card_num]);
    percent_label[card_num]->setText(str.append('%'));
    percent_label[card_num]->hide();
    ++card_num;
    connect(bnt,&QPushButton::clicked,[=](){
        selected_one=PlantType;
        index = i;
    });
    return true;
}
 bool Card::AddTool(Plants ToolType,QString path)
 {
     int i = card_num;
     QPushButton* bnt = new QPushButton(this->parentWidget());
     bnt->move(80*card_num,20);
     buttons[card_num]=bnt;
     QSize size(80,80);
     bnt->resize(size);
     QPixmap pix;
     pix.load(path);
     bnt->setIcon(pix);
     bnt->setIconSize(size);
     bnt->show();
     connect(bnt,&QPushButton::clicked,[=](){
         selected_one=ToolType;
         index = i;
     });
     return true;
 }
