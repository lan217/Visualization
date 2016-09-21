#ifndef WIDGET_HCD_H
#define WIDGET_HCD_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QComboBox>
#include <QTableWidget>
#include <QTimeEdit>
#include <QGraphicsView>
#include "common.h"
#include "my_usual_radiobox.h"
#include "generaleditbox.h"

class WidgetHcd : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetHcd(QWidget *parent = 0);
    ~WidgetHcd();
    void init();
private:
    QLabel *materialLabel;
    QLabel *layerLabel;

    GeneralEditBox *hcdEditBox;

    QPushButton *loadMaterialButton;
    QPushButton *saveMeterialBUtton;
    QPushButton *createButton;
    QPushButton *calButton;
    QComboBox *layerBox;
    QTableWidget *materialTable;
    QTableWidget *borderTable;

    MyUsualRadioBox * isRadiationInsideRadio;
    MyUsualRadioBox * isRadiationOutsideRadio;
    QComboBox *boundaryConditionInsideBox;
    QComboBox *boundaryConditionOutsideBox;
    QPushButton *settingInputInsedeButton;
    QPushButton *settingInputOutsideButton;

    QGraphicsView *materialGraph;
    QGraphicsView *coordinateGraph;

    void fillMetalTable();

signals:

public slots:
    void changeTable(int index);
    void showLoadDialog();
    void showSettingInputDialog();
};

#endif // WIDGET_HCD_H
