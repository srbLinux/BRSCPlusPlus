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
    void CreateTreeRoot();
    QString GetOpenFolder();
    QString GetFileFormat(QString FileName);
    void SetProjectFileTree(QDir* Path,QTreeWidgetItem* parent);
    explicit TreeMenu(QTreeWidget* parent = nullptr);
private:
    QTreeWidgetItem* RootTreeItem;

signals:
    void MyItemDoubleClicked(QString AbsolutePath);
public slots:
    void DoubleClickedPath(QTreeWidgetItem* item,int column);
};

#endif // PROJECTFILETREE_H
