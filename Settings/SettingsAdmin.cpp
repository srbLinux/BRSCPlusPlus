#include "SettingsAdmin.h"

SettingsAdmin::SettingsAdmin(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("IDE设置"));
    resize(1400,750);
    MainLayout = new QHBoxLayout(this);
    SettingsListWidget = new QListWidget;
    SettingStackWidget = new QStackedWidget;
    MainLayout->addWidget(SettingsListWidget);
    MainLayout->addWidget(SettingStackWidget);
    MainLayout->setStretchFactor(SettingsListWidget,1);
    MainLayout->setStretchFactor(SettingStackWidget,6);
    fontWindow = new FontAdmin;
    FontListWidgetItem = new QListWidgetItem(tr("设置字体样式和大小"));
    SettingsListWidget->addItem(FontListWidgetItem);
    SettingStackWidget->addWidget(fontWindow);
}
