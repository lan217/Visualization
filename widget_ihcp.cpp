#include "widget_ihcp.h"
#include "my_treewidget_item.h"
#include "widget_ihcp_1.h"
#include "widget_ihcp_2.h"
#include <QLabel>
#include <QTreeWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>

WidgetIhcp::WidgetIhcp(QWidget *parent) : QWidget(parent)
{
    init();
}

WidgetIhcp::~WidgetIhcp()
{

}

void WidgetIhcp::init()
{
    //init all Qmembers
    treeWidget = new QTreeWidget();
    treeWidget->clear();
    treeWidget->setHeaderHidden(true);
    connect(treeWidget, &QTreeWidget::itemClicked, this, &WidgetIhcp::treeItemClicked);

    QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(treeWidget);
    treeWidgetItem->setText(0, tr("界面"));
    MyQtreeWidgetItem *firInterface = new MyQtreeWidgetItem(treeWidgetItem, 0);
    firInterface->setText(0, tr("打开热辨识计算"));
    MyQtreeWidgetItem *twoInterface = new MyQtreeWidgetItem(treeWidgetItem, 1);
    twoInterface->setText(0, tr("打开热计算窗口"));

    stackedWidget = new QStackedWidget(this);
    Widget_ihcp_1 *widgetOne = new Widget_ihcp_1(this);
    Widget_ihcp_2 *widgetTwo = new Widget_ihcp_2(this);
    stackedWidget->addWidget(widgetOne);
    stackedWidget->addWidget(widgetTwo);

    //setting all layout
    QHBoxLayout *mainLayout = new QHBoxLayout();

    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setStretchFactor(treeWidget, 1);
    mainLayout->setStretchFactor(stackedWidget, 4);

    this->setLayout(mainLayout);
}

void WidgetIhcp::treeItemClicked(QTreeWidgetItem *item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL || (myItem->Index() < 0 || myItem->Index() >= stackedWidget->count()))
        return;
    stackedWidget->setCurrentIndex(myItem->Index());
}
