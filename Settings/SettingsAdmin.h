#ifndef SETTINGSADMIN_H
#define SETTINGSADMIN_H

/*
 *
 *  @file: Settings/SettingAdmin.h
 *  @brief: class SettingAdmin will Admin all Setting.
 *  @author: handsomerenbin
 *  @date: 2021.110.01
 *  @version: 1.01
*/

#include "./Plugins/FontAdmin.h"
#include "./Plugins/ColorAdmin.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>

class SettingsAdmin : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsAdmin(QWidget *parent = nullptr);
private:
    FontAdmin* fontWindow;
    ColorAdmin* colorWindow;
    QHBoxLayout* MainLayout;
    QVBoxLayout* TheLastLayout;
    QHBoxLayout* AllBtnLayout;
    QPushButton* ApplyBtn;
    QPushButton* CancelBtn;
    QPushButton* ReStartBtn;
    QListWidget* SettingsListWidget;
    QStackedWidget* SettingStackWidget;
    QListWidgetItem* FontListWidgetItem;
    QListWidgetItem* ColorListWidgetItem;
public slots:
    void ApplyBtnClicked();
signals:

};

#endif // SETTINGSADMIN_H
