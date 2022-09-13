#include "playsence.h"
#include <QApplication>
int FPS = 1000/30;
grass* grass_arry[5][20];
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    playSence w;
    w.show();

    return a.exec();
}
