#ifndef NEWFOLDER_H
#define NEWFOLDER_H

#include <QDir>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>

class NewFolder : public QWidget
{
    Q_OBJECT
public:
    explicit NewFolder(QWidget *parent = nullptr);
private:
    QLabel* NewNameLabel;
    QLineEdit* NewNameEdit;
    QLabel* NewPathNameLabel;
    QLineEdit* NewPathNameLine;
    QGridLayout* NewLayout;
    QHBoxLayout* BtnLayout;
    QPushButton* OKBtn;
    QPushButton* CancelBtn;
    QPushButton* ReStartBtn;
public slots:
    void CancelWindow();
    void ReStartWindow();
    void OKWindow();
    QString GetNameQString();
    QString GetPathQString();
signals:

};

#endif // NEWFOLDER_H
