#ifndef SUN_H
#define SUN_H
#include<QLabel>
#include <QWidget>
#include<QDebug>
#include<QPushButton>
#include<vector>
extern int FPS;
struct sun
{
    QPushButton* btn;
    int x;
    int y;
    bool state;//if state is true , the sun will drop natuarly
};

class Sun : public QWidget
{
    Q_OBJECT
public:
    Sun(QWidget *parent,int sum);
    void add()
    {
        Sun_sum+=25;
        //qDebug()<< Sun_sum;
        update();
    }
    bool cost(int COST)
    {
        if(COST>Sun_sum)
            return false;
        Sun_sum-=COST;
        update();
        return true;
    }

    void update()
    {
        label->setText(QString::number(Sun_sum));
    }
    void produce_sun(int x,int y,bool state);
    void timely_produce_sun();
    void timerEvent(QTimerEvent *event);
signals:
    void time_is_up();
public slots:

private:
    int Sun_sum;
    QLabel * label;
    std::vector<sun> sun_vec;
    int id1;//定时器1的唯一标号
    int id2;//定时器2的唯一标号
    int unclicked_sun;
    QPixmap pix;
};

#endif // SUN_H
