#include "Mainwindow.h"

int MainWindow::TerminalNumber = 0;

int MainWindow::ProjectNumber = 0;

QString MainWindow::ProjectName = nullptr;

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
    LeftMainLayout = new QHBoxLayout;
    RightWindowSplitter = new QSplitter(Qt::Horizontal);
    SecondWindowLayout->addLayout(LeftMainLayout);
    SecondWindowLayout->addWidget(ProjectWindowSplitter);
    SecondWindowLayout->addWidget(RightWindowSplitter);
    SecondWindowLayout->setStretchFactor(LeftToolBarSplitter,1);
    SecondWindowLayout->setStretchFactor(ProjectWindowSplitter,5);
    SecondWindowLayout->setStretchFactor(RightWindowSplitter,38);
    /*
     * Left Tool
    */
    Treemenu = new TreeMenu();
    LeftTopBar = new QToolBar;
    LeftToolLayout = new QVBoxLayout;
    NULLLabel = new QLabel;
    LeftButtomBar = new QToolBar;
    LeftMainLayout->addLayout(LeftToolLayout);
    LeftMainLayout->addWidget(LeftToolBarSplitter);
    LeftToolLayout->addWidget(LeftTopBar);
    LeftToolLayout->addWidget(NULLLabel);
    LeftToolLayout->addWidget(LeftButtomBar);
    LeftToolLayout->setStretchFactor(LeftTopBar,1);
    LeftToolLayout->setStretchFactor(NULLLabel,1);
    LeftToolLayout->setStretchFactor(LeftButtomBar,1);
    ProjectAction = new QAction(tr("资源管理器"),LeftTopBar);
    ProjectAction->setIcon(QIcon(":/RunImage/Image/Project.png"));
    ProjectWindowSplitter->addWidget(Treemenu);
    ProjectWindowSplitter->hide();
    LeftTopBar->addAction(ProjectAction);
    connect(ProjectAction,&QAction::triggered,this,&MainWindow::OpenPorjectEdit);
    /*
     * Top Menu
    */
    FileMenu = new QMenu(tr("文件"));
    OpenAction = new QAction(tr("打开文件"),FileMenu);
    OpenProjectAction = new QAction(tr("打开项目"),FileMenu);
    NewAction = new QAction(tr("新建文件"),FileMenu);
    NewProjectAction = new QAction(tr("新建项目"),FileMenu);
    SaveFileAction = new QAction(tr("保存当前文件"),FileMenu);
    CloseAction = new QAction(tr("关闭当前文件"),FileMenu);
    CloseProjectAction = new QAction(tr("关闭当前项目"),FileMenu);
    connect(OpenAction,&QAction::triggered,this,&MainWindow::OpenActionWindow);
    connect(OpenProjectAction,&QAction::triggered,this,&MainWindow::OpenProjectWindow);
    connect(NewAction,&QAction::triggered,this,&MainWindow::NewActionWindow);
    connect(NewProjectAction,&QAction::triggered,this,&MainWindow::NewProjectWindow);
    connect(SaveFileAction,&QAction::triggered,this,&MainWindow::SaveFileFunction);
    connect(CloseAction,&QAction::triggered,this,&MainWindow::CloseFunction);
    connect(CloseProjectAction,&QAction::triggered,this,&MainWindow::CloseProject);
    FileMenu->addAction(OpenAction);
    FileMenu->addAction(OpenProjectAction);
    FileMenu->addAction(NewAction);
    FileMenu->addAction(NewProjectAction);
    FileMenu->addAction(SaveFileAction);
    FileMenu->addAction(CloseAction);
    FileMenu->addAction(CloseProjectAction);
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
    CodingTextEdit = new QTextEdit(tr("#include<stdio.h>"));
    RightWindowSplitter->addWidget(CodingTextEdit);
    connect(Treemenu,SIGNAL(MyItemDoubleClicked(QString)),this,SLOT(ReadFileEdit(QString)));
}

MainWindow::~MainWindow()
{

}

QString MainWindow::GetOpenFolderName()
{
    if(ProjectName != nullptr)
    {
        qDebug()<<ProjectName;
        return ProjectName;
    }
    else
        return nullptr;
}

void MainWindow::OpenActionWindow()
{

}

QString MainWindow::OpenProjectWindow()
{
    ProjectName = QFileDialog::getExistingDirectory();
    QString FolderName = ProjectName;
    qDebug()<<ProjectName;
    return FolderName;
}

void MainWindow::NewActionWindow()
{
    NewFile* file = new NewFile;
    file->show();
}

void MainWindow::NewProjectWindow()
{
    NewFolder* folder = new NewFolder;
    folder->show();
}

void MainWindow::SaveFileFunction()
{

}

void MainWindow::CloseFunction()
{

}

void MainWindow::CloseProject()
{

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

void MainWindow::ReadFileEdit(QString Path)
{
    QFile file(Path);
    file.open(QIODevice::ReadOnly);
    QString Text = file.readAll();
    CodingTextEdit->setText(Text);
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

