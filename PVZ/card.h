#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include"grass.h"
#include"QPushButton"
class playSence;
class Card : public QWidget
{
    Q_OBJECT
    friend class playSence;
public:
    Card(QWidget *parent = nullptr);
    bool AddCard(Plants PlanType,int cost,QString path);
    bool AddTool(Plants toolTYpe,QString path);
signals:
    void disabled();
public slots:

private:
    int card_num;
    Plants selected_one;
    int index;
    QPushButton* buttons[20];
    int percent[20];
    QLabel* percent_label[20];
    QTimer* timer;
    int cont;
    int fresh_gap;
};
#endif
