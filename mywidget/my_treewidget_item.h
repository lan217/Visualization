#ifndef MY_TREEWIDGET_ITEM_H
#define MY_TREEWIDGET_ITEM_H

#include <QTreeWidgetItem>

/**
 * @brief to know which item is clicked briefly
 */
class MyQtreeWidgetItem : public QObject ,public QTreeWidgetItem
{
    Q_OBJECT
public:
    explicit MyQtreeWidgetItem(QTreeWidgetItem *parent = 0, int index = -1);
    explicit MyQtreeWidgetItem(MyQtreeWidgetItem *parent, int index = -1);
    ~MyQtreeWidgetItem();
    void init();
    void setIndex(int index);
    int Index();

private:
    int index;
signals:

public slots:
};
#endif // MY_TREEWIDGET_ITEM_H
