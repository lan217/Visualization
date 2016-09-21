#include "widget_atmosphere_model.h"
#include "dialog_table.h"
#include <QDebug>
AtmosphereModelWidget::AtmosphereModelWidget(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout();
    QStringList radioLabels;
    radioLabels << "1. 1962年u.s. standard atmosphere大气参数表" << "2. 风洞流场参数"
                << "3. 输入大气参数"
                << "4. 1963 patrick air force base atmosphere大气参数表"
                << "5. 1971 vandenberg reference atmosphere大气参数表"
                << "6. 1973 vandenberg hot day atmosphere大气参数表"
                << "7. 1973 vandenberg cold day atmosphere大气参数表"
                << "8. 1971 kennedy hot day atmosphere大气参数表"
                << "9. 1971 kennedy cold day atmosphere大气参数表"
                << "10. 1976 u.s. standard atmosphere大气参数表";
    atmosphereRadioBox = new MyUsualRadioBox("", radioLabels, MyUsualRadioBox::Vertical);
    atmosphereRadioBox->setRadioIndex(0);

    loadWindButton = new QPushButton(tr("载入风动参数"));
    loadWindButton->setObjectName("载入大气参数   ");
    loadWindButton->setEnabled(false);
//    loadWindButton->setFixedWidth(Utils::largeButtonSize().width() * 0.5);
    loadAtmosphereButton = new QPushButton(tr("load atmospheric data parameter"));
    loadAtmosphereButton->setObjectName("loadAtmosphereButton");
    loadAtmosphereButton->setEnabled(false);
//    loadAtmosphereButton->setFixedWidth(Utils::largeButtonSize().width() * 0.5);
    connect(loadWindButton, &QPushButton::clicked, this, &AtmosphereModelWidget::showLoadDialog);
    connect(loadAtmosphereButton, &QPushButton::clicked, this, &AtmosphereModelWidget::showLoadDialog);

    atmosphereRadioBox->insertWidgetWithButtonIndex(1, loadWindButton);
    atmosphereRadioBox->insertWidgetWithButtonIndex(2, loadAtmosphereButton);
    connect(atmosphereRadioBox, &MyUsualRadioBox::radioToggle, this, &AtmosphereModelWidget::changeButtonEnable);

    mainLayout->addWidget(atmosphereRadioBox, 0, 0);

    mainLayout->setColumnStretch(0, 2);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setRowStretch(0, 2);
    mainLayout->setRowStretch(1, 1);
    this->setLayout(mainLayout);
}

AtmosphereModelWidget::~AtmosphereModelWidget()
{

}

void AtmosphereModelWidget::showLoadDialog()
{
    QPushButton *button= qobject_cast<QPushButton*>(sender());
    QStringList headerLabels;

    if (button->objectName() == "loadWindButton") {
        headerLabels << "时间" << "静温" << "静压";
        TableDialog *dialog = new TableDialog("载入风洞", headerLabels);
        dialog->show();
    } else if (button->objectName() == "loadAtmosphereButton") {
        headerLabels << "高度" << "静温" << "静压";
        TableDialog *dialog = new TableDialog("载入大气模型", headerLabels);
        dialog->show();
    }
}

void AtmosphereModelWidget::changeButtonEnable(int index)
{
    qDebug() << index;
    switch (index) {
    case 1:
        loadWindButton->setEnabled(true);
        loadAtmosphereButton->setEnabled(false);
        break;
    case 2:
        loadWindButton->setEnabled(false);
        loadAtmosphereButton->setEnabled(true);
        break;
    default:
        loadWindButton->setEnabled(false);
        loadAtmosphereButton->setEnabled(false);
        break;
    }
}
