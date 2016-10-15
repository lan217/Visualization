#include "mywidget/my_usual_radiobox.h"
#include <QLayout>

/**
 * @brief MyUsualRadioBox::MyUsualRadioBox
 * @param groupTitle
 * @param titles radioButtons' titles
 * @param parent
 */
MyUsualRadioBox::MyUsualRadioBox(const QString &groupTitle, const QStringList &titles, Orientation orien, QWidget *parent) :
    QGroupBox(groupTitle, parent),
    orien(orien)
{
    this->numRadio = titles.count();

    radioGroup = new QButtonGroup(this);

    QGridLayout *buttonLayout = new QGridLayout();

    for (int i = 0;i < this->numRadio;i++) {
        QRadioButton *newRadioButton = new QRadioButton(titles.at(i), this);
        radioGroup->addButton(newRadioButton);
        radioGroup->setId(newRadioButton, i);

        if (i == 0) {
            newRadioButton->setChecked(true);
        }

        QHBoxLayout *extraLayout = new QHBoxLayout();
        extraLayout->setObjectName("extraLayout" + QString::number(i));
        if (orien == Horizontal) {
            buttonLayout->addWidget(newRadioButton, 0, 2 * i);
            buttonLayout->addLayout(extraLayout, 0, 2 * i + 1);
        } else if (orien == Vertical) {
            buttonLayout->addWidget(newRadioButton, i, 0);
            buttonLayout->addLayout(extraLayout, i, 1);
        } else {
            continue;
        }

        connect(newRadioButton, &QRadioButton::toggled, this, &MyUsualRadioBox::radioSlot);
    }


    this->setLayout(buttonLayout);
    if (orien == Horizontal) {
        this->setFixedHeight(Utils::windowSize().height() * 0.1);
    }

}

void MyUsualRadioBox::radioSlot()
{
    emit radioToggle(radioIndex());
}

/**
 * @brief set which radioButton is checked
 * @param index
 */
void MyUsualRadioBox::setRadioIndex(int index)
{
    if (index == -1) {
        for (int i = 0;i < this->numRadio;i++) {
            if (radioGroup->button(i)) {
                radioGroup->button(i)->setCheckable(false);
            }
        }

    } else {
        if (radioGroup->button(index)) {
            radioGroup->button(index)->setChecked(true);
        }
    }

}

/**
 * @brief get which radioButton is checked
 * @return
 */
int MyUsualRadioBox::radioIndex()
{
    for (int i = 0;i < this->numRadio;i++) {
        if (radioGroup->button(i) && radioGroup->button(i)->isChecked()) {
            return i;
        }
    }

    return -1;
}

void MyUsualRadioBox::enable()
{
    for (int i = 0;i < this->numRadio;i++) {
        if (radioGroup->button(i)) {
            radioGroup->button(i)->setEnabled(true);
            radioGroup->button(i)->setCheckable(true);
        }
    }
}

void MyUsualRadioBox::disable()
{
    for (int i = 0;i < this->numRadio;i++) {
        if (radioGroup->button(i)) {
            radioGroup->button(i)->setDisabled(true);
        }
    }
}

/**
 * @brief insert widget behind the radioButton
 * @param index
 * @param widget
 */
void MyUsualRadioBox::insertWidgetWithButtonIndex(int index, QWidget *widget)
{
    if (radioGroup->button(index)) {
        QHBoxLayout *extraLayout = this->layout()->findChild<QHBoxLayout *>("extraLayout" + QString::number(index));

        if (extraLayout) {
            extraLayout->addWidget(widget);
        }
    }
}

void MyUsualRadioBox::insertWithButtonIndexEnd(int index)
{
    if (radioGroup->button(index)) {
        QHBoxLayout *extraLayout = this->layout()->findChild<QHBoxLayout *>("extraLayout" + QString::number(index));

        if (extraLayout) {
            extraLayout->addStretch(1);
        }
    }

}
