#ifndef WIDGET_HEATEC_H
#define WIDGET_HEATEC_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QStackedWidget>
#include "mywidget/my_treewidget_item.h"
#include "widget_cal_ball_head.h"
#include "widget_cal_cylinder.h"
#include "widget_flight.h"
#include "widget_atmosphere_model.h"
#include "widget_flat.h"
#include "widget_mulpoint.h"

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
    FlightWidget *flightWidget;
    AtmosphereModelWidget *atmosphereModelWidget;
    CalBallHeadWidget *calBallHeadWidget;
    CalCylinderWidget *calCylinderWidget;
    FlatWidget *flatWidget;
    MulPointWidget *mulPointWidget;
    QPushButton *createButton;
    QPushButton *calButton;

public slots:

    void treeItemClicked(QTreeWidgetItem* item);
    void saveParameterData();
};

#endif // WIDGET_HEATEC_H
