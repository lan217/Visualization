#ifndef UTILS_H
#define UTILS_H
#include <QDebug>

class Utils
{
private:

public:
    Utils();
    static Utils getInstance();
    static QSize windowSize();
    static int lineEditWidth();
    static QSize largeButtonSize();
};




#endif // UTILS_H
