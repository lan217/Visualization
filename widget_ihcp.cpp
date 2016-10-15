#include "widget_ihcp.h"
#include "mywidget/my_treewidget_item.h"
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
    treeWidget->expandAll();
    treeWidget->setItemsExpandable(false);

    stackedWidget = new QStackedWidget(this);
    Widget_ihcp_1 *widgetOne = new Widget_ihcp_1(this);
    Widget_ihcp_2 *widgetTwo = new Widget_ihcp_2(this);
    stackedWidget->addWidget(widgetOne);
    stackedWidget->addWidget(widgetTwo);

    createButton = new QPushButton(tr("载入"), this);
    createButton->setFixedSize(Utils::largeButtonSize());
    calButton = new QPushButton(tr("保存"), this);
    calButton->setFixedSize(Utils::largeButtonSize());

    //setting all layout
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QGridLayout *rightLayout = new QGridLayout();
    rightLayout->addWidget(stackedWidget, 0, 0, 1, 6);
    rightLayout->addWidget(createButton, 1, 0);
    rightLayout->addWidget(calButton, 1, 1);

    mainLayout->addWidget(treeWidget);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(treeWidget, 1);
    mainLayout->setStretchFactor(rightLayout, 4);

    this->setLayout(mainLayout);
}

void WidgetIhcp::treeItemClicked(QTreeWidgetItem *item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL || (myItem->Index() < 0 || myItem->Index() >= stackedWidget->count()))
        return;
    stackedWidget->setCurrentIndex(myItem->Index());
}
