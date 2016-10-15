#include "dialog_material_lib.h"
#include <QLayout>
#include <QHeaderView>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

MateriaLibDialog::MateriaLibDialog(QWidget *parent) :
    QDialog(parent)
{
    init();
}

MateriaLibDialog::~MateriaLibDialog()
{

}

void MateriaLibDialog::init()
{
    addAction = new QAction(tr("添加材料"), this);
    addMenu = new QMenu(this);
    addMenu->addAction(addAction);
    delAction = new QAction(tr("删除材料"), this);
    delMenu = new QMenu(this);
    delMenu->addAction(delAction);
    connect(addMenu, &QMenu::triggered, this, &MateriaLibDialog::onAddMenuTriggered);
    connect(delMenu, &QMenu::triggered, this, &MateriaLibDialog::onDelMenuTriggered);


    QHBoxLayout *mainLayout = new QHBoxLayout();
    QGridLayout *leftLayout = new QGridLayout();
    QGridLayout *rightLayout = new QGridLayout();

    treeWidget = new QTreeWidget();
    treeWidget->clear();
    treeWidget->setHeaderHidden(true);
    connect(treeWidget, &QTreeWidget::itemClicked, this, &MateriaLibDialog::treeItemClicked);
    connect(treeWidget, &QTreeWidget::itemChanged, this, &MateriaLibDialog::treeItemChange);

    group_metal = new QTreeWidgetItem(treeWidget);
    group_metal->setText(0, "金属材料");
    group_metal->setFlags(Qt::ItemIsEnabled);
    group_setting = new QTreeWidgetItem(treeWidget);
    group_setting->setText(0, "非金属材料");
    group_setting->setFlags(Qt::ItemIsEnabled);

    leftLayout->addWidget(treeWidget, 0, 0, 1, 2);

    densityLabel = new QLabel(tr("密度:"));
    emissivityLabel = new QLabel(tr("辐射系数:"));
    densityEdit = new QLineEdit();
    emissivityEdit = new QLineEdit();
    saveMaterialButton = new QPushButton(tr("保存材料"));
    connect(saveMaterialButton, &QPushButton::clicked, this, &MateriaLibDialog::saveMaterialLibData);

    tmpLambdaTable = new QTableWidget(2,15);
    tmpLambdaTable->horizontalHeader()->setVisible(false);
    QStringList headerLabels;
    headerLabels << tr("温度") << tr("λ");
    tmpLambdaTable->setVerticalHeaderLabels(headerLabels);
    tmpLambdaTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tmpLambdaTable->setFixedHeight(80);
    for (int i = 0;i < tmpLambdaTable->columnCount();i++) {
        tmpLambdaTable->setColumnWidth(i, 50);
    }


    tmpCpTable = new QTableWidget(2,15);
    tmpCpTable->horizontalHeader()->setVisible(false);
    headerLabels.clear();
    headerLabels << tr("温度") << tr("cp");
    tmpCpTable->setVerticalHeaderLabels(headerLabels);
    tmpCpTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tmpCpTable->setFixedHeight(80);
    for (int i = 0;i < tmpCpTable->columnCount();i++) {
        tmpCpTable->setColumnWidth(i, 50);
    }

    QMap<int,MaterialLib::Material> map = MaterialLib::getInstance()->getMaterialNameList();

    for(QMap<int,MaterialLib::Material>::iterator it = map.begin();it != map.end();it++){
        MaterialLib::Material material = it.value();
        MyQtreeWidgetItem *item;

        if (material.type == 1) {
            item = new MyQtreeWidgetItem(group_metal, it.key());
        } else {
            item = new MyQtreeWidgetItem(group_setting, it.key());
        }

        item->setText(0, material.materialName);
        item->setFlags(Qt::ItemIsEditable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        if (it == map.begin()) {
            treeWidget->setCurrentItem(item);
            treeItemClicked(item);
        }
    }

    treeWidget->expandAll();

    rightLayout->addWidget(densityLabel, 0, 0);
    rightLayout->addWidget(densityEdit, 0, 1);
    rightLayout->addWidget(emissivityLabel, 0, 2);
    rightLayout->addWidget(emissivityEdit, 0, 3);
    rightLayout->addWidget(saveMaterialButton, 0, 4);
    rightLayout->addWidget(tmpLambdaTable, 1, 0, 1, 5);
    rightLayout->addWidget(tmpCpTable, 2, 0, 1, 5);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(leftLayout,1);
    mainLayout->setStretchFactor(rightLayout,3);

    this->setLayout(mainLayout);
    this->setWindowTitle(tr("材料库"));
}

void MateriaLibDialog::treeItemClicked(QTreeWidgetItem* item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL)
        return;

    tmpLambdaTable->clearContents();
    tmpCpTable->clearContents();
    MaterialLib::Material* material = MaterialLib::getInstance()->getMaterial(myItem->Index());

    if (material) {
        densityEdit->setText(QString::number(material->destiny));
        emissivityEdit->setText(QString::number(material->emissivity));
        int col = 0;

        QMap<float,float> map = MaterialLib::getInstance()->getTmpLambdaMap(myItem->Index());
        for (QMap<float,float>::iterator it = map.begin();it != map.end();it++) {
            if (tmpCpTable->item(0, col)) {
                tmpCpTable->item(0, col)->setText(QString::number(it.key()));
            } else {
                tmpCpTable->setItem(0, col, new QTableWidgetItem(QString::number(it.key())));
            }
            if (tmpCpTable->item(1, col)) {
                tmpCpTable->item(1, col)->setText(QString::number(it.value()));
            } else {
                tmpCpTable->setItem(1, col, new QTableWidgetItem(QString::number(it.value())));
            }
            col++;
        }
        col = 0;
        map = MaterialLib::getInstance()->getTmpLambdaMap(myItem->Index());
        for (QMap<float,float>::iterator it = map.begin();it != map.end();it++) {
            if (tmpLambdaTable->item(0, col)) {
                tmpLambdaTable->item(0, col)->setText(QString::number(it.key()));
            } else {
                tmpLambdaTable->setItem(0, col, new QTableWidgetItem(QString::number(it.key())));
            }
            if (tmpLambdaTable->item(1, col)) {
                tmpLambdaTable->item(1, col)->setText(QString::number(it.value()));
            } else {
                tmpLambdaTable->setItem(1, col, new QTableWidgetItem(QString::number(it.value())));
            }
            col++;
        }
    }
}

