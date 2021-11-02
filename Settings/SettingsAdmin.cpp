#include "SettingsAdmin.h"

SettingsAdmin::SettingsAdmin(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("IDE设置"));
    resize(1100,640);
    MainLayout = new QHBoxLayout(this);
    TheLastLayout = new QVBoxLayout();
    AllBtnLayout = new QHBoxLayout();
    SettingsListWidget = new QListWidget;
    SettingStackWidget = new QStackedWidget;
    MainLayout->addWidget(SettingsListWidget);
    MainLayout->addLayout(TheLastLayout);
    MainLayout->setStretchFactor(SettingsListWidget,1);
    MainLayout->setStretchFactor(TheLastLayout,6);
    TheLastLayout->addWidget(SettingStackWidget);
    TheLastLayout->addLayout(AllBtnLayout);
    TheLastLayout->setStretchFactor(SettingStackWidget,4);
    TheLastLayout->setStretchFactor(AllBtnLayout,1);
    CancelBtn = new QPushButton(tr("取消修改"));
    ReStartBtn = new QPushButton(tr("重置修改"));
    ApplyBtn = new QPushButton(tr("应用修改"));
    QLabel* NULLLabel = new QLabel;
    AllBtnLayout->addWidget(NULLLabel);
    AllBtnLayout->addWidget(CancelBtn);
    AllBtnLayout->addWidget(ReStartBtn);
    AllBtnLayout->addWidget(ApplyBtn);
    AllBtnLayout->setStretchFactor(NULLLabel,3);
    AllBtnLayout->setStretchFactor(CancelBtn,1);
    AllBtnLayout->setStretchFactor(ReStartBtn,1);
    AllBtnLayout->setStretchFactor(ApplyBtn,1);
    fontWindow = new FontAdmin;
    colorWindow = new ColorAdmin;
    FontListWidgetItem = new QListWidgetItem(tr("设置字体样式和大小"));
    ColorListWidgetItem = new QListWidgetItem(tr("设置IDE背景颜色"));
    SettingsListWidget->addItem(FontListWidgetItem);
    SettingsListWidget->addItem(ColorListWidgetItem);
    SettingStackWidget->addWidget(fontWindow);
    SettingStackWidget->addWidget(colorWindow);
    connect(SettingsListWidget,SIGNAL(currentRowChanged(int)),SettingStackWidget,SLOT(setCurrentIndex(int)));
}

void SettingsAdmin::ApplyBtnClicked()
{
    if(colorWindow->ReturnAdmin() == HasChanged)
    {

    }

}
