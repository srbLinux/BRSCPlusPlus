#ifndef NEWFILE_H
#define NEWFILE_H

#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class NewFile : public QWidget
{
    Q_OBJECT
public:
    explicit NewFile(QWidget *parent = nullptr);
private:
    QHBoxLayout* MainLayout;

signals:

};

#endif // NEWFILE_H
