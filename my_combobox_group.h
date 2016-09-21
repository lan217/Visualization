#ifndef MY_COMBOBOX_GROUP_H
#define MY_COMBOBOX_GROUP_H

#include <QWidget>
#include <QGroupBox>
#include <QComboBox>
#include "common.h"

class comboBoxGroupBox : public QGroupBox
{
    Q_OBJECT
protected:
    QComboBox *comboBox;
    QLabel *comboBoxLabel;
    QLabel *firstLabel;
    QLabel *secondLabel;
    QLineEdit *firstEdit;
    QLineEdit *secondEdit;
    QPushButton *button;
    void init(const QStringList &comboLabels, const QStringList &contentLabels);

public:
    explicit comboBoxGroupBox(const QString &groupTitle = "", QWidget *parent = 0);
    explicit comboBoxGroupBox();
    ~comboBoxGroupBox();
    void setTransformIndex(int index);
    int transformIndex();
    void enable();
    void disable();


public slots:
    virtual void changeTransform(int index) = 0;

};

class TransformBox : public comboBoxGroupBox
{
    Q_OBJECT
public:
    explicit TransformBox(const QString &groupTitle = "", QWidget *parent = 0);
public slots:
    void changeTransform(int index);
};

class AmplificationFactorBox : public comboBoxGroupBox
{
    Q_OBJECT
public:
    explicit AmplificationFactorBox(const QString &groupTitle = "", QWidget *parent = 0);
public slots:
    void changeTransform(int index);
};

#endif // MY_COMBOBOX_GROUP_H
