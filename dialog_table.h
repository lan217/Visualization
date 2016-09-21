#ifndef DIALOG_TABLE_H
#define DIALOG_TABLE_H

#include <QDialog>
#include <QPushButton>
#include <QTableWidget>

class TableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableDialog(const QString &title, const QStringList &headerLabels, QWidget *parent = 0);
    ~TableDialog();

private:
    QTableWidget *inputTable;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // DIALOG_TABLE_H
