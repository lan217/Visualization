#include "widget_main.h"
#include "widget_heatec.h"
#include "dialog_login.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog dialog;
//    dialog.show();

//    if (dialog.exec() == QDialog::Accepted) {
        // login success
        WidgetMain w;
        w.show();

        return a.exec();
//    } else {
//        return 0;
//    }

}
