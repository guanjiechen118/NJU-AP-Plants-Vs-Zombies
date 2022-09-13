#ifndef GRASS_H
#define GRASS_H
#define x_base 300
#define y_base 180
#define x_gap 92
#define y_gap 100

#include <QWidget>
#include <plant.h>
#include"sunflower.h"
#include"nutwall.h"
#include"peashooter.h"
#include"spikerock.h"
#include"repeater.h"
#include"cherrybomb.h"
#include<QPair>
#include<QLinkedList>
#include"zombies.h"
#include"firetree.h"
#include"starfruit.h"
enum Plants{_NONE,_SunFlower,_NutWall,_PeaShooter,_SpikeRock,_Repeater,_FireTree,_CherryBomb,_SHOVEL,_StarFruit};
class zombies;
class grass : public QWidget
{
    Q_OBJECT
public:
    friend class zombies;
    static QPair<int,int> Locate(int x,int y);
    explicit grass(QWidget *parent,int line,int cross,Sun* SUN);
    bool Is_occupied()
    {return occupied;}
    bool Is_eatable()
    {return eatable;}
    bool Is_rehance()
    {
        return rehance;
    }
    static bool line_has_zom(int);
    bool In(int x,int y);
    bool Anchor(Plants type);
    void anchor_zombie(zombies* newzom);
    void delete_zombie(zombies* newzom);
    bool hit_first(int power);
    bool hit_all(int power);
    bool hit_all_F(int power);
    bool hit_all_G(int power);
    int firs_zom_x();
    bool has_zom();
signals:
    void cleared();
public slots:
private:
    Plant* plant;
    bool occupied;
    bool eatable;
    bool rehance;
    int _x;
    int _y;
    int _line;
    int _cross;
    Sun* sun;
    QLinkedList<zombies*> zoms;
};

#endif // GRASS_H
