#include "Newfile.h"

using std::string;

int NewFile::FileSize = 100;

NewFile::NewFile(QWidget *parent) : QWidget(parent)
{
    resize(800,450);
    MainLayout = new QHBoxLayout(this);
    NewFileList = new QListWidget(this);
    FileWidget = new QStackedWidget(this);
    RightLayout = new QVBoxLayout;
    MainLayout->addWidget(NewFileList);
    MainLayout->addLayout(RightLayout);
    MainLayout->setStretchFactor(NewFileList,3);
    MainLayout->setStretchFactor(RightLayout,11);
    ClassFileItem = new QListWidgetItem(tr("新建C++类(.h && .cpp)"),NewFileList);
    CppFileItem = new QListWidgetItem(tr("新建源文件(.cpp)"),NewFileList);
    HeaderFileItem = new QListWidgetItem(tr("新建头文件(.h)"),NewFileList);
    OtherFileItem = new QListWidgetItem(tr("新建其他文件"),NewFileList);
    Classfile = new ClassFile;
    Cppfile = new CppFile;
    Headerfile = new HeaderFile;
    Otherfile = new OtherFile;
    qDebug()<<"1";
    FileWidget->addWidget(Classfile);
    FileWidget->addWidget(Cppfile);
    FileWidget->addWidget(Headerfile);
    FileWidget->addWidget(Otherfile);
    connect(NewFileList,SIGNAL(currentRowChanged(int)),FileWidget,SLOT(setCurrentIndex(int)));
    OkBtn = new QPushButton(tr("确认"));
    CancelBtn = new QPushButton(tr("取消"));
    BtnLayout = new QHBoxLayout;
    QLabel* ERROR = new QLabel;
    BtnLayout->addWidget(ERROR);
    BtnLayout->addWidget(OkBtn);
    BtnLayout->addWidget(CancelBtn);
    BtnLayout->setStretchFactor(ERROR,4);
    BtnLayout->setStretchFactor(OkBtn,1);
    BtnLayout->setStretchFactor(CancelBtn,1);
    RightLayout->addWidget(FileWidget);
    RightLayout->addLayout(BtnLayout);
    RightLayout->setParent(MainLayout);
    connect(OkBtn,SIGNAL(clicked()),this,SLOT(OkBtnClicked()));
    connect(CancelBtn,&QPushButton::clicked,this,&NewFile::CancelBtnClicked);
}

