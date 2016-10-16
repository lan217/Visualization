#include <QLayout>

#include "widget_main.h"
#include "utils/utils.h"
#include <QDebug>

WidgetMain::WidgetMain(QWidget *parent) :
    QWidget(parent)
{
    init();
}

WidgetMain::~WidgetMain()
{

}

void WidgetMain::init()
{

    this->resize(Utils::windowSize());
    qDebug("%d  %d", this->width(), this->height());

    this->setStyleSheet("QGroupBox#topGroupBox{"
                        "font-weight: bold;}"
                        "QLineEdit{"
                        "max-width: " + QString::number(Utils::lineEditWidth()) + "px;"
                        "}"
                        "QLineEdit#dirEdit{"
                        "max-width: " + QString::number(Utils::windowSize().width()) + "px;"
                        "}"
                        "*{font-size :" + QString::number((int)(Utils::windowSize().height() * 0.024)) + "px;}");
//                        "QTableWidget{"
//                        "font-size: 20px;"
//                        "}");
    QVBoxLayout *mainLayout = new QVBoxLayout();
    tabWidget = new QTabWidget(this);

    heatecTabWidget = new WidgetHeatec(this);
    hcdTabWidget = new WidgetHcd(this);
    ihcpTabWidget = new WidgetIhcp(this);
    tunnelTabWidget = new WidgetWindTunnel(this);
    chooseWidget = new WidgetChoose(this);

    tabWidget->addTab(heatecTabWidget, "热环境");
    tabWidget->addTab(hcdTabWidget, "热传导");
    tabWidget->addTab(ihcpTabWidget, "热辨识");
    tabWidget->addTab(tunnelTabWidget, "电弧风洞");
    tabWidget->addTab(chooseWidget, "遴选");

    mainLayout->addWidget(tabWidget);
    this->setWindowTitle(tr("气动热快速预测软件"));
    this->setLayout(mainLayout);


}
