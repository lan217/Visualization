#ifndef WIDGET_IHCP_H
#define WIDGET_IHCP_H

#include <QWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include "widget_ihcp_1.h"
#include "widget_ihcp_2.h"

class WidgetIhcp : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetIhcp(QWidget *parent = 0);
    ~WidgetIhcp();
    void init();

private:
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    Widget_ihcp_1 *widgetIchp1;
    Widget_ihcp_2 *widgetIchp2;

signals:

public slots:
    void treeItemClicked(QTreeWidgetItem* item);
};

#endif // WIDGET_IHCP_H