void NewFile::OkBtnClicked()
{
    if(Classfile->ClassNameLine->text() != nullptr)
        FileSize = CLASS;
    else if(Cppfile->CppNameLine->text() != nullptr)
        FileSize = CPP;
    else if(Headerfile->LineText() == false)
        FileSize = HEADER;
    else if(Otherfile->LineText() == false)
        FileSize = OTHER;
    if(FileSize == CLASS)
    {
        if(this->Classfile->HeaderNameChanged() == false && this->Classfile->CppNameChanged() == false \
               && this->Classfile->CppNameChanged() == false && this->Classfile->PathIsRight() == false)
        {
                qDebug()<<"CLASS";
                QString Path = Classfile->PathNameLine->text();
                QString DEFINE = Classfile->ClassNameLine->text().toUpper() + "_H";
                QString Class_h = "#ifndef " + DEFINE + "\n" + "#define " + DEFINE + "\n";
                Class_h += "#include <iostream>\n\
        using namespace std;\nclass " + Classfile->ClassNameLine->text() +"\n\
        {\n\
            public:\n\
                explicit " + Classfile->ClassNameLine->text() +"();\n\
                ~" + Classfile->ClassNameLine->text() + "();\n\
            private:\n\
        };\n";
                QString Class_cpp = "#include \"../include/" + Classfile->HeaderNameLine->text() +"\"\n\
        " + Classfile->ClassNameLine->text() + "::" + Classfile->ClassNameLabel->text() + "()\n\
        {\n\n\n}\n" + Classfile->ClassNameLine->text() + "::~" + Classfile->ClassNameLine->text() + "()\n{\n\n}\n";
                QDir dir;
                QString CPPNAME = Cppfile->CppNameLine->text();
                QString HEADERNAME = Headerfile->HeaderNameLine->text();
                if(dir.exists(Path + "/src") && dir.exists(Path + "/include"))
                {
                    QFile fp0(Path + "/src/" + CPPNAME);
                    QString path0 = Path + "/src/" + CPPNAME;
                    QString path1 = Path + "/include/" + HEADERNAME;
                    qDebug()<<path0<<" "<<path1;
                    #ifdef __linux__
                    string str0 = "touch " + path0.toStdString();
                    const char* cmd0 = str0.c_str();
                    popen(cmd0,"w");
                    string str1 = "touch " + path1.toStdString();
                    const char* cmd1 = str1.c_str();
                    popen(cmd1,"w");
                    #elif _WIN32
                    #endif
                    fp0.open(QIODevice::ReadWrite | QIODevice::Text);
                    string _cpp = Class_cpp.toStdString();
                    fp0.write(_cpp.c_str());
                    fp0.close();
                    QFile fp1(Path + "/include" + HEADERNAME);
                    fp1.open(QIODevice::ReadWrite | QIODevice::Text);
                    string _h = Class_h.toStdString();
                    fp1.write(_h.c_str());
                    fp1.close();
                    close();
                }
                else
                {
                    QFile fp0(Path + "/" + CPPNAME);
                    QString path0 = Path + "/src/" + CPPNAME;
                    QString path1 = Path + "/include/" + HEADERNAME;
                    qDebug()<<path0<<" "<<path1;
                    #ifdef __linux__
                    string str0 = "touch " + path0.toStdString();
                    const char* cmd0 = str0.c_str();
                    popen(cmd0,"w");
                    string str1 = "touch " + path1.toStdString();
                    const char* cmd1 = str1.c_str();
                    popen(cmd1,"w");
                    #elif _WIN32
                    #endif
                    fp0.open(QIODevice::ReadWrite | QIODevice::Text);
                    string _cpp = Class_cpp.toStdString();
                    string _h = Class_h.toStdString();
                    fp0.write(_cpp.c_str());
                    fp0.close();
                    QFile fp1(Path + "/" + HEADERNAME);
                    fp1.open(QIODevice::ReadWrite | QIODevice::Text);
                    fp1.write(_h.c_str());
                    fp1.close();
                    close();
                }
            }
            else
            {
                QErrorMessage* errormsg = new QErrorMessage;
                errormsg->setWindowTitle(tr("命名错误"));
                errormsg->showMessage(tr("C++类命名错误！！！"));
            }
    }
    else if(FileSize == CPP)
    {
        QString CPPName = Cppfile->CppNameLine->text();
        QString Path = Cppfile->PathNameLine->text();
        QFile file(Path + "/" + CPPName);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        string _cpp = "#include <iostream>\nint main\n{\n   return 0;\n}\n";
        file.write(_cpp.c_str());
        //file.close();
        close();
    }
    else if(FileSize == HEADER)
    {
        QString HeaderName = Headerfile->HeaderNameLine->text();
        QString Path = Headerfile->PathNameLine->text();
        QString Define = HeaderName.toUpper();
        QFile file(Path + "/" + HeaderName);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QString Header = "#ifndef " + Define +"\n#define" + Define + "\n#endif";
        string _h = Header.toStdString();
        file.write(_h.c_str());
        file.close();
        close();
    }
    else if(FileSize == OTHER)
    {
        QString OtherName = Otherfile->OtherNameLine->text();
        QString Path = Otherfile->PathNameLine->text();
        QFile file(Path + "/" + OtherName);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.close();
        close();
    }
}

void NewFile::CancelBtnClicked()
{
    this->close();
}

ClassFile::ClassFile(QWidget* parent) : QWidget(parent)
{
    ClassGridLayout = new QGridLayout(this);
    ClassNameLabel = new QLabel(tr("C++类名"));
    ClassNameLine = new QLineEdit();
    CppNameLabel = new QLabel(tr("源文件名称(.cpp)"));
    CppNameLine = new QLineEdit();
    HeaderNameLabel = new QLabel(tr("头文件名称(.h)"));
    HeaderNameLine = new QLineEdit;
    PathNameLabel = new QLabel(tr("C++类路径"));
    PathNameLine = new QLineEdit();
    ClassSearchBtn = new QPushButton(tr("浏览..."));
    ClassGridLayout->addWidget(ClassNameLabel,0,0);
    ClassGridLayout->addWidget(ClassNameLine,0,1,1,2);
    ClassGridLayout->addWidget(CppNameLabel,1,0);
    ClassGridLayout->addWidget(CppNameLine,1,1,1,2);
    ClassGridLayout->addWidget(HeaderNameLabel,2,0);
    ClassGridLayout->addWidget(HeaderNameLine,2,1,1,2);
    ClassGridLayout->addWidget(PathNameLabel,3,0);
    ClassGridLayout->addWidget(PathNameLine,3,1);
    ClassGridLayout->addWidget(ClassSearchBtn,3,2);
    connect(ClassNameLine,&QLineEdit::textChanged,this,&ClassFile::ClassNameChanged);
    connect(CppNameLine,&QLineEdit::textChanged,this,&ClassFile::CppNameChanged);
    connect(HeaderNameLine,&QLineEdit::textChanged,this,&ClassFile::HeaderNameChanged);
    connect(ClassSearchBtn,&QPushButton::clicked,this,&ClassFile::PathIsRight);
}

bool ClassFile::ClassNameChanged()
{
    using std::iterator;
    int boolean = 0;
    QString Classname = ClassNameLine->text();
    string name = Classname.toStdString();
    if((name[0] >= 'A' && name[0] <= 'Z') || (name[0] >= 'a' && name[0] <= 'z') || name[0] == '_')
    {
        for(string::iterator itor = name.begin() + 1;itor < name.end() - 1;itor++)
        {
            if(!((*itor >= 'A' && *itor <= 'Z') || (*itor >= 'a' && *itor <= 'z') || (*itor >= '0' && *itor <= '9') || *itor == '_'))
            {
                boolean = 1;
            }
        }
        if(boolean == 0)
        {
            CppNameLine->setText(ClassNameLine->text() + ".cpp");
            HeaderNameLine->setText(ClassNameLine->text() + ".h");
            return false;
        }
        else
            return true;
    }
    else
        return true;
}

