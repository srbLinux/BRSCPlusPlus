#ifndef PROJECTFILETREE_H
#define PROJECTFILETREE_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>



class ProjectFileTree : public QDialog
{
    Q_OBJECT
public:
    ProjectFileTree();
};

class NewBuildFile : public QDialog
{
    Q_OBJECT
public:
    explicit NewBuildFile(QDialog* parent = nullptr);
private:
};

class NewBuildFolder : public QDialog
{
    Q_OBJECT
public:
    explicit NewBuildFolder(QDialog* parent = nullptr);
private:
};

class TreeMenu : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeMenu(QTreeWidget* parent = nullptr);
private:
};

#endif // PROJECTFILETREE_H
