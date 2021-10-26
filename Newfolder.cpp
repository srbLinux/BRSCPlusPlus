#include "Newfolder.h"

NewFolder::NewFolder(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("BRSC++ 新建文件夹"));
    resize(700,450);
    NewLayout = new QGridLayout(this);
    NewNameLabel = new QLabel;
    NewNameLabel->setText(tr("文件夹名称"));
    NewLayout->addWidget(NewNameLabel,0,0);
    NewNameEdit = new QLineEdit;
    NewLayout->addWidget(NewNameEdit,0,1);
    NewPathNameLabel = new QLabel;
    NewPathNameLabel->setText(tr("文件夹路径"));
    NewLayout->addWidget(NewPathNameLabel,1,0);
    NewPathNameLine = new QLineEdit;
    NewLayout->addWidget(NewPathNameLine,1,1);
    BtnLayout = new QHBoxLayout;
    OKBtn = new QPushButton;
    OKBtn->setText(tr("完成"));
    BtnLayout->addWidget(OKBtn);
    ReStartBtn = new QPushButton;
    ReStartBtn->setText(tr("重置"));
    BtnLayout->addWidget(ReStartBtn);
    CancelBtn = new QPushButton;
    CancelBtn->setText(tr("取消"));
    BtnLayout->addWidget(CancelBtn);
    NewLayout->addLayout(BtnLayout,2,2);
}

void NewFolder::OKWindow()
{
    QDir* dir = new QDir();
    dir->mkdir(GetPathQString());
}

void NewFolder::ReStartWindow()
{
    NewNameEdit->clear();
    NewPathNameLine->clear();
}

void NewFolder::CancelWindow()
{
    this->close();
}

QString NewFolder::GetNameQString()
{
    QString Name = NewNameEdit->text();
    return Name;
}

QString NewFolder::GetPathQString()
{
    QString Path = "";
    return Path;
}
