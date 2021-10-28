#include "Newfolder.h"

NewFolder::NewFolder(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("BRSC++ 新建项目"));
    resize(800,400);
    MainLayout = new QHBoxLayout(this);
    NewFolderList = new QListWidget;
    NewStackWidget = new QStackedWidget;
    MainLayout->addWidget(NewFolderList);
    MainLayout->addWidget(NewStackWidget);
    MainLayout->setStretchFactor(NewFolderList,1);
    MainLayout->setStretchFactor(NewStackWidget,5);
    NewProjectItem = new QListWidgetItem(tr("新建C++项目"),NewFolderList);
    NewPorjectWidget = new QWidget;
    QGridLayout* NewProjectLayout = new QGridLayout(NewPorjectWidget);
    QLabel* NameLabel = new QLabel(tr("项目名称"),NewPorjectWidget);
    NameLine = new QLineEdit(NewPorjectWidget);
    QLabel* PathNameLabel = new QLabel(tr("项目位置"),NewPorjectWidget);
    PathNameLine = new QLineEdit(NewPorjectWidget);
    SearchBtn = new QPushButton(tr("浏览..."));
    CancelBtn = new QPushButton(tr("取消"));
    OkBtn = new QPushButton(tr("确认"));
    NewProjectLayout->addWidget(NameLabel,1,0);
    NewProjectLayout->addWidget(NameLine,1,1);
    NewProjectLayout->addWidget(PathNameLabel,2,0);
    NewProjectLayout->addWidget(PathNameLine,2,1);
    NewProjectLayout->addWidget(SearchBtn,2,2);
    NewProjectLayout->addWidget(CancelBtn,3,4);
    NewProjectLayout->addWidget(OkBtn,3,5);
    NewStackWidget->addWidget(NewPorjectWidget);
    connect(OkBtn,&QPushButton::clicked,this,&NewFolder::OKBtnClicked);
    connect(CancelBtn,&QPushButton::clicked,this,&NewFolder::CancelClicked);
    connect(SearchBtn,&QPushButton::clicked,this,&NewFolder::SearchClicked);
    connect(NewFolderList,SIGNAL(currentRowChanged(int)),NewStackWidget,SLOT(setCurrentIndex(int)));
}

void NewFolder::CancelClicked()
{
    close();
}

void NewFolder::OKBtnClicked()
{
    QString Path = PathNameLine->text() + NameLine->text();
    QDir dir;
    QString CMakeConcent = "cmake_minimum_required(VERSION 3.5)\n\
project(TEXT)\n\
set(CMAKE_CXX_STANDARD 17)\n\
set(PROJECT_SOURCES\n\
   src/main.cpp\n\
   include/main.h\n\
   )\n\
add_executable(TEXT ${PROJECT_SOURCES})\n\
";
    QString main_cpp = "#include \"../include/main.h\"\n\
int main()\n\
{\n\
    return 0;\n\
}\n";
    QString main_h = "#ifndef MAIN_H\n\
#define MAIN_H\n\
#include <iostream>\n\
using namespace std;\n\
class Main{\n\
};\n\
#endif";
    dir.mkdir(Path);
    qDebug()<<CMakeConcent;
    QString src = Path + "/src";
    QString include =  Path + "/include";
    QString build = Path + "/build";
    dir.mkdir(src);
    dir.mkdir(include);
    dir.mkdir(build);
    QString CMake = Path + "/CMakeLists.txt";
    QFile file(CMake);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    std::string str = CMakeConcent.toStdString();
    const char* str1 = str.c_str();
    file.write(str1);
    file.close();
    QFile maincpp(Path + "/src/main.cpp");
    maincpp.open(QIODevice::ReadWrite | QIODevice::Text);
    std::string cpp = main_cpp.toStdString();
    maincpp.write(cpp.c_str());
    maincpp.close();
    QFile header(Path + "/include/main.h");
    header.open(QIODevice::ReadWrite | QIODevice::Text);
    std::string mainheader = main_h.toStdString();
    header.write(mainheader.c_str());
    header.close();
    close();
}

void NewFolder::SearchClicked()
{
    PathNameLine->setText(QFileDialog::getExistingDirectory());
}



