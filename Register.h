#ifndef REGISTER_H
#define REGISTER_H

#include <QtSql>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QButtonGroup>
#include <QSqlDatabase>
#include <QErrorMessage>

class Register : public QWidget
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);
private:
    QLabel* UserSexLabel;
    QLabel* UserNameLabel;
    QLabel* UserIconLabel;
    QLabel* UserAccountLabel;
    QLabel* UserPasswordLabel;
    QLabel* UserPasswordAgainLabel;
    QLineEdit* UserNameLine;
    QLineEdit* UserAccountLine;
    QLineEdit* UserPasswordLine;
    QLineEdit* UserPasswordAgainLine;
    QCheckBox* UserSexCheckBoxMan;
    QCheckBox* UserSexCheckBoxWoman;
    QPushButton* UserSexCheckBtn;
    QPushButton* RegisterCheckBtn;
    QPushButton* RegisterReStartBtn;
    QVBoxLayout* RegisterIconLayout;
    QHBoxLayout* RegisterSexLayout;
    QHBoxLayout* RegisterABtnLayout;
    QGridLayout* RegisterMainLayout;
public slots:
    void RegisterCheck();
    void ReStart();
signals:

};

#endif // REGISTER_H
