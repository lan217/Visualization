#include "widget_cal_ball_head.h"
#include <QGroupBox>
#include <QDebug>
#include <QSpacerItem>
CalBallHeadWidget::CalBallHeadWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

CalBallHeadWidget::~CalBallHeadWidget()
{

}

void CalBallHeadWidget::init()
{
    // init radioBoxs
    QStringList radioLabels;
    radioLabels << tr("Fay-Riddle") << tr("Lees-Deta");
    formulaRadio = new MyUsualRadioBox(tr("公式选择"), radioLabels);
    formulaRadio->setObjectName("formulaRadio");
    connect(formulaRadio, &MyUsualRadioBox::radioToggle, this, &CalBallHeadWidget::changeWidgetByRadioBox);
    radioLabels.clear();
    radioLabels << tr("是") << tr("否");
    thinRadio = new MyUsualRadioBox(tr("是否稀薄"), radioLabels);
    twoDimensionRadio = new MyUsualRadioBox(tr("是否二维"), radioLabels);
    radioLabels.clear();
    radioLabels << tr("程序自动计算") << tr("给定数值");
    lewisRadio = new MyUsualRadioBox(tr("Lewis数计算方法"), radioLabels);
    lewisRadio->setObjectName("lewisRadio");
    lewisEdit = new QLineEdit();
    lewisRadio->insertWidgetWithButtonIndex(1, lewisEdit);
    connect(lewisRadio, &MyUsualRadioBox::radioToggle, this, &CalBallHeadWidget::changeWidgetByRadioBox);
    radioLabels.clear();
    radioLabels << tr("前一时刻") << tr("定壁温");
    temperatureRadio = new MyUsualRadioBox(tr("壁温"), radioLabels);
    temperatureRadio->setObjectName("temperatureRadio");
    wallTemperatureEdit = new QLineEdit();
    temperatureRadio->insertWidgetWithButtonIndex(1, wallTemperatureEdit);
    connect(temperatureRadio, &MyUsualRadioBox::radioToggle, this, &CalBallHeadWidget::changeWidgetByRadioBox);

    amplificationBox = new AmplificationFactorBox();
    transformRadioBox = new TransformBox();
    QStringList labels;
    labels << "半径:" << "壁面倾角:"<<"发射率:";
    editBox = new GeneralEditBox("", labels, 1, 3, this);
    editBox->setFixedHeight(Utils::windowSize().height() * 0.1);

    // mainLayout
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(formulaRadio, 0, 0);
    mainLayout->addWidget(editBox, 1, 0, 1, 3);
    mainLayout->addWidget(amplificationBox, 2, 0, 1, 3);
    mainLayout->addWidget(temperatureRadio, 3, 0);
    mainLayout->addWidget(thinRadio, 3, 1);
    mainLayout->addWidget(twoDimensionRadio, 3, 2);
    mainLayout->addWidget(lewisRadio, 3, 3);
    mainLayout->addWidget(transformRadioBox, 4, 0, 1, 3);
    mainLayout->setRowStretch(5, 1);
    mainLayout->setColumnStretch(0, 3);
    mainLayout->setColumnStretch(1, 2);
    mainLayout->setColumnStretch(2, 2);
    mainLayout->setColumnStretch(3, 3);
    mainLayout->setSpacing(20);
//    this->setStyleSheet("QGroupBox{margin-bottom:30px}");

    this->setLayout(mainLayout);
}


void CalBallHeadWidget::changeWidgetByRadioBox(int index)
{
    MyUsualRadioBox *radioBox = qobject_cast<MyUsualRadioBox*>(sender());

    if (radioBox->objectName() == "formulaRadio") {
        QLineEdit *edit = editBox->getLineEdit(0, 0);
        if (index == 0) {
            if (edit) {
                edit->setText("90");
                edit->setDisabled(true);
            }
            transformRadioBox->setTransformIndex(8);
            transformRadioBox->disable();
        } else {
            if (edit) {
                edit->setText("");
                edit->setEnabled(true);
            }
            transformRadioBox->enable();
        }
    } else if (radioBox->objectName() == "lewisRadio") {
        if (index == 0) {
            lewisEdit->setText("");
            lewisEdit->setDisabled(true);
        } else {
            lewisEdit->setEnabled(true);
        }
    } else if (radioBox->objectName() == "temperatureRadio") {
        if (index == 0) {
            wallTemperatureEdit->setText("");
            wallTemperatureEdit->setDisabled(true);
        } else {
            wallTemperatureEdit->setEnabled(true);
        }
    }
}
