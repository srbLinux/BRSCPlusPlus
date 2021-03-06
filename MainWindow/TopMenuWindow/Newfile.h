#ifndef NEWFILE_H
#define NEWFILE_H

#include <QDir>
#include <mutex>
#include <thread>
#include <cstdio>
#include <QLabel>
#include <QWidget>
#include <unistd.h>
#include <QtWidgets>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QStackedWidget>
#include <QListWidgetItem>

class ClassFile;
class CppFile;
class HeaderFile;
class OtherFile;
/*
 *
 *  CopyRight (C) 2021.11.03
 *  @author:handsomerenbin
 *  @version: 1.01
 *  add something about more size
 *
*/

typedef enum SelectFile
{
    CLASS = 0,
    CPP = 1,
    HEADER = 2,
    OTHER = 3
}SelectFile;

class NewFile : public QWidget
{
    Q_OBJECT
public:
    explicit NewFile(QWidget *parent = nullptr);
    QPushButton* GetOkBtn() const;
    QPushButton* GetCancelBtn() const;
    static int FileSize;
    void OTHERFuction();
    void HEADERFuction();
    void CPPFuction();
    void CLASSFuction();
private:
    std::mutex File;
    QHBoxLayout* MainLayout;
    QListWidget* NewFileList;
    QListWidgetItem* ClassFileItem;
    QListWidgetItem* CppFileItem;
    QListWidgetItem* HeaderFileItem;
    QListWidgetItem* OtherFileItem;
    QStackedWidget* FileWidget;
    QWidget* ClassFileWidget;
    ClassFile* Classfile;
    CppFile* Cppfile;
    HeaderFile* Headerfile;
    OtherFile* Otherfile;
    QVBoxLayout* RightLayout;
    QHBoxLayout* BtnLayout;
    QPushButton* CancelBtn;
    QPushButton* OkBtn;
public slots:
    void OkBtnClicked();
    void CancelBtnClicked();
signals:
    void BroadcastCreated(int);
};

class ClassFile : public QWidget
{
    Q_OBJECT
    friend class NewFile;
public:
    explicit ClassFile(QWidget* parent = nullptr);
private:
    QGridLayout* ClassGridLayout;
    QLabel* ClassNameLabel;
    QLineEdit* ClassNameLine;
    QLabel* CppNameLabel;
    QLineEdit* CppNameLine;
    QLabel* HeaderNameLabel;
    QLineEdit* HeaderNameLine;
    QLabel* PathNameLabel;
    QLineEdit* PathNameLine;
    QPushButton* ClassSearchBtn;
    #define CLASSFILE
public slots:
    bool PathIsRight();
    bool CppNameChanged();
    bool ClassNameChanged();
    bool HeaderNameChanged();
};

class CppFile : public QWidget
{
    Q_OBJECT
    friend class NewFile;
public:
    explicit CppFile(QWidget* parent = nullptr);
private:
    QGridLayout* MainLayout;
    QLabel* CppNameLabel;
    QLineEdit* CppNameLine;
    QLabel* PathNameLabel;
    QLineEdit* PathNameLine;
    QPushButton* SearchPathBtn;
public slots:
    void SearchBtnClicked();
};

class HeaderFile : public QWidget
{
    Q_OBJECT
    friend class NewFile;
public:
    bool LineText() const;
    explicit HeaderFile(QWidget* parent = nullptr);
private:
    QGridLayout* MainLayout;
    QLabel* HeaderNameLabel;
    QLineEdit* HeaderNameLine;
    QLabel* PathNameLabel;
    QLineEdit* PathNameLine;
    QPushButton* SearchPathBtn;
public slots:
    void SearchBtnClicked();
};

class OtherFile : public QWidget
{
    Q_OBJECT
    friend class NewFile;
public:
    bool LineText() const;
    explicit OtherFile(QWidget* parent = nullptr);
private:
    QGridLayout* MainLayout;
    QLabel* OtherNameLabel;
    QLineEdit* OtherNameLine;
    QLabel* PathNameLabel;
    QLineEdit* PathNameLine;
    QPushButton* SearchPathBtn;
public slots:
    void SearchBtnClicked();
};

#endif // NEWFILE_H
