#ifndef WIDGET_FLIGHT_H
#define WIDGET_FLIGHT_H

#include <QWidget>
#include <QTableWidget>
#include "generaleditbox.h"
#include "common.h"
#include <QTextEdit>

class FlightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlightWidget(QWidget *parent = 0);
    ~FlightWidget();
    QString getParameterData();


private:
    GeneralEditBox *timeEditBox;
    QTableWidget *tableWidget;
    QPushButton *saveButton;
    QPushButton *loadButton;

    QTextEdit *textEdit;
};

#endif // WIDGET_FLIGHT_H
