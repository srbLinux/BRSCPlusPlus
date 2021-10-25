#ifndef NEWFOLDER_H
#define NEWFOLDER_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
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
public slots:
    void GetNameQString();
    void GetPathQString();
signals:

};

#endif // NEWFOLDER_H
