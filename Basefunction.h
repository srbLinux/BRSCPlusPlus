#ifndef BASEFUNCTION_H
#define BASEFUNCTION_H

#include <QObject>

class BaseFunction : public QObject
{
    Q_OBJECT
public:
    explicit BaseFunction(QObject *parent = nullptr);
public slots:

signals:

};

#endif // BASEFUNCTION_H
