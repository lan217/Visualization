#include "dialog_table.h"
#include <QLayout>
#include <QHeaderView>
TableDialog::TableDialog(const QString &title, const QStringList &headerLabels, QWidget *parent) :
    QDialog(parent)
{
    QGridLayout *mainLayout = new QGridLayout();

    inputTable = new QTableWidget(3, 3);
    inputTable->verticalHeader()->setVisible(false);

    inputTable->setHorizontalHeaderLabels(headerLabels);
    inputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);;

    loadButton = new QPushButton(tr("载入"), this);
    saveButton = new QPushButton(tr("保存"), this);

    mainLayout->addWidget(inputTable, 0, 0, 1, 2);
    mainLayout->addWidget(loadButton, 1, 0);
    mainLayout->addWidget(saveButton, 1, 1);

    this->setLayout(mainLayout);
    this->setFixedSize(400, 200);
    this->setWindowTitle(title);
}

TableDialog::~TableDialog()
{

}
