#ifndef WIDGET_WIND_TUNNEL_H
#define WIDGET_WIND_TUNNEL_H


#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTimeEdit>
#include "common.h"
#include "my_usual_radiobox.h"

class WidgetWindTunnel : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetWindTunnel(QWidget *parent = 0);
    ~WidgetWindTunnel();
    void changeOutputTabWidget(const QStringList tabLabels);
private:
    QComboBox *calProjectBox;
    QTableWidget *inputTable;
    QTableWidget *output_Table;
    QTabWidget *outputTabWidget;

    QPushButton *loadButton;
    QPushButton *createButton;
    QPushButton *calButton;

signals:

public slots:
    void changeTable(int index);
};

#endif // WIDGET_WIND_TUNNEL_H
