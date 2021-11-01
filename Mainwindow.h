#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./Settings/SettingsAdmin.h"
#include "./MainWindow/TopMenuWindow/Newfile.h"
#include "./MainWindow/TopMenuWindow/Newfolder.h"
#include "./MainWindow/TopMenuWindow/Openfloder.h"
#include "./MainWindow/LeftToolWindow/ProjectFileTree.h"

#include <QList>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QProcess>
#include <QTextEdit>
#include <QGroupBox>
#include <QSplitter>
#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>

class ApplicationInfo;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class TreeMenu;
    friend class ApplicationInfo;
public:
    MainWindow(QWidget *parent = nullptr);
    static int TerminalNumber;
    static int ProjectNumber;
    static QString OpenProject;
    ~MainWindow();
private:
    //Layout
    QWidget* MainWidget;
    QVBoxLayout* MainWindowLayout;
    QHBoxLayout* SecondWindowLayout;
    QSplitter* LeftToolBarSplitter;
    QSplitter* ProjectWindowSplitter;
    QVBoxLayout* RightWindowLayout;
    QSplitter* CodingWindowSplitter;
    QSplitter* TerminalWindowSplitter;
    //
    QTextEdit* CodingTextEdit;
    //Top Menu
    QMenuBar* TopMenuBar;
    QMenu* FileMenu;
    QAction* NewAction;
    QAction* OpenAction;
    QAction* OpenProjectAction;
    QAction* NewProjectAction;
    QAction* SaveFileAction;
    QAction* CloseAction;
    QAction* CloseProjectAction;
    QMenu* BuildMenu;
    QAction* NewBuildToExecAction;
    QAction* NewBuildOnlyCMakeAction;
    QAction* RebuildToExecAction;
    QMenu* ToolAdminMenu;
    QAction* OpenSettingWindow;
    SettingsAdmin* AdminWindow;
    QMenu* TerminalMenu;
    QAction* NewTerminal;
    QAction* DeleteTerminal;
    QLabel* TitleLabel;
    QTextEdit* InfoText;
    //BuildAction* NewBuild;
    QMenu* AboutMenu;
    QMenu* Help;
    //Left Tool
    QVBoxLayout* LeftToolLayout;
    QHBoxLayout* LeftMainLayout;
    TreeMenu* Treemenu;
    QToolBar* LeftTopBar;
    QAction* ProjectAction;
    QLabel* NULLLabel;
    QToolBar* LeftButtomBar;
    QAction* ToolBuildAction;
    ApplicationInfo* info;
signals:
    void EmitPathName(QString PathName);
    void OnlyGenerateMakeFile(QString make);
    void GenerateExec(QString exe);
public slots:
    //File Menu
    void NewActionWindow();
    void OpenActionWindow();
    QString OpenProjectWindow();
    void NewProjectWindow();
    void SaveFileFunction();
    void CloseFunction();
    void CloseProject();
    //Build Menu
    void MakeFileClicked();
    void ExecClicked();
    //Terminal Menu
    void OpenTerminalEdit();
    void SetInfoText(QString Applicationinfo);
    //About Menu
    void AboutBRS();
    //Project Action
    void OpenPorjectEdit();
    //
    void ReadFileEdit(QString Path);
    //ToolMenu
    void OpenSettingsWindow();
};

class ApplicationInfo : public QObject
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit ApplicationInfo(QObject* parent = nullptr);
private:
    QProcess* Process;
    QProcess* Process1;
    QString OpenProjectPath;
    QString ShellSize;
public slots:
    void GetOpenProjectName(QString Path);
    void BashSelectAndMain(QString ShellSize);
    void FinshedOutput();
    void BashStandardOutput();
    void BashStandardError();
signals:
    void StandardQString(QString output);
    void StandardError(QString error);
    void StandardFinsh(QString FinshInfo);
};

#endif // MAINWINDOW_H
