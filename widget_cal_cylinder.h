#ifndef CAL_CYLINDER_H
#define CAL_CYLINDER_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include "common.h"
#include "my_usual_radiobox.h"
#include "my_combobox_group.h"
#include "generaleditbox.h"

class CalCylinderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalCylinderWidget(QWidget *parent = 0);
    ~CalCylinderWidget();
    void init();

private:
    QLineEdit *lewisEdit;
    GeneralEditBox *editBox;
    AmplificationFactorBox *amplificationBox;
    TransformBox *transformRadioBox;
    MyUsualRadioBox *formulaRadio;
    MyUsualRadioBox *thinRadio;
    MyUsualRadioBox *lewisRadio;
    MyUsualRadioBox *planeRadio;
    MyUsualRadioBox *rudderRadio;
public slots:
    void changeWidgetByRadioBox(int index);
};

#endif // CAL_CYLINDER_H
