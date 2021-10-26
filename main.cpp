#include "Login.h"
#include "Mainwindow.h"

#include <QList>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QToolBox>
#include <QTextEdit>
#include <QGroupBox>
#include <QSplitter>
#include <QFileDialog>
#include <QToolButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>
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
