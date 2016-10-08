#ifndef DIALOG_MATERIAL_LIB_H
#define DIALOG_MATERIAL_LIB_H

#include <QDialog>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include "my_treewidget_item.h"
#include "material_lib.h"
#include "my_treewidget_item.h"

class MateriaLibDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MateriaLibDialog(QWidget *parent = 0);
    ~MateriaLibDialog();
    void init();
private:
    QLabel *densityLabel;
    QLabel *emissivityLabel;
    QLineEdit *densityEdit;
    QLineEdit *emissivityEdit;
    QTreeWidget *treeWidget;
    QPushButton *saveMaterialButton;
    QTableWidget *tmpLambdaTable;
    QTableWidget *tmpCpTable;
signals:
    void dataChanged();
public slots:
    void treeItemClicked(QTreeWidgetItem* item);
    void treeItemChange(QTreeWidgetItem* item);
    void saveMaterialLibData();
};

#endif //DIALOG_MATERIAL_LIB_H
