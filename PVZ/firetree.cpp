#include "firetree.h"

FireTree::FireTree(QWidget *parent,int x,int y) : Plant(parent,x,y,":/FireTree.gif")
{
    label->resize(80,100);
    HP=150;
    power=0;
    FPS_gap=100000;
}
void FireTree::make_action()
{
    //do nothing
}
