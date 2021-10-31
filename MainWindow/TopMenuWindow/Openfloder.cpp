#include "Openfloder.h"

OpenFolder::OpenFolder(QWidget *parent) : QWidget(parent)
{
    OpenFloderAction = new QAction(this);
    connect(OpenFloderAction,&QAction::triggered,this,&OpenFolder::OpenAction);
}

void OpenFolder::OpenAction()
{

}
