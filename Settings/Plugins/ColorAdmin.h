#ifndef COLORADMIN_H
#define COLORADMIN_H

/*
 * @brief: the class is a color select class.
 * @version: 1.01
 * @author: handsomerenbin
 *
*/

#include <QLabel>
#include <QWidget>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>

typedef enum Color
{
    HasChanged = 1,
    NotChange = 2
}Color;

class ColorAdmin : public QWidget
{
    Q_OBJECT
public:
    explicit ColorAdmin(QWidget *parent = nullptr);
    Color ReturnAdmin();
private:
    QGridLayout* ColorMainLayout;
    QComboBox* SelectColor;
    QLabel* ColorLabel;
    int ALast;
    QTextEdit* ExampleTextEdit;
public slots:
    void BoxSelectChanged(QString color);
signals:
    void BackgroundColorBroadcast(QString color);
    void FontColorBroadcast(QHash<int,QString> FontColor);
};

#endif // COLORADMIN_H
