#include "Login.h"
#include "Mainwindow.h"

#include <unistd.h>
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/home/srblinux/Start.jpg"));
    splash.show();
    //sleep(2);
    MainWindow w;
    w.show();
    splash.finish(&w);
    Login logWin;
    logWin.show();
    return a.exec();
}
