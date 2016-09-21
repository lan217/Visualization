#include "widget_heatec.h"
#include "widget_flight.h"
#include "widget_atmosphere_model.h"
#include "widget_flat.h"
#include "widget_mulpoint.h"
#include "utils.h"
#include <QLayout>
#include <typeinfo>
#include <QDebug>
WidgetHeatec::WidgetHeatec(QWidget *parent) :
    QWidget(parent)
{
    init();
}

WidgetHeatec::~WidgetHeatec()
{

}

void WidgetHeatec::init()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QGridLayout *rightLayout = new QGridLayout();

    // left layout(init treeWidget)
    treeWidget = new QTreeWidget();
    treeWidget->clear();
    treeWidget->setHeaderHidden(true);
    connect(treeWidget, &QTreeWidget::itemClicked, this, &WidgetHeatec::treeitemClicked);

    QTreeWidgetItem *group_input = new QTreeWidgetItem(treeWidget);
    group_input->setText(0, "计算输入");
    MyQtreeWidgetItem *subItem_flight = new MyQtreeWidgetItem(group_input, 0);
    subItem_flight->setText(0, "飞行");
    MyQtreeWidgetItem *subItem_air = new MyQtreeWidgetItem(group_input, 1);
    subItem_air->setText(0, "大气模型");
    QTreeWidgetItem *group_setting = new QTreeWidgetItem(treeWidget);
    group_setting->setText(0, "计算参数设置");
    MyQtreeWidgetItem *subItem_spoint = new MyQtreeWidgetItem(group_setting);
    subItem_spoint->setText(0, "单点");
    MyQtreeWidgetItem *subItem_ballhead = new MyQtreeWidgetItem(subItem_spoint, 2);
    subItem_ballhead->setText(0, "球头");
    MyQtreeWidgetItem *subItem_cylinder = new MyQtreeWidgetItem(subItem_spoint, 3);
    subItem_cylinder->setText(0, "后掠圆柱");
    MyQtreeWidgetItem *subItem_pad = new MyQtreeWidgetItem(subItem_spoint, 4);
    subItem_pad->setText(0, "平板");
    MyQtreeWidgetItem *subItem_mpoints = new MyQtreeWidgetItem(group_setting, 5);
    subItem_mpoints->setText(0, "多点");
    treeWidget->setCurrentItem(subItem_flight);

    // right layout(init stackedWidget)
    FlightWidget *flightWidget = new FlightWidget(this);
    AtmosphereModelWidget *atmosphereModelWidget = new AtmosphereModelWidget(this);
    CalBallHeadWidget *calBallHeadWidget = new CalBallHeadWidget(this);
    CalCylinderWidget *calCylinderWidget = new CalCylinderWidget(this);
    FlatWidget *dialog5 = new FlatWidget(this);
    MulPointWidget *dialog6 = new MulPointWidget(this);
    childStackedWidget = new QStackedWidget(this);
//    childStackedWidget->resize(this->window()->width(), this->window()->height());
    childStackedWidget->addWidget(flightWidget);
    childStackedWidget->addWidget(atmosphereModelWidget);
    childStackedWidget->addWidget(calBallHeadWidget);
    childStackedWidget->addWidget(calCylinderWidget);
    childStackedWidget->addWidget(dialog5);
    childStackedWidget->addWidget(dialog6);

    createButton = new QPushButton(tr("保存"), this);
    createButton->setFixedSize(Utils::largeButtonSize());
    calButton = new QPushButton(tr("载入"), this);
    calButton->setFixedSize(Utils::largeButtonSize());


    rightLayout->addWidget(childStackedWidget, 0, 0, 1, 6);
    rightLayout->addWidget(createButton, 1, 0);
    rightLayout->addWidget(calButton, 1, 1);

    mainLayout->addWidget(treeWidget);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(treeWidget,1);
    mainLayout->setStretchFactor(rightLayout,4);

    this->setLayout(mainLayout);
}


void WidgetHeatec::treeitemClicked(QTreeWidgetItem* item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL || (myItem->Index() < 0 || myItem->Index() >= childStackedWidget->count()))
        return;

    childStackedWidget->setCurrentIndex(myItem->Index());

    if (myItem->Index() == 0 || myItem->Index() == 1) {
        createButton->setVisible(true);
        createButton->setText(tr("保存"));
        calButton->setVisible(true);
        calButton->setText(tr("载入"));
    } else if (myItem->Index() == 1) {
        createButton->setVisible(false);
        calButton->setVisible(false);
    } else {
        createButton->setVisible(true);
        createButton->setText(tr("生成计算文件"));
        calButton->setVisible(true);
        calButton->setText(tr("开始计算"));
    }

}


