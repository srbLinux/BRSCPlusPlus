#ifndef ABSTRACT_H
#define ABSTRACT_H

/*
 *
 *  CopyRight (C) 2021.10.31
 *  @acthor:handsomerenbin
 *  该头文件定义一些全局变量以解决一些static和其他目前我所知C++知识水平难以解决的问题
 *
*/
#include <QObject>


class Abstract : public QObject
{
    Q_OBJECT
public:
    explicit Abstract(QObject *parent = nullptr);

signals:

};

#endif // ABSTRACT_H
