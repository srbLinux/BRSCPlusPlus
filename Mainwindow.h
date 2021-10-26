#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Newfolder.h"

#include <QList>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QTextEdit>
#include <QGroupBox>
#include <QSplitter>
#include <QDockWidget>
#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    static int TerminalNumber;
    static int ProjectNumber;
    ~MainWindow();
private:
    //Layout
    QWidget* MainWidget;
    QVBoxLayout* MainWindowLayout;
    QHBoxLayout* SecondWindowLayout;
    QSplitter* LeftToolBarSplitter;
    QSplitter* ProjectWindowSplitter;
    QSplitter* RightWindowSplitter;
    //
    QTextEdit* ProjectTextEdit;
    QTextEdit* CodingTextEdit;
    //Top Menu
    QMenuBar* TopMenuBar;
    QMenu* FileMenu;
    QAction* OpenFileAction;
    QAction* OpenFolderAction;
    QAction* NewFileAction;
    QAction* NewFolderAction;
    QMenu* BuildMenu;
    QMenu* TerminalMenu;
    QAction* NewTerminal;
    QAction* DeleteTerminal;
    QDockWidget* TerminalWindow;
    QMenu* AboutMenu;
    QMenu* Help;
    QToolBar* LeftToolBar;
    QAction* ProjectAction;
public slots:
    //File Menu
    void OpenFileClicked();
    void OpenFolderClicked();
    void NewFileClicked();
    void NewFolderClicked();
    //Terminal Menu
    void OpenTerminalEdit();
    //About Menu
    void AboutBRS();
    //Project Action
    void OpenPorjectEdit();
};
#endif // MAINWINDOW_H
