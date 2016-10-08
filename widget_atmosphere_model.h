#ifndef WIDGET_ATMOSPHERE_MODEL_H
#define WIDGET_ATMOSPHERE_MODEL_H

#include <QWidget>
#include <QTableWidget>
#include "common.h"
#include "my_usual_radiobox.h"


class AtmosphereModelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AtmosphereModelWidget(QWidget *parent = 0);
    ~AtmosphereModelWidget();
    QString getParameterData();

private:
    MyUsualRadioBox *atmosphereRadioBox;
    QPushButton *loadWindButton;
    QPushButton *loadAtmosphereButton;
    QTableWidget *inputTable;
public slots:
    void showLoadDialog();
    void changeButtonEnable(int index);


};

#endif // WIDGET_ATMOSPHERE_MODEL_H
