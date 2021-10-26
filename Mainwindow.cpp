#include "Mainwindow.h"

int MainWindow::TerminalNumber = 0;

int MainWindow::ProjectNumber = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
     * MainWindow's Layout
    */
    resize(1300,750);
    MainWindowLayout = new QVBoxLayout();
    MainWidget = new QWidget;
    MainWidget->setLayout(MainWindowLayout);
    setCentralWidget(MainWidget);
    TopMenuBar = new QMenuBar;
    SecondWindowLayout = new QHBoxLayout;
    MainWindowLayout->addWidget(TopMenuBar);
    MainWindowLayout->addLayout(SecondWindowLayout);
    MainWindowLayout->setStretchFactor(TopMenuBar,1);
    MainWindowLayout->setStretchFactor(SecondWindowLayout,20);
    LeftToolBarSplitter = new QSplitter;
    ProjectWindowSplitter = new QSplitter;
    RightWindowSplitter = new QSplitter(Qt::Horizontal);
    SecondWindowLayout->addWidget(LeftToolBarSplitter);
    SecondWindowLayout->addWidget(ProjectWindowSplitter);
    SecondWindowLayout->addWidget(RightWindowSplitter);
    SecondWindowLayout->setStretchFactor(LeftToolBarSplitter,1);
    SecondWindowLayout->setStretchFactor(ProjectWindowSplitter,5);
    SecondWindowLayout->setStretchFactor(RightWindowSplitter,38);
    /*
     * Left Tool
    */
    LeftToolBar = new QToolBar;
    LeftToolBarSplitter->addWidget(LeftToolBar);
    ProjectAction = new QAction(tr("资源管理器"),LeftToolBar);
    ProjectTextEdit = new QTextEdit();
    ProjectWindowSplitter->addWidget(ProjectTextEdit);
    ProjectWindowSplitter->hide();
    LeftToolBar->addAction(ProjectAction);
    connect(ProjectAction,&QAction::triggered,this,&MainWindow::OpenPorjectEdit);
    /*
     * Top Menu
    */
    FileMenu = new QMenu(tr("文件"));
    OpenFileAction = new QAction(tr("打开文件"),FileMenu);
    OpenFileAction->setShortcut(QKeySequence::Open);
    OpenFileAction->setStatusTip(tr("Open a File"));
    connect(OpenFileAction,&QAction::triggered,this,&MainWindow::OpenFileClicked);
    OpenFolderAction = new QAction(tr("打开文件夹"),FileMenu);
    connect(OpenFolderAction,&QAction::triggered,this,&MainWindow::OpenFolderClicked);
    NewFileAction = new QAction(tr("新建文件"),FileMenu);
    connect(NewFileAction,&QAction::triggered,this,&MainWindow::NewFileClicked);
    NewFolderAction = new QAction(tr("新建文件夹"),FileMenu);
    connect(NewFolderAction,&QAction::triggered,this,&MainWindow::NewFolderClicked);
    FileMenu->addAction(OpenFileAction);
    FileMenu->addAction(OpenFolderAction);
    FileMenu->addAction(NewFileAction);
    FileMenu->addAction(NewFolderAction);
    BuildMenu = new QMenu(tr("构建"));
    TerminalMenu = new QMenu(tr("终端"));
    NewTerminal = new QAction(tr("打开一个新终端"),TerminalMenu);
    connect(NewTerminal,&QAction::triggered,this,&MainWindow::OpenTerminalEdit);
    DeleteTerminal = new QAction(tr("关闭打开的终端"),TerminalMenu);
    TerminalMenu->addAction(NewTerminal);
    TerminalMenu->addAction(DeleteTerminal);
    TopMenuBar->addMenu(FileMenu);
    TopMenuBar->addMenu(BuildMenu);
    TopMenuBar->addMenu(TerminalMenu);
    //Top Menu end
    CodingTextEdit = new QTextEdit(tr("hygtfygvyuHello C++"));
    RightWindowSplitter->addWidget(CodingTextEdit);
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
    NewFolder* folder = new NewFolder;
    folder->show();
}

void MainWindow::AboutBRS()
{

}

void MainWindow::OpenPorjectEdit()
{
    if(ProjectNumber % 2 == 0)
        ProjectWindowSplitter->setVisible(true);
    else
        ProjectWindowSplitter->setVisible(false);
    ProjectNumber++;
}

void MainWindow::OpenTerminalEdit()
{
    if(TerminalNumber % 2 == 0)
    {

    }
    else
    {

    }
}

