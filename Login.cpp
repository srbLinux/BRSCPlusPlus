#include "Login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("BRSC++   登录页面"));
    LoginLayout = new QGridLayout(this);
    UserAccountLabel = new QLabel;
    UserAccountLabel->setText(tr("用户账号"));
    LoginLayout->addWidget(UserAccountLabel,0,0);
    UserAccountLine = new QLineEdit;
    LoginLayout->addWidget(UserAccountLine,0,1);
    UserPasswordLabel = new QLabel;
    UserPasswordLabel->setText(tr("用户密码"));
    LoginLayout->addWidget(UserPasswordLabel,1,0);
    UserAccountLine = new QLineEdit;
    LoginLayout->addWidget(UserAccountLine,1,1);
    CheckBtn = new QPushButton;
    CheckBtn->setText(tr("用户登录"));
    LoginLayout->addWidget(CheckBtn,2,0);
    RegisterBtn = new QPushButton;
    RegisterBtn->setText(tr("用户注册"));
    LoginLayout->addWidget(RegisterBtn,2,1);
    ReStartBtn = new QPushButton;
    ReStartBtn->setText(tr("重置输入"));
    LoginLayout->addWidget(ReStartBtn,2,2);
    connect(ReStartBtn,&QPushButton::clicked,this,&Login::ReStart);
    connect(CheckBtn,&QPushButton::clicked,this,&Login::LoginCheck);
    connect(RegisterBtn,&QPushButton::clicked,this,&Login::RegisterClicked);
}

void Login::ReStart()
{
    UserAccountLine->clear();
    UserPasswordLine->clear();
}

void Login::RegisterClicked()
{
    Register* regWin = new Register;
    regWin->show();
}

//no finish
void Login::LoginCheck()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("BRSCPlusPlus");
    db.setPassword("123");
    bool DBOpen = db.open();
    if(DBOpen == true)
    {

    }
}
