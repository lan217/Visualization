#ifndef MY_USUAL_RADIOBOX_H
#define MY_USUAL_RADIOBOX_H
#include <QGroupBox>
#include <QRadioButton>
#include <QButtonGroup>
#include "common.h"
/**
 * @brief package groupBox for handling radioButtons
 */
class MyUsualRadioBox : public QGroupBox
{
    Q_OBJECT
public:
    enum Orientation{
        Horizontal = 0,
        Vertical
    };
    explicit MyUsualRadioBox(const QString &groupTitle, const QStringList &titles, \
                             Orientation orien = Horizontal, QWidget *parent = 0);
    void setRadioIndex(int index);
    int radioIndex();
    void enable();
    void disable();
    void insertWidgetWithButtonIndex(int index, QWidget *widget);


private:
    int numRadio;
    QButtonGroup *radioGroup;
    Orientation orien;
signals:
    void radioToggle(int index);
public slots:
    void radioSlot();

};

#endif // MY_USUAL_RADIOBOX_H
