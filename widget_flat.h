#ifndef WIDGET_FLAT_H
#define WIDGET_FLAT_H
#include "my_usual_radiobox.h"
#include "generaleditbox.h"
#include <QDialog>
#include <QLabel>
#include <QTableWidget>
#include <QComboBox>
#include "my_combobox_group.h"
#include "common.h"

class FlatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlatWidget(QWidget *parent = 0);
    ~FlatWidget();
private:
    MyUsualRadioBox *radioBox;
    MyUsualRadioBox *radioBox2;
    MyUsualRadioBox *radioBox3;
    MyUsualRadioBox *radioBox4;
    MyUsualRadioBox *thinRadio;

    AmplificationFactorBox *amplificationBox;
    TransformBox *transformRadioBox;
    QLineEdit *wallTemperatureEdit;
    QLineEdit *distanceEdit;

    QTableWidget *tableWidget;
    QComboBox *combomBox1;
    QComboBox *combomBox2;

    GeneralEditBox *editBox;
public slots:
    void changeWidgetByRadioBox(int index);
};

#endif // WIDGET_FLAT_H
