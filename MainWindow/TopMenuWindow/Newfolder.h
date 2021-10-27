#ifndef NEWFOLDER_H
#define NEWFOLDER_H

#include <QDir>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QSplitter>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QStackedWidget>
#include <QDesktopServices>

class NewFolder : public QWidget
{
    Q_OBJECT
public:
    explicit NewFolder(QWidget *parent = nullptr);
private:
    QHBoxLayout* MainLayout;
    QVBoxLayout* RightLayout;
    QListWidget* NewFolderList;
    QStackedWidget* NewStackWidget;
    QWidget* NewPorjectWidget;
    QPushButton* SearchBtn;
    QListWidgetItem* NewProjectItem;
public slots:
signals:

};

#endif // NEWFOLDER_H
