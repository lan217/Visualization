#ifndef WIDGET_FLIGHT_H
#define WIDGET_FLIGHT_H

#include <QWidget>
#include <QTableWidget>
#include "generaleditbox.h"
#include "common.h"

class FlightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlightWidget(QWidget *parent = 0);
    ~FlightWidget();

private:
    GeneralEditBox *timeEditBox;
    QTableWidget *tableWidget;
    QPushButton *saveButton;
    QPushButton *loadButton;

};

#endif // WIDGET_FLIGHT_H
