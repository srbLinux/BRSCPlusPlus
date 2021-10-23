#include "Login.h"
#include "Mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Login logWin;
    logWin.show();
    return a.exec();
}
