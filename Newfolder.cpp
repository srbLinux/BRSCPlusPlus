#include "Newfolder.h"

NewFolder::NewFolder(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr(""));
    NewLayout = new QGridLayout(this);
    NewNameLabel = new QLabel;
    NewNameLabel->setText(tr(""));
    NewLayout->addWidget(NewNameLabel,0,0);
    NewNameEdit = new QLineEdit;
    NewLayout->addWidget(NewNameEdit,0,1);
    NewPathNameLabel = new QLabel;
    NewPathNameLabel->setText(tr(""));
    NewLayout->addWidget(NewPathNameLabel,1,0);
    NewPathNameLine = new QLineEdit;
    NewLayout->addWidget(NewPathNameLine,1,1);
}

void NewFolder::GetNameQString()
{

}

void NewFolder::GetPathQString()
{

}
