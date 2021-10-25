#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("BRSC++ IDE"));
    resize(1300,750);
    /*
        BRSC++ IDE Version 0.1 UI Design:
       -----------------------------------------
       | P |File  Build  Terminal  About  Help |
       | r |-----------------------------------|
       | o |                                   |
       | j |                                   |
       | e | C++ Programmer                    |
       | c |                                   |
       | t |                                   |
       |---|             Coding                |
       | P |                                   |
       | l |                            Window |
       | u |                                   |
       | g |                                   |
       | i |-----------------------------------|
       | n |Linux  Terminal                    |
       | s |                                   |
       |---|                   Spliting  Window|
       -----------------------------------------
       something about this UI Design:
       Fristly,Terminal not only can run shell commands,but also can output g++'s oudata.
    */
    TopMenuBar = new QMenuBar(this);
    TopMenuBar->resize(1300,35);
    FileMenu = new QMenu(tr("文件"),this);
    OpenFileAction = new QAction(tr("打开文件"),this);
    OpenFileAction->setShortcut(QKeySequence::Open);
    OpenFileAction->setStatusTip(tr("Open a File"));
    connect(OpenFileAction,&QAction::triggered,this,&MainWindow::OpenFileClicked);
    OpenFolderAction = new QAction(tr("打开文件夹"),this);
    connect(OpenFolderAction,&QAction::triggered,this,&MainWindow::OpenFolderClicked);
    NewFileAction = new QAction(tr("新建文件"),this);
    NewFolderAction = new QAction(tr("新建文件夹"),this);
    FileMenu->addAction(OpenFileAction);
    FileMenu->addAction(OpenFolderAction);
    FileMenu->addAction(NewFileAction);
    FileMenu->addAction(NewFolderAction);
    AboutMenu = new QMenu(tr("关于"),this);
    TopMenuBar->addMenu(FileMenu);
    TopMenuBar->addMenu(AboutMenu);
}

MainWindow::~MainWindow()
{
}

void MainWindow::OpenFileClicked()
{
   QString getName = QFileDialog::getOpenFileName(this,"","/","All file(*,*);;C file(*.cpp)");
}

void MainWindow::OpenFolderClicked()
{

}

void MainWindow::NewFileClicked()
{

}

void MainWindow::NewFolderClicked()
{
    NewFolder folder;
    folder.show();
}

