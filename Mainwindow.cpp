#include "Mainwindow.h"

#include <QTime>

int MainWindow::TerminalNumber = 0;

int MainWindow::ProjectNumber = 0;

QString MainWindow::OpenProject = nullptr;

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
    RightWindowLayout = new QVBoxLayout;
    SecondWindowLayout->addLayout(LeftMainLayout);
    SecondWindowLayout->addWidget(ProjectWindowSplitter);
    SecondWindowLayout->addLayout(RightWindowLayout);
    SecondWindowLayout->setStretchFactor(LeftToolBarSplitter,1);
    SecondWindowLayout->setStretchFactor(ProjectWindowSplitter,5);
    SecondWindowLayout->setStretchFactor(RightWindowLayout,38);
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
    NewBuildToExecAction = new QAction(tr("构建项目"),BuildMenu);
    NewBuildOnlyCMakeAction = new QAction(tr("仅生成Makefile"),BuildMenu);
    BuildMenu->addAction(NewBuildToExecAction);
    BuildMenu->addAction(NewBuildOnlyCMakeAction);
    TerminalMenu = new QMenu(tr("终端"));
    ToolAdminMenu = new QMenu(tr("工具"));
    OpenSettingWindow = new QAction(tr("设置"),ToolAdminMenu);
    connect(OpenSettingWindow,&QAction::triggered,this,&MainWindow::OpenSettingsWindow);
    ToolAdminMenu->addAction(OpenSettingWindow);
    NewTerminal = new QAction(tr("打开一个新终端"),TerminalMenu);
    connect(NewTerminal,&QAction::triggered,this,&MainWindow::OpenTerminalEdit);
    DeleteTerminal = new QAction(tr("关闭打开的终端"),TerminalMenu);
    TerminalMenu->addAction(NewTerminal);
    TerminalMenu->addAction(DeleteTerminal);
    TopMenuBar->addMenu(FileMenu);
    TopMenuBar->addMenu(BuildMenu);
    TopMenuBar->addMenu(TerminalMenu);
    TopMenuBar->addMenu(ToolAdminMenu);
    //Top Menu end
    CodingTextEdit = new QTextEdit(tr("#include<stdio.h>"));
    CodingWindowSplitter = new QSplitter();
    TerminalWindowSplitter =  new QSplitter(Qt::Vertical);
    RightWindowLayout->addWidget(CodingWindowSplitter);
    RightWindowLayout->addWidget(TerminalWindowSplitter);
    RightWindowLayout->setStretchFactor(CodingWindowSplitter,3);
    RightWindowLayout->setStretchFactor(TerminalWindowSplitter,1);
    CodingWindowSplitter->addWidget(CodingTextEdit);
    //NewBuild = new BuildAction;
    InfoText = new QTextEdit;
    TitleLabel = new QLabel(tr("应用程序输出"));
    QVBoxLayout* TerminalLayout = new QVBoxLayout(TerminalWindowSplitter);
    TerminalWindowSplitter->addWidget(TitleLabel);
    TerminalWindowSplitter->addWidget(InfoText);
    TerminalLayout->addWidget(TitleLabel);
    TerminalLayout->addWidget(InfoText);
    TerminalLayout->setStretchFactor(TitleLabel,1);
    TerminalLayout->setStretchFactor(InfoText,5);
    info = new ApplicationInfo;
    //QSize Terminalsize = TerminalWindowSplitter->size();
    //NewBuild->resize(Terminalsize.rwidth(),Terminalsize.rheight());
    connect(Treemenu,SIGNAL(MyItemDoubleClicked(QString)),this,SLOT(ReadFileEdit(QString)));
    connect(NewTerminal,&QAction::triggered,this,&MainWindow::OpenTerminalEdit);
    connect(this,SIGNAL(EmitPathName(QString)),Treemenu,SLOT(CreateTreeRoot(QString)));
    connect(this,SIGNAL(EmitPathName(QString)),info,SLOT(GetOpenProjectName(QString)));
    connect(NewBuildOnlyCMakeAction,&QAction::triggered,this,&MainWindow::MakeFileClicked);
    connect(NewBuildToExecAction,&QAction::triggered,this,&MainWindow::ExecClicked);
    connect(this,SIGNAL(OnlyGenerateMakeFile(QString)),info,SLOT(BashSelectAndMain(QString)));
    connect(this,SIGNAL(GenerateExec(QString)),info,SLOT(BashSelectAndMain(QString)));
    connect(info,SIGNAL(StandardQString(QString)),this,SLOT(SetInfoText(QString)));
    connect(info,SIGNAL(StandardError(QString)),this,SLOT(SetInfoText(QString)));
    connect(info,SIGNAL(StandardFinsh(QString)),this,SLOT(SetInfoText(QString)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::ChangeBRSAllWindowColor(QString StrColor)
{
    ProjectWindowSplitter->setStyleSheet("");
}

void MainWindow::MakeFileClicked()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    str += ": Starting " + OpenProject + "... ";
    InfoText->append(str);
    emit OnlyGenerateMakeFile("MAKE");
}

void MainWindow::ExecClicked()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    str += ": Starting " + OpenProject + "... ";
    InfoText->append(str);
    emit GenerateExec("EXEC");
}

void MainWindow::SetInfoText(QString Applicationinfo)
{
    InfoText->append(Applicationinfo);
}

void MainWindow::OpenActionWindow()
{

}

QString MainWindow::OpenProjectWindow()
{
    QString PathName = QFileDialog::getExistingDirectory();
    OpenProject = PathName;
    if(PathName != nullptr)
        emit EmitPathName(PathName);
    return PathName;
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
        TerminalWindowSplitter->setVisible(true);
    }
    else
        TerminalWindowSplitter->setVisible(false);
    TerminalNumber++;
}

void MainWindow::OpenSettingsWindow()
{
    AdminWindow = new SettingsAdmin;
    AdminWindow->show();
}

ApplicationInfo::ApplicationInfo(QObject* parent) : QObject(parent)
{
    Process = new QProcess(this);
}

void ApplicationInfo::GetOpenProjectName(QString Path)
{
    OpenProjectPath = Path;
}

void ApplicationInfo::BashSelectAndMain(QString ShellSize)
{
    this->ShellSize = ShellSize;
    if(ShellSize == "MAKE" || ShellSize == "EXEC")
    {
        QStringList list;
        list<<"..";
        Process->setProgram("cmake");
        Process->setArguments(list);
        Process->start();
        connect(Process,&QProcess::readyReadStandardOutput,this,&ApplicationInfo::BashStandardOutput);
        connect(Process,&QProcess::readyReadStandardError,this,&ApplicationInfo::BashStandardError);
    }
    if(ShellSize == "EXEC")
    {
        Process1 = new QProcess;
        QStringList list0;
        list0<<"";
        Process1->setProgram("make");
        Process1->setArguments(list0);
        Process1->start();
        connect(Process,&QProcess::readyReadStandardOutput,this,&ApplicationInfo::BashStandardOutput);
        connect(Process,&QProcess::readyReadStandardError,this,&ApplicationInfo::BashStandardError);
    }
}

void ApplicationInfo::BashStandardOutput()
{
    QString OutOutput = QString::fromLocal8Bit(Process->readAllStandardOutput());
    emit StandardQString(OutOutput);
}

void ApplicationInfo::BashStandardError()
{
    QString error = QString::fromLocal8Bit(Process->readAllStandardError());
    emit StandardError(error);
}

void ApplicationInfo::FinshedOutput()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    str += ": " + OpenProjectPath + "exited with code 0";
    emit StandardFinsh(str);
}
