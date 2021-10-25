#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Newfolder.h"

#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QGroupBox>
#include <QFileDialog>
#include <QToolButton>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QMenu* FileMenu;
    QAction* OpenFileAction;
    QAction* OpenFolderAction;
    QAction* NewFileAction;
    QAction* NewFolderAction;
    QAction* CloseAllFileAction;
    QMenu* AboutMenu;
    QMenu* BuildMenu;
    QMenu* TerminalMenu;
    QMenu* HelpMenu;
    QMenuBar* TopMenuBar;
    QToolBar* MainToolBar;
    QGridLayout* MainLayout;
public slots:
    void OpenFileClicked();
    void OpenFolderClicked();
    void NewFileClicked();
    void NewFolderClicked();
};
#endif // MAINWINDOW_H
