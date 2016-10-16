#include "mywidget/my_treewidget_item.h"
MyQtreeWidgetItem::MyQtreeWidgetItem(QTreeWidgetItem *parent, int index) :
    QTreeWidgetItem(parent)
{
    setIndex(index);
    init();
}

MyQtreeWidgetItem::MyQtreeWidgetItem(MyQtreeWidgetItem *parent, int index) :
    QTreeWidgetItem(parent)
{
    setIndex(index);
    init();
}

MyQtreeWidgetItem::~MyQtreeWidgetItem()
{

}

void MyQtreeWidgetItem::init()
{

}

void MyQtreeWidgetItem::setIndex(int index)
{
    this->index = index;
}

int MyQtreeWidgetItem::Index()
{
    return this->index;
}
