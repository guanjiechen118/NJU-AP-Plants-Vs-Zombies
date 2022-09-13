#ifndef PLANT_H
#define PLANT_H
#define damage 10;
#include <QWidget>
#include<QTimer>
#include<QLabel>
#include<QMovie>
#include<QString>
#define x_base 300
#define y_base 180
#define x_gap 92
#define y_gap 100
class grass;
class zombies;
extern int FPS;
class Plant : public QWidget
{
    Q_OBJECT
public:
    friend class grass;
    friend class zombies;
    explicit Plant(QWidget *parent,int X,int Y,QString str);
    void eaten()
    {
        HP-=damage;
    }
signals:
    void died();
    void update();
public slots:
    virtual void make_action()=0;
protected:
    int HP;
    int power;
    int FPS_gap;
    int line;
    int cross;
    int _x;
    int _y;
    int cont;
    QTimer* timer;
    QLabel* label;
    QMovie* movie;
    QString str;
};
#endif // PLANT_H
