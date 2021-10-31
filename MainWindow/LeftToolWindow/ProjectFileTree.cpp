#include "ProjectFileTree.h"
#include "../../Mainwindow.h"

#include <QDebug>

ProjectFileTree::ProjectFileTree()
{

}

TreeMenu::TreeMenu(QTreeWidget* parent) : QTreeWidget(parent)
{
    setColumnCount(1);
    setHeaderLabel(tr("资源管理器"));
    CreateTreeRoot();
}

void TreeMenu::CreateTreeRoot()
{
    QDir* dir = new QDir(GetOpenFolder());
    qDebug()<<"TreeMenu: "<<GetOpenFolder();
    RootTreeItem = new QTreeWidgetItem();
    this->addTopLevelItem(RootTreeItem);
    RootTreeItem->setText(0,dir->dirName());
    SetProjectFileTree(dir,RootTreeItem);
}

void TreeMenu::SetProjectFileTree(QDir *Path, QTreeWidgetItem *parent)
{
    QStringList AllFileName = Path->entryList();
    QString PathName = Path->absolutePath();
    for(int i = 2;i < AllFileName.size();i++)
    {
        QFileInfo* FileInfo = new QFileInfo(PathName + "/" + AllFileName[i]);
        if(FileInfo->isFile())
        {
            if(GetFileFormat(AllFileName[i]) == ".cpp")
            {
                //qDebug()<<".CPP: "<<AllFileName[i];
                QTreeWidgetItem* item = new QTreeWidgetItem(parent);
                item->setText(0,AllFileName[i]);
                item->setIcon(0,QIcon(":/RunImage/Image/cpp.png"));
                item->setToolTip(0,PathName + "/" + AllFileName[i]);
            }
            else if(GetFileFormat(AllFileName[i]) == ".h")
            {
                QTreeWidgetItem* item = new QTreeWidgetItem(parent);
                item->setText(0,AllFileName[i]);
                item->setIcon(0,QIcon(":/RunImage/Image/header.png"));
                item->setToolTip(0,PathName + "/" + AllFileName[i]);
            }
            else if(GetFileFormat(AllFileName[i]) == nullptr)
            {
                QTreeWidgetItem* item = new QTreeWidgetItem(parent);
                item->setText(0,AllFileName[i]);
                item->setIcon(0,QIcon(":/RunImage/Image/其他文件.png"));
                item->setToolTip(0,PathName + "/" + AllFileName[i]);
            }
        }
        else if(FileInfo->isDir())
        {
            QTreeWidgetItem* item = new QTreeWidgetItem(parent);
            item->setText(0,AllFileName[i]);
            item->setIcon(0,QIcon(":/RunImage/Image/Folder.png"));
            item->setToolTip(0,PathName + "/" + AllFileName[i]);
            QDir* son = new QDir(PathName + "/" + AllFileName[i]);
            SetProjectFileTree(son,item);
        }
    }
}

QString TreeMenu::GetFileFormat(QString FileName)
{
    QString Format = "";
    for(int i = FileName.size() - 1;i >= 0;i--)
    {
        if(FileName[i] != '.')
            Format.push_front(FileName[i]);
        else
        {
            Format.push_front(FileName[i]);
            break;
        }
    }
    //qDebug()<<Format;
    return Format;
}

QString TreeMenu::GetOpenFolder()
{
    return MainWindow::GetOpenFolderName();
}

