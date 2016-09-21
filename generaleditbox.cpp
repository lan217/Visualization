#include "generaleditbox.h"
#include <QDebug>
GeneralEditBox::GeneralEditBox(QString title, const QStringList &labels, int rows, int cols, QWidget *parent) :
    QGroupBox(title, parent)
{
    this->numOfEdits = labels.count();
    QGridLayout *editLayout = new QGridLayout;

    int k = 0;
    int count = -1;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            count++;
            QLabel *label = new QLabel(labels.at(count), this);
            label->setObjectName("lable_" + QString::number(i) + "_" + QString::number(j));
            QLineEdit *edit = new QLineEdit(this);
            edit->setObjectName("edit_" + QString::number(i) + "_" + QString::number(j));
            editLayout->addWidget(label, i, k);
            editLayout->addWidget(edit, i, k+1);

            k = k + 2;
        }
        k = 0;
    }

    this->setLayout(editLayout);

}

QLabel *GeneralEditBox::getLabel(int row, int col)
{
    QLabel *lable = this->findChild<QLabel*>\
            ("lable_" + QString::number(row) + "_" + QString::number(col));

    if (lable) {
        return lable;
    }

    return NULL;
}

QLineEdit *GeneralEditBox::getLineEdit(int row, int col)
{
    QLineEdit *edit = this->findChild<QLineEdit *>\
            ("edit_" + QString::number(row) + "_" + QString::number(col));

    if (edit) {
        return edit;
    }

    return NULL;
}

void GeneralEditBox::removeWidget(int row, int col)
{
    int index = row * (col - 1) + col;
    this->layout()->takeAt(index);
}

void GeneralEditBox::addWidget(QWidget* widget, int row, int col, int rowSpan, int columnSpan)
{
    QGridLayout *layout =  static_cast<QGridLayout *>(this->layout());

    if (layout) {
        layout->addWidget(widget, row, col, rowSpan, columnSpan);
    }
}
