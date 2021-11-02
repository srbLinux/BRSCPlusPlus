#ifndef FONTADMIN_H
#define FONTADMIN_H

#include <QMap>
#include <QWidget>
#include <QGridLayout>

typedef enum Font
{
    FontChanged = 0,
    FontNotChange = 1
}Font;

class FontAdmin : public QWidget
{
    Q_OBJECT
public:
    explicit FontAdmin(QWidget *parent = nullptr);
private:
    QMap<int,QString> FontInfo;
public slots:

signals:

};

#endif // FONTADMIN_H