void MateriaLibDialog::treeItemChange(QTreeWidgetItem* item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL)
        return;

    QString name = myItem->text(0);
    if (!MaterialLib::getInstance()->updateMaterialName(myItem->Index(), name)) {
        MaterialLib::Material* material = MaterialLib::getInstance()->getMaterial(myItem->Index());
        if (material) {
            myItem->setText(0, material->materialName);
        }
    } else {
        emit dataChanged();
    }

}

void MateriaLibDialog::contextMenuEvent(QContextMenuEvent *event)
{
    QTreeWidgetItem *item = treeWidget->currentItem();

    if (item != NULL && item->parent() == NULL) {
        addMenu->exec(QCursor::pos());
    } else if (item != NULL) {
        delMenu->exec(QCursor::pos());
    }

}

void MateriaLibDialog::onAddMenuTriggered(QAction *action)
{
    QTreeWidgetItem *item = treeWidget->currentItem();

    if (item != NULL && item->parent() == NULL) {
        int topItemindex = treeWidget->indexOfTopLevelItem(item);
        qDebug() << topItemindex;
        if (topItemindex == 0) {
            MyQtreeWidgetItem *metal;
            metal = new MyQtreeWidgetItem(group_metal);
            metal->setText(0, "eee");
            treeWidget->setCurrentItem(metal);

        }
    }
}

void MateriaLibDialog::onDelMenuTriggered(QAction *action)
{

}

void MateriaLibDialog::saveMaterialLibData()
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(treeWidget->currentItem());

    if (myItem == NULL)
        return;

    float destiny = densityEdit->text().toFloat();
    float emissivity = emissivityEdit->text().toFloat();

    QMap<float,float> tmpLambdaMap;
    for (int i = 0;i < tmpLambdaTable->columnCount();i++) {
        if ((!tmpLambdaTable->item(0, i) || tmpLambdaTable->item(0, i)->text() == "") ||
                (!tmpLambdaTable->item(1, i) || tmpLambdaTable->item(1, i)->text() == ""))
            continue;
        qDebug() << i;
        tmpLambdaMap.insert(tmpLambdaTable->item(0, i)->text().toFloat(),
                            tmpLambdaTable->item(1, i)->text().toFloat());
    }

    QMap<float,float> tmpCpMap;
    for (int i = 0;i < tmpCpTable->columnCount();i++) {
        if ((!tmpCpTable->item(0, i) || tmpCpTable->item(0, i)->text() == "") ||
                (!tmpCpTable->item(1, i) || tmpCpTable->item(1, i)->text() == ""))
            continue;

        tmpLambdaMap.insert(tmpCpTable->item(0, i)->text().toFloat(),
                            tmpCpTable->item(1, i)->text().toFloat());
    }

    bool isSaved = MaterialLib::getInstance()->updateMaterialProperty(myItem->Index(), destiny, emissivity)
            && MaterialLib::getInstance()->updateMaterialTmpLambdaMap(myItem->Index(), tmpLambdaMap)
            && MaterialLib::getInstance()->updateMaterialTmpCpMap(myItem->Index(), tmpCpMap);


    if (isSaved) {
        QMessageBox::warning(this, tr(""), tr("保存成功"), tr("确定"));
    }
}
