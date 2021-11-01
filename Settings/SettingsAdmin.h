#ifndef SETTINGSADMIN_H
#define SETTINGSADMIN_H

#include "./Plugins/FontAdmin.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QStackedWidget>

class SettingsAdmin : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsAdmin(QWidget *parent = nullptr);
private:
    FontAdmin* fontWindow;
    QHBoxLayout* MainLayout;
    QListWidget* SettingsListWidget;
    QStackedWidget* SettingStackWidget;
    QListWidgetItem* FontListWidgetItem;
    QListWidgetItem* BackgroudWidgetItem;
public slots:

signals:

};

#endif // SETTINGSADMIN_H
