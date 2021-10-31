#ifndef OPENFOLDER_H
#define OPENFOLDER_H

#include <QWidget>
#include <QAction>

class OpenFolder : public QWidget
{
    Q_OBJECT
public:
    explicit OpenFolder(QWidget *parent = nullptr);
private:
    QAction* OpenFloderAction;
public slots:
    void OpenAction();
signals:

};

#endif // OPENFOLDER_H
