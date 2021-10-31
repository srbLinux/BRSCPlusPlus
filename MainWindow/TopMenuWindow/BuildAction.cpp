#include "BuildAction.h"
#include "../../Mainwindow.h"

using std::string;

BuildAction::BuildAction(QWidget *parent) : QWidget(parent)
{
    QString ProjectName = MainWindow::ProjectName;
    qDebug()<<ProjectName;
    #ifdef __linux__
    string cmd = "cd " + ProjectName.toStdString();
    popen(cmd.c_str(),"w");
    QDir dir(ProjectName);
    if(dir.exists(ProjectName + "/build") == false)
        popen("mkdir build","w");
    popen("cd build","w");
    FILE* fp = popen("cmake ..","w");
    if(fp == nullptr)
    {

    }
    #endif
    #ifdef _WIN32

    #endif
}

CMakeLog::CMakeLog(QWidget* parent) : QWidget(parent)
{

}
