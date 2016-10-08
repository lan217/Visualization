#ifndef WIDGET_MULPOINT_H
#define WIDGET_MULPOINT_H

#include <QDialog>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QFileDialog>
#include <QComboBox>
#include <QGroupBox>
#include <QGraphicsView>
#include "my_usual_radiobox.h"
#include "my_combobox_group.h"
#include "common.h"

class MulPointWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MulPointWidget(QWidget *parent = 0);
    ~MulPointWidget();
    void init();
    QString getParameterData();


private:
    QLabel *geometryLabel;
    QLabel *calNumLabel;
    QLabel *frontRadiusLabel;

    MyUsualRadioBox *frontStructRadio;
    MyUsualRadioBox *calPosRadio;
    MyUsualRadioBox *thermalFlowCalRadio;
    MyUsualRadioBox *luoTransFactorRadio;
    MyUsualRadioBox *ifUsingFlowRadio;
    MyUsualRadioBox *flowSettingRadio;
    MyUsualRadioBox *pressureSetRadio;
    MyUsualRadioBox *temperatureRadio;
    QLineEdit *wallTemperatureEdit;

    QPushButton *geometryFileButton;

    QLineEdit *frontRadiusEdit;
    QComboBox *calNumBox;

    QTableWidget *tableSettingWidget;
    AmplificationFactorBox *amplificationBox;
    TransformBox *transformRadioBox;
    QGraphicsView *resultGraph;

public slots:
    void changeTable(int index);
    void changeWidgetByRadioBox(int index);
};

#endif // WIDGET_MULPOINT_H
