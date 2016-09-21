#ifndef GENERALEDITBOX_H
#define GENERALEDITBOX_H

#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class GeneralEditBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit GeneralEditBox(QString title, const QStringList &labels, int rows, int cols, QWidget *parent = 0);
    QLabel *getLabel(int row, int col);
    QLineEdit *getLineEdit(int row, int col);
    void removeWidget(int row, int col);
    void addWidget(QWidget* widget, int row, int col, int rowSpan = 1, int columnSpan= 1);
private:

    int numOfEdits;

};

#endif // GENERALEDITBOX_H
