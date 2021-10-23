#ifndef LOGIN_H
#define LOGIN_H

#include "Register.h"

#include <QSql>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QtSql/QSqlDatabase>

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
private:
    QLabel* UserAccountLabel;
    QLabel* UserPasswordLabel;
    QLineEdit* UserAccountLine;
    QLineEdit* UserPasswordLine;
    QPushButton* CheckBtn;
    QPushButton* ReStartBtn;
    QPushButton* RegisterBtn;
    QGridLayout* LoginLayout;
public slots:
    void LoginCheck();
    void RegisterClicked();
signals:

};

#endif // LOGIN_H
