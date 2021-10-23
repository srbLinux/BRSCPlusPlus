#include "Register.h"

Register::Register(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("BRSC++ 注册页面"));
    RegisterMainLayout = new QGridLayout(this);
    UserNameLabel = new QLabel;
    UserNameLabel->setText(tr("用户名"));
    RegisterMainLayout->addWidget(UserNameLabel,0,0);
    UserNameLine = new QLineEdit;
    RegisterMainLayout->addWidget(UserNameLine,0,1);
    UserIconLabel = new QLabel;
    UserIconLabel->setText(tr("选择用户头像"));
    RegisterMainLayout->addWidget(UserIconLabel,1,0);
    /*
        Sex Select !!!
        RegisterSexLayout is the son of RegisterMainLayout !!!
        And There need two public slots:
                one is void SexManisCheckornot();
                another one is void SexWomanCheckronot().
        The Plan is :
                |SexLabel|   |ManBox|   |WomanBox|
    */
    RegisterSexLayout = new QHBoxLayout;
    UserSexLabel = new QLabel;
    UserSexLabel->setText(tr("用户性别"));
    RegisterSexLayout->addWidget(UserSexLabel);
    UserSexCheckBoxMan = new QCheckBox;
    UserSexCheckBoxMan->setText(tr("Man"));
    UserSexCheckBoxWoman = new QCheckBox;
    UserSexCheckBoxWoman->setText(tr("Woman"));
    QButtonGroup* SexGroup = new QButtonGroup(this);
    SexGroup->addButton(UserSexCheckBoxMan,1);
    RegisterSexLayout->addWidget(UserSexCheckBoxMan);
    RegisterSexLayout->addWidget(UserSexCheckBoxWoman);
    SexGroup->addButton(UserSexCheckBoxWoman,2);
    RegisterMainLayout->addLayout(RegisterSexLayout,3,0,1,2);
    //end
    UserAccountLabel = new QLabel;
    UserAccountLabel->setText(tr("用户账号"));
    RegisterMainLayout->addWidget(UserAccountLabel,4,0);
    UserAccountLine = new QLineEdit;
    RegisterMainLayout->addWidget(UserAccountLine,4,1);
    UserPasswordLabel = new QLabel;
    UserPasswordLabel->setText(tr("用户密码"));
    RegisterMainLayout->addWidget(UserPasswordLabel,5,0);
    UserPasswordLine = new QLineEdit;
    RegisterMainLayout->addWidget(UserPasswordLine,5,1);
    UserPasswordAgainLabel = new QLabel;
    UserPasswordAgainLabel->setText(tr("再次输入密码"));
    RegisterMainLayout->addWidget(UserPasswordAgainLabel,6,0);
    UserPasswordAgainLine = new QLineEdit;
    RegisterMainLayout->addWidget(UserPasswordAgainLine,6,1);
    /*
        All QPushButton is there!!!
        The Plan is:
            |RegisterBtn|-->void RegisterCheck()    |ReStartBtn|-->void Restart();
        so We need a QHBoxLayout named RegisterABtnLayout;
        and you konw that this Layout farther is Main
        now coding it !!!
    */
    RegisterABtnLayout = new QHBoxLayout;
    RegisterMainLayout->addLayout(RegisterABtnLayout,7,0,1,2);
    RegisterCheckBtn = new QPushButton;
    RegisterCheckBtn->setText(tr("用户注册"));
    RegisterABtnLayout->addWidget(RegisterCheckBtn);
    connect(RegisterCheckBtn,&QPushButton::clicked,this,&Register::RegisterCheck);
    RegisterReStartBtn = new QPushButton;
    RegisterReStartBtn->setText(tr("重置输入"));
    connect(RegisterReStartBtn,&QPushButton::clicked,this,&Register::ReStart);
    RegisterABtnLayout->addWidget(RegisterReStartBtn);
}

void Register::RegisterCheck()
{
    /*
        Now We need to notice some issues,Register Check divded into several aspects:
            1.Check the cin of PasswordLine and PasswordLineAgain are same?
            2.insert the info to database .
        if not,push a window about Error .
    */
    QString OnceIn = UserPasswordLine->text();
    QString AgainIn = UserPasswordAgainLine->text();
    if(OnceIn != AgainIn)
    {
        QErrorMessage* ErrorWin = new QErrorMessage;
        ErrorWin->setWindowTitle(tr("密码错误"));
        ErrorWin->showMessage(tr("输入密码不匹配"));
    }
    else
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
            QSqlQuery query;
            QString Name = UserNameLine->text();
            QString Account = UserAccountLine->text();
            QString Password = UserPasswordLine->text();
            QString Sex = "";
            QString Icon = "";
            if(UserSexCheckBoxMan->isChecked())
                Sex = "男";
            else
                Sex = "女";
            QString sql = "insert into UserInfo values(\'" + Name + "\',\'" + Account + "\',\'";
            sql += Password + "\',\'" + Sex + "\',\'\')";
            bool execsql = false;
            execsql = query.exec(sql);
            if(execsql == true)
            {
                QMessageBox* msg = new QMessageBox;
                msg->information(NULL,"","注册成功",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
                close();
            }
        }
        else
        {

        }
    }
}


void Register::ReStart()
{
    UserAccountLine->clear();
    UserNameLine->clear();
    UserPasswordAgainLine->clear();
    UserPasswordLine->clear();
}

