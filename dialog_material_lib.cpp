#include "dialog_material_lib.h"
#include <QLayout>
#include <QHeaderView>
#include <QFile>
#include <QDebug>
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
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QGridLayout *leftLayout = new QGridLayout();
    QGridLayout *rightLayout = new QGridLayout();

    treeWidget = new QTreeWidget();
    treeWidget->clear();
    treeWidget->setHeaderHidden(true);
    connect(treeWidget, &QTreeWidget::itemClicked, this, &MateriaLibDialog::treeitemClicked);

    QTreeWidgetItem *group_input = new QTreeWidgetItem(treeWidget);
    group_input->setText(0, "金属材料");

//    QFile file("./data/material.dat");

//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//            qDebug()<<"Can't open the file!"<<file.fileName()<< endl;
//        }
//    QTextStream stream( &file );
//        while(!stream.atEnd()) {
//            QString str = stream.readLine();
//            QTreeWidgetItem *item = new QTreeWidgetItem(group_input);
//            item->setText(0, str);

//            qDebug()<< str;
//        }
    QStringList metalList = MaterialLib::getInstance()->getMaterial();

    {
        int i = 0;
        for(QStringList::iterator it = metalList.begin();it != metalList.end();it++,i++){
            QString current = *it;

            MyQtreeWidgetItem *item = new MyQtreeWidgetItem(group_input, i);
            item->setText(0, current);
            item->setFlags(Qt::ItemIsEditable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);

            qDebug()<< current;
        }
    }


    QTreeWidgetItem *group_setting = new QTreeWidgetItem(treeWidget);
    group_setting->setText(0, "非金属材料");

    leftLayout->addWidget(treeWidget, 0, 0, 1, 2);

    densityLabel = new QLabel(tr("密度:"));
    emissivityLabel = new QLabel(tr("辐射系数:"));
    densityEdit = new QLineEdit();
    emissivityEdit = new QLineEdit();
    saveMaterialButton = new QPushButton(tr("保存材料"));

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

//    tmpLambdaTable->seti


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

void MateriaLibDialog::treeitemClicked(QTreeWidgetItem* item)
{
    MyQtreeWidgetItem *myItem = static_cast<MyQtreeWidgetItem *>(item);

    if (myItem == NULL || myItem->Index() < 0 )
        return;

    MaterialLib::Material* material = MaterialLib::getInstance()->getMaterial(myItem->Index());

    if (material) {

        densityEdit->setText(QString::number(material->getDestiny()));
        emissivityEdit->setText(QString::number(material->getEmissivity()));
        int col = 0;
        qDebug() << material->getTmpCpMap().values();
        QMap<float,float>::iterator it;
        QMap<float,float> map = material->getTmpCpMap();
        for (it = map.begin();it != map.end();it++) {
            qDebug() << it.key();
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
        map = material->getTmpLambdaMap();
        for (it = map.begin();it != map.end();it++) {
            qDebug() << it.key();
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
