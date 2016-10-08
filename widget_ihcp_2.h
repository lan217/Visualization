#ifndef WIDGET_IHCP_2_H
#define WIDGET_IHCP_2_H
#include "generaleditbox.h"
#include "my_usual_radiobox.h"
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "common.h"

class Widget_ihcp_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_ihcp_2(QWidget *parent = 0);
    ~Widget_ihcp_2();

private:
    GeneralEditBox *editBox;
    GeneralEditBox *editBox2;
    MyUsualRadioBox *radioBox1;
    MyUsualRadioBox *radioBox2;


};

#endif // WIDGET_IHCP_2_H