bool ClassFile::CppNameChanged()
{
    QString CppName = CppNameLine->text();
    string name = CppName.toStdString();
    int length = name.size();
    bool boolean = false;
    for(int i = 0;i < length - 7;i++)
    {
        if(name[i] == '.')
        {
            if(name[i + 1] == 'c' && name[i + 2] == 'p' && name[i + 3] == 'p')
                boolean = true;
        }
    }
    if(boolean == true)
        return true;
    else
        return false;
}

bool ClassFile::PathIsRight()
{
    PathNameLine->setText(QFileDialog::getExistingDirectory());
    string Path = PathNameLine->text().toStdString();
    string FolderName = "";
    for(int i = Path.size() - 1;i >= 0;i--)
    {
        if(Path[i] != '/')
            FolderName += Path[i];
        else
            break;
    }
    if(FolderName == "src" || FolderName == "include" || FolderName == "build")
        return true;
    else
        return false;
}

bool ClassFile::HeaderNameChanged()
{
    QString HeaderName = HeaderNameLine->text();
    string name = HeaderName.toStdString();
    int length = name.size();
    bool boolean = false;
    for(int i = 0;i < length - 4;i++)
    {
        if(name[i] == '.')
        {
            if(name[i + 1] == 'h')
                boolean = true;
        }
    }
    if(boolean == true)
        return true;
    else
        return false;
}

CppFile::CppFile(QWidget* parent) : QWidget(parent)
{
    MainLayout = new QGridLayout(this);
    CppNameLabel = new QLabel(tr("源文件名称(.cpp)"));
    CppNameLine = new QLineEdit;
    PathNameLabel = new QLabel(tr("新建源文件路径"));
    PathNameLine = new QLineEdit;
    SearchPathBtn = new QPushButton(tr("浏览..."));
    MainLayout->addWidget(CppNameLabel,0,0);
    MainLayout->addWidget(CppNameLine,0,1);
    MainLayout->addWidget(PathNameLabel,1,0);
    MainLayout->addWidget(PathNameLine,1,1);
    MainLayout->addWidget(SearchPathBtn,1,2);
    connect(SearchPathBtn,&QPushButton::clicked,this,&CppFile::SearchBtnClicked);
}

void CppFile::SearchBtnClicked()
{
    PathNameLine->setText(QFileDialog::getExistingDirectory());
}

HeaderFile::HeaderFile(QWidget* parent) : QWidget(parent)
{
    MainLayout = new QGridLayout(this);
    HeaderNameLabel = new QLabel(tr("头文件名称(.h)"));
    HeaderNameLine = new QLineEdit;
    PathNameLabel = new QLabel(tr("新建头文件路径"));
    PathNameLine = new QLineEdit;
    SearchPathBtn = new QPushButton(tr("浏览..."));
    MainLayout->addWidget(HeaderNameLabel,0,0);
    MainLayout->addWidget(HeaderNameLine,0,1);
    MainLayout->addWidget(PathNameLabel,1,0);
    MainLayout->addWidget(PathNameLine,1,1);
    MainLayout->addWidget(SearchPathBtn,1,2);
    connect(SearchPathBtn,&QPushButton::clicked,this,&HeaderFile::SearchBtnClicked);
}

void HeaderFile::SearchBtnClicked()
{
    PathNameLine->setText(QFileDialog::getExistingDirectory());
}

bool HeaderFile::LineText() const
{
    if(HeaderNameLine->text() == nullptr)
        return true;
    else
        return false;
}

OtherFile::OtherFile(QWidget* parent) : QWidget(parent)
{
    MainLayout = new QGridLayout(this);
    OtherNameLabel = new QLabel(tr("其他文件名称"));
    OtherNameLine = new QLineEdit;
    PathNameLabel = new QLabel(tr("新建其他文件路径"));
    PathNameLine = new QLineEdit;
    SearchPathBtn = new QPushButton(tr("浏览..."));
    MainLayout->addWidget(OtherNameLabel,0,0);
    MainLayout->addWidget(OtherNameLine,0,1);
    MainLayout->addWidget(PathNameLabel,1,0);
    MainLayout->addWidget(PathNameLine,1,1);
    MainLayout->addWidget(SearchPathBtn,1,2);
    connect(SearchPathBtn,&QPushButton::clicked,this,&OtherFile::SearchBtnClicked);
}

void OtherFile::SearchBtnClicked()
{
    PathNameLine->setText(QFileDialog::getExistingDirectory());
}

bool OtherFile::LineText() const
{
    if(OtherNameLine->text() == nullptr)
        return true;
    else
        return false;
}
