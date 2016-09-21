#include "widget_wind_tunnel.h"
#include "widget_hcd.h"
#include "dialog_material_lib.h"
#include <QLayout>
#include <QHeaderView>
#include <QGroupBox>
#include <QLabel>

WidgetWindTunnel::WidgetWindTunnel(QWidget *parent) :
    QWidget(parent)

{
    QGridLayout *mainLayout = new QGridLayout();

    // left box
    QGroupBox *calGroupBox = new QGroupBox(tr("计算项目"));
    QGridLayout *calGroupLayout = new QGridLayout();
    calProjectBox = new QComboBox();
    QStringList calProjectLabels;
    calProjectLabels << "1喷管口出Ma" << "2驻点状态设计" << "3平板状态设计" ;
    calProjectBox->addItems(calProjectLabels);
    calProjectBox->setCurrentIndex(0);
    loadButton = new QPushButton(tr("载入数据"), this);
    calGroupLayout->addWidget(calProjectBox, 0, 0);
    calGroupLayout->addWidget(loadButton, 0, 2);
    calGroupBox->setLayout(calGroupLayout);

    connect(calProjectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeTable(int)));

    // mid box
    QGroupBox *inputGroupBox= new QGroupBox(tr("输入"));
    QGridLayout *inputLayout=new QGridLayout();
    inputTable = new QTableWidget(10, 3);
    inputTable->verticalHeader()->setVisible(false);
    QStringList headerLabels;
    headerLabels << "h0" << "P0"<<"A2/A1";
    inputTable->setHorizontalHeaderLabels(headerLabels);
    inputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    inputLayout->addWidget(inputTable, 0, 0);
    inputGroupBox->setLayout(inputLayout);


    // right box
    QGroupBox *outputGroupBox= new QGroupBox(tr("输出"));
    QGridLayout *outputLayout=new QGridLayout();
    outputTabWidget = new QTabWidget(this);
    QStringList tabLabels;
    tabLabels << "孤室参数" << "喉道" << "喷管出口" << "斜激波" << "总参数";
    changeOutputTabWidget(tabLabels);
    outputLayout->addWidget(outputTabWidget);
    outputGroupBox->setLayout(outputLayout);


    createButton = new QPushButton(tr("存储"), this);
    createButton->setFixedSize(Utils::largeButtonSize());
    calButton = new QPushButton(tr("开始计算"), this);
    calButton->setFixedSize(Utils::largeButtonSize());

    mainLayout->addWidget(calGroupBox, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(inputGroupBox, 0, 1);
    mainLayout->addWidget(outputGroupBox, 0, 2, 1, 3);
    mainLayout->addWidget(createButton, 2, 3);
    mainLayout->addWidget(calButton, 2, 4);
    mainLayout->setRowStretch(0, 4);
    mainLayout->setRowStretch(1, 1);
    mainLayout->setRowStretch(2, 1);
    mainLayout->setColumnStretch(1, 4);
    mainLayout->setColumnStretch(3, 6);
    mainLayout->setColumnStretch(2, 2);
    mainLayout->setColumnStretch(3, 3);
    mainLayout->setColumnStretch(4, 3);

    this->setLayout(mainLayout);
}

WidgetWindTunnel::~WidgetWindTunnel()
{

}

void WidgetWindTunnel::changeOutputTabWidget(const QStringList tabLabels)
{
    outputTabWidget->clear();
    for (int i = 0;i < tabLabels.count();i++) {
        QTableWidget *tabTableWidget = new QTableWidget(9, 5, this);
        tabTableWidget->setObjectName("tableWidget_" + QString::number(i));
        tabTableWidget->verticalHeader()->setVisible(false);
        tabTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        outputTabWidget->addTab(tabTableWidget, tabLabels.at(i));
    }
}

void WidgetWindTunnel::changeTable(int index)
{
    QStringList headerLabels;
    QStringList tabLabels;
    if(index == 0){
        headerLabels << "h0" << "P0"<<"A2/A1";

        inputTable->setColumnCount(3);
        inputTable->setHorizontalHeaderLabels(headerLabels);
        tabLabels << "孤室参数" << "喉道" << "喷管出口" << "斜激波" << "总参数";
        changeOutputTabWidget(tabLabels);
    }else if(index == 1){
        headerLabels << "t0" << "Ht "<< "Ma" << "Pt";
        inputTable->setColumnCount(4);
        inputTable->setHorizontalHeaderLabels(headerLabels);
        tabLabels << "";
        changeOutputTabWidget(tabLabels);
    }else{
        headerLabels << "Hr" << "Ma" << "Q";
        inputTable->setColumnCount(3);
        inputTable->setHorizontalHeaderLabels(headerLabels);
        tabLabels << "波前参数" << "喷管参数" << "设计参数";
        changeOutputTabWidget(tabLabels);
    }
}
