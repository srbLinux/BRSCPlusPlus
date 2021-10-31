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
    QPushButton* GetOkBtn() const;
    QPushButton* GetCancelBtn() const;
private:
    QHBoxLayout* MainLayout;
    QVBoxLayout* RightLayout;
    QListWidget* NewFolderList;
    QStackedWidget* NewStackWidget;
    QWidget* NewPorjectWidget;
    QLineEdit* PathNameLine;
    QLineEdit* NameLine;
    QPushButton* SearchBtn;
    QPushButton* CancelBtn;
    QPushButton* OkBtn;
    QListWidgetItem* NewProjectItem;
public slots:
    void SearchClicked();
    void OKBtnClicked();
    void CancelClicked();
signals:

};

#endif // NEWFOLDER_H
