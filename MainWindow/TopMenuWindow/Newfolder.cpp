#include "Newfolder.h"

NewFolder::NewFolder(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("BRSC++ 新建项目"));
    resize(1300,700);
    MainLayout = new QHBoxLayout(this);
    NewFolderList = new QListWidget;
    RightLayout = new QVBoxLayout;
    MainLayout->addWidget(NewFolderList);
    MainLayout->addLayout(RightLayout);
    MainLayout->setStretchFactor(NewFolderList,1);
    MainLayout->setStretchFactor(RightLayout,10);
    NewProjectItem = new QListWidgetItem(tr("新建C++项目"),NewFolderList);
    NewPorjectWidget = new QWidget;
    NewStackWidget = new QStackedWidget;
    NewStackWidget->addWidget(NewPorjectWidget);
    SearchBtn = new QPushButton(tr("浏览..."));
}



