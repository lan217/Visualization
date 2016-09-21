#include "widget_mulpoint.h"
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QHeaderView>

MulPointWidget::MulPointWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

void MulPointWidget::init()
{
    //init all Qmembers
    QGridLayout *mainLayout = new QGridLayout();

    geometryLabel = new QLabel(tr("几何结构:"));
    calNumLabel = new QLabel(tr("计算段数:"));
    frontRadiusLabel = new QLabel(tr("前缘半径:"));
    geometryFileButton = new QPushButton(tr("打开文件:"));

    calNumEdit = new QLineEdit(this);
    frontRadiusEdit = new QLineEdit(this);

    transformRadioBox = new TransformBox();
    amplificationBox = new AmplificationFactorBox();
    resultGraph = new QGraphicsView();
    //setting all qradiobox
    QStringList radioLabels;
    radioLabels << "二维圆柱" << "三维球头";
    frontStructRadio = new MyUsualRadioBox(tr("前缘结构"), radioLabels);
    radioLabels.clear();
    radioLabels << "迎风" << "背风";
    calPosRadio = new MyUsualRadioBox(tr("计算位置"), radioLabels);
    radioLabels.clear();
    radioLabels << "eebert参考系" << "eebert-spending";
    thermalFlowCalRadio = new MyUsualRadioBox(tr("热流计算方法"), radioLabels);
    radioLabels.clear();
    radioLabels << "尖楔" << "尖锥";
    luoTransFactorRadio = new MyUsualRadioBox(tr("罗格勒变换因子"), radioLabels);
    radioLabels.clear();
    radioLabels << "是" << "否";
    ifUsingFlowRadio = new MyUsualRadioBox(tr("是否使用湍流开始位置"), radioLabels);
    radioLabels.clear();
    radioLabels << "楔" << "锥";
    flowSettingRadio = new MyUsualRadioBox(tr("流动设置"), radioLabels);
    radioLabels.clear();
    radioLabels << "楔" << "锥";
    pressureSetRadio = new MyUsualRadioBox(tr("压力设置"), radioLabels);

    QGroupBox *tableBox = new QGroupBox("");
    QHBoxLayout *tableLayout = new QHBoxLayout();
    tableSettingWidget = new QTableWidget(this);
    tableSettingWidget->setRowCount(4);
    tableSettingWidget->setColumnCount(5);
    QStringList tableHeader;
    tableHeader << "长度" << "角度" << "计算点数" << "流动设置" << "压力设置";
    tableSettingWidget->setHorizontalHeaderLabels(tableHeader);
    tableSettingWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableSettingWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableLayout->addWidget(tableSettingWidget,0,Qt::AlignTop);
    tableBox->setLayout(tableLayout);
    tableSettingWidget->setFixedHeight(Utils::windowSize().height() * 0.3);

    for(int i = 0; i < 4; i++) {
        QComboBox *combomBox = new QComboBox();
        combomBox->addItem(tr("楔"));
        combomBox->addItem(tr("锥"));
        tableSettingWidget->setCellWidget(i, 3, combomBox);
    }
    for(int i = 0; i < 4; i++) {
        QComboBox * combomBox = new QComboBox();
        combomBox->addItem(tr("楔"));
        combomBox->addItem(tr("锥"));
        combomBox->addItem(tr("修正牛顿"));
        tableSettingWidget->setCellWidget(i, 4, combomBox);
    }

    QGroupBox *group = new QGroupBox();
    QGridLayout *groupLayout = new QGridLayout();
    groupLayout->addWidget(geometryLabel, 0, 0);
    groupLayout->addWidget(geometryFileButton, 0 ,1);
    groupLayout->addWidget(calNumLabel, 0, 2);
    groupLayout->addWidget(calNumEdit, 0, 3);
    groupLayout->addWidget(frontStructRadio, 1, 0, 1, 2);
    groupLayout->addWidget(frontRadiusLabel, 1, 2);
    groupLayout->addWidget(frontRadiusEdit, 1, 3);
    group->setLayout(groupLayout);
    group->setFixedHeight(Utils::windowSize().height() * 0.2);

    //setting layout

    mainLayout->addWidget(group, 0, 0, 1, 2);
    mainLayout->addWidget(tableBox, 1, 0, 1, 3, Qt::AlignTop);
    mainLayout->addWidget(amplificationBox, 2, 0, 1, 3);
    mainLayout->addWidget(resultGraph, 1, 3, 2, 2);
    mainLayout->addWidget(calPosRadio, 3, 0);
    mainLayout->addWidget(flowSettingRadio, 3, 1);
    mainLayout->addWidget(pressureSetRadio, 3, 2);
    mainLayout->addWidget(thermalFlowCalRadio, 3, 3);
    mainLayout->addWidget(luoTransFactorRadio, 3, 4);
    mainLayout->addWidget(transformRadioBox, 4, 0, 1, 4);
    mainLayout->setRowStretch(5, 1);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnStretch(2, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->setColumnStretch(4, 1);
    this->setLayout(mainLayout);


}

MulPointWidget::~MulPointWidget()
{

}
