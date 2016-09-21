#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include <QWidget>
#include "widget_heatec.h"
#include "widget_hcd.h"
#include "widget_ihcp.h"
#include "widget_wind_tunnel.h"
#include "widget_chooset.h"

class WidgetMain : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetMain(QWidget *parent = 0);

    ~ WidgetMain();
    void init();

private:
    QTabWidget *tabWidget;
    WidgetHeatec *heatecTabWidget;
    WidgetHcd *hcdTabWidget;
    WidgetIhcp *ihcpTabWidget;
    WidgetWindTunnel *tunnelTabWidget;
    WidgetChoose *chooseWidget;
signals:

public slots:
};

#endif // WIDGET_MAIN_H
