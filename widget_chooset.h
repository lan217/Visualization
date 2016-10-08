#ifndef WIDGET_CHOOSE_H
#define WIDGET_CHOOSE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include "common.h"
#include "my_usual_radiobox.h"


class WidgetChoose : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChoose(QWidget *parent = 0);
    ~WidgetChoose();

private:
    QLabel *cruiseStratLabel;
    QLabel *cruiseEndLabel;
    QLabel *trajectoryStartLineLabel;
    QLabel *characMutationLabel;
    QLabel *heatecMinMachNumLabel;
    QLabel *heatecTimeStartLabel;
    QLabel *heatecTimeEndLabel;
    QLabel *heatecMinTimeStepLabel;
    QLabel *heatecStartLineLabel;
    QLabel *hcdTimeStartLabel;
    QLabel *hcdTimeEndLabel;
    QLabel *chooseTimeStartLabel;
    QLabel *chooseTimeEndLabel;
    QLabel *chooseCoordinateLabel;

    QLineEdit *cruiseStratEdit;
    QLineEdit *cruiseEndEdit;
    QLineEdit *trajectoryStartLineEdit;
    QLineEdit *characMutationEdit;
    QLineEdit *heatecMinMachNumEdit;
    QLineEdit *heatecTimeStartEdit;
    QLineEdit *heatecTimeEndEdit;
    QLineEdit *heatecMinTimeStepEdit;
    QLineEdit *heatecStartLineEdit;
    QLineEdit *hcdTimeStartEdit;
    QLineEdit *hcdTimeEndEdit;
    QLineEdit *chooseTimeStartEdit;
    QLineEdit *chooseTimeEndEdit;
    QLineEdit *chooseCoordinateEdit;
    QLineEdit *trajectoryDirectoryEdit;
    QLineEdit *atmosphereFileEdit;
    QLineEdit *pointParaTemplateEdit;
    MyUsualRadioBox *heightUnitsBox;
    MyUsualRadioBox *angleUnitsBox;
    MyUsualRadioBox *staticTmpUnitsBox;
    MyUsualRadioBox *staticPressureUnitsBox;
    MyUsualRadioBox *calSpeedMethodBox;
    MyUsualRadioBox *heatecStartMethodBox;
    MyUsualRadioBox *heatecClearResultBox;
    MyUsualRadioBox *hcdStartBox;
    MyUsualRadioBox *hcdClearBox;
    QTableWidget *attackAngleRatioTable;
    QTableWidget *trajectoryParaColTable;
    QTableWidget *heatecParaColTable;
    QPushButton *selectTrajectoryDirButton;
    QPushButton *selectAtmosphereButton;
    QPushButton *selectPointParaTemplateButton;
    QPushButton *createButton;
    QPushButton *calButton;
public slots:
    void showSelectedDirectory();
    void changeAtmosphereAvailability(const QString dir);
    void saveParameterData();
};

#endif // WIDGET_CHOOSE_H
