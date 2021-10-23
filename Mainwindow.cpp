#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("BRSC++ IDE"));
    resize(1200,800);
}

MainWindow::~MainWindow()
{
}

