#ifndef SPIKEROCK_H
#define SPIKEROCK_H

#include <QWidget>
#include"plant.h"
#include"grass.h"
class SpikeRock : public Plant
{
    Q_OBJECT
public:
    explicit SpikeRock(QWidget *parent,int X,int Y);
    void make_action();
signals:

public slots:
};

#endif // SPIKEROCK_H
