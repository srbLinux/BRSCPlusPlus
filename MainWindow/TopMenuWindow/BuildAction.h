#ifndef BUILDACTION_H
#define BUILDACTION_H

#include <cstdio>
#include <QWidget>

class BuildAction : public QWidget
{
    Q_OBJECT
public:
    explicit BuildAction(QWidget *parent = nullptr);
private:
public slots:
signals:

};

class CMakeLog : public QWidget
{
    Q_OBJECT
public:
    explicit CMakeLog(QWidget* parent = nullptr);
private:
public slots:

signals:
};
#endif // BUILDACTION_H
