#include "ProjectFileTree.h"
#include "../../Mainwindow.h"

ProjectFileTree::ProjectFileTree()
{

}

TreeMenu::TreeMenu(QTreeWidget* parent) : QTreeWidget(parent)
{
    this->setObjectName("TreeMenu");
    this->verticalScrollBar()->setObjectName("TreemenuVerticl");
    this->horizontalScrollBar()->setObjectName("TreeMenuHorizontal");
    this->setColumnCount(1);
    this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setAutoScroll(true);
    this->header()->setVisible(false);
    this->setFrameStyle(QFrame::Sunken);
    this->setAnimated(true);
    Newfile = new NewFile();
    connect(Newfile->GetOkBtn(),SIGNAL(clicked(bool)),this,SLOT(BuildNewFile()));
    connect(Newfile->GetCancelBtn(),&QPushButton::clicked,this,&TreeMenu::CloseBuildFile);
    Newfolder = new NewFolder();

}

QString TreeMenu::GetOpenFolder()
{
    return MainWindow::GetOpenFolderName();
}


void TreeMenu::ButtonCollapseItem()
{

}

void TreeMenu::CreateTopItem(QString Path)
{

}

void TreeMenu::FindFile(QDir *Path, QTreeWidgetItem *parent)
{

}

void TreeMenu::DoubleClickPath(QTreeWidgetItem* item,int clomn)
{

}

void TreeMenu::ItemPressd(QTreeWidgetItem* item,int clomn)
{

}

void TreeMenu::TempActionInformation(QAction* action)
{

}

void TreeMenu::BuildNewFile(bool flag)
{

}

void TreeMenu::BuildNewDir(bool flag)
{

}

void TreeMenu::CloseBuildFile(bool flag)
{

}

void TreeMenu::CancelDir(bool flag)
{

}

