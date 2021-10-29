#ifndef ALLDIALOG_H
#define ALLDIALOG_H

#include <QDialog>

class AllDialog : public QDialog
{
public:
    explicit AllDialog(QDialog* parent = nullptr);
private:
public slots:
};

class AboutBRS : public QDialog
{
public:
    explicit AboutBRS(QDialog* parent = nullptr);
private:
public slots:
};

#endif // ALLDIALOG_H
