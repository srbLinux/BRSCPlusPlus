#ifndef PROJECTFILETREE_H
#define PROJECTFILETREE_H

#include "../TopMenuWindow/Newfile.h"
#include "../TopMenuWindow/Newfolder.h"
#include "../TopMenuWindow/Openfloder.h"

#include <QMenu>
#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class ProjectFileTree : public QDialog
{
    Q_OBJECT
public:
    explicit ProjectFileTree();
};

class TreeMenu : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeMenu(QTreeWidget* parent = nullptr);
    QString GetOpenFolder();
    void CreateTopItem(QString Path);
    void FindFile(QDir* Path,QTreeWidgetItem* parent);
    void ButtonCollapseItem();
private:
    int NowCol;
    QMenu* DirMenu;
    QAction* NewFileAction;
    QAction* RenameDirAction;
    QAction* NewFolderAction;
    QAction* DeleteFolderAction;
    QAction* SearchInFolderAction;
    QAction* CloseProjectAction;
    QMenu* FileMenu;
    QAction* RenameFileAction;
    QAction* DeleteFileAction;
    QAction* OpenFloderAction;
    NewFile* Newfile;
    NewFolder* Newfolder;
    OpenFolder* Openfolder;
    QTreeWidgetItem* Root;
    QTreeWidgetItem* NowItem;
signals:
    void ShowTextSignal(QString Path,QString Name,QTreeWidgetItem* item);
    void CollapseItemSignal(const QTreeWidgetItem* item);
    void RenameSignal();
public slots:
    void DoubleClickPath(QTreeWidgetItem* item,int cloumn);
    void ItemPressd(QTreeWidgetItem* pressedItem,int cloumn);
    void TempActionInformation(QAction* action);
    void BuildNewFile(bool flag);
    void CloseBuildFile(bool flag);
    void BuildNewDir(bool flag);
    void CancelDir(bool flag);
};

#endif // PROJECTFILETREE_H
