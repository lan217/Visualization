#ifndef WIDGET_HEATEC_H
#define WIDGET_HEATEC_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QStackedWidget>
#include "my_treewidget_item.h"
#include "widget_cal_ball_head.h"
#include "widget_cal_cylinder.h"

class WidgetHeatec : public QWidget
{
    Q_OBJECT
    
public:
    explicit WidgetHeatec(QWidget *parent = 0);
    ~WidgetHeatec();
    void init();


private:
    QTreeWidget *treeWidget;
    QStackedWidget *childStackedWidget;
    CalBallHeadWidget *calBallHeadWidget;
    CalCylinderWidget *calCylinderWidget;
    QPushButton *createButton;
    QPushButton *calButton;

public slots:

    void treeitemClicked(QTreeWidgetItem* item);

};

#endif // WIDGET_HEATEC_H
