#ifndef CALL_BALL_HEAD_WIDGET_H
#define CALL_BALL_HEAD_WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include "common.h"
#include "my_usual_radiobox.h"
#include "my_combobox_group.h"
#include "generaleditbox.h"

class CalBallHeadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalBallHeadWidget(QWidget *parent = 0);
    ~CalBallHeadWidget();
    void init();

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
public slots:
    void changeWidgetByRadioBox(int index);
};

#endif // CALL_BALL_HEAD_WIDGET_H