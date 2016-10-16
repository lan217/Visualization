#ifndef CALL_BALL_HEAD_WIDGET_H
#define CALL_BALL_HEAD_WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include "common.h"
#include "mywidget/my_usual_radiobox.h"
#include "mywidget/my_combobox_group.h"
#include "mywidget/generaleditbox.h"

class CalBallHeadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalBallHeadWidget(QWidget *parent = 0);
    ~CalBallHeadWidget();
    void init();
    QString getParameterData();

private:
    QLineEdit *lewisEdit;
    QLineEdit *wallTemperatureEdit;
    GeneralEditBox *editBox;
    AmplificationFactorBox *amplificationBox;
    TransformBox *transformRadioBox;
    MyUsualRadioBox *formulaRadio;
    MyUsualRadioBox *thinRadio;
    MyUsualRadioBox *twoDimensionRadio;
    MyUsualRadioBox *lewisRadio;
    MyUsualRadioBox *temperatureRadio;
    MyUsualRadioBox *calPosRadio;

public slots:
    void changeWidgetByRadioBox(int index);
};

#endif // CALL_BALL_HEAD_WIDGET_H
