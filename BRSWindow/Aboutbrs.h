#ifndef ABOUTBRS_H
#define ABOUTBRS_H

#include <QLabel>
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class AboutBRS : public QDialog
{
public:
    AboutBRS();
private:
    QLabel* BRSVersionLabel;
    QPushButton* OKBtn;
    QGridLayout* AboutBRSLayout;
public slots:
    void OKBtnClicked();
};

#endif // ABOUTBRS_H
