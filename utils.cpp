#include "utils.h"
#include <stdarg.h>
#include <QDesktopWidget>
#include <QApplication>
Utils::Utils()
{

}
QSize Utils::windowSize()
{
    QSize screenSize = QApplication::desktop()->screenGeometry().size();
    return QSize(screenSize.width() * 0.9, screenSize.height() * 0.8);
}

int Utils::lineEditWidth()
{
    return windowSize().width() * 0.1;
}

QSize Utils::largeButtonSize()
{
    return QSize(windowSize().width() * 0.15, windowSize().height() * 0.15);
}
