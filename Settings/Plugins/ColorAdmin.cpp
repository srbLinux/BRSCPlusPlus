#include "ColorAdmin.h"

ColorAdmin::ColorAdmin(QWidget *parent) : QWidget(parent)
{
    ColorMainLayout = new QGridLayout(this);
    ColorLabel = new QLabel(tr("选择背景颜色"),this);
    SelectColor = new QComboBox(this);
    QStringList list;
    list<<"默认背景"<<"灰色背景";
    SelectColor->addItems(list);
    ExampleTextEdit = new QTextEdit(this);
    ColorMainLayout->addWidget(ColorLabel,0,0);
    ColorMainLayout->addWidget(SelectColor,0,1,1,2);
    ColorMainLayout->addWidget(ExampleTextEdit,1,1,2,2);
    connect(SelectColor,&QComboBox::currentTextChanged,this,&ColorAdmin::BoxSelectChanged);
}

/*
 *  @pragm: QString
 *  ColorInfo变量是一套随背景色改变而改变的字体颜色
 *  信息发送路径：ColorAdmin --> SettingsAdmin(决定是否继续发送到MainWindow，决定权在ApplyBtn手上)
 *  --> MainWindow(MainWindow设立一个槽函数专门接受由SettingAdmin传输来的数据)
 *  The function not finshed.
*/
void ColorAdmin::BoxSelectChanged(QString color)
{
    QHash<int,QString> ColorInfo;
    /*
     *  ColorInfo数据设置规则如下:
     *  0 ---> 注释                        green
     *  1 ---> 字符串 <something.h>
     *  2 ---> #include #define #...
     *  3 ---> class
     *  4 ---> int || long long || ...
     *
    */
    ALast = HasChanged;
    if(color == "灰色背景")
    {
        //88,87,86
        ExampleTextEdit->setStyleSheet("background-color:#292421;");
        ExampleTextEdit->setTextColor("color:green;");
        ColorInfo.insert(0,"48 128 20");
        ColorInfo.insert(1,"255 97 3");
        ColorInfo.insert(2,"160 32 240");
        ColorInfo.insert(3,"0 255 0");
        ColorInfo.insert(4,"127 255 0");
    }
    else if(color == "默认背景")
    {
        ExampleTextEdit->setStyleSheet("background-color:white;");
        ColorInfo.insert(0,"48 128 20");
        ColorInfo.insert(1,"255 97 3");
        ColorInfo.insert(2,"160 32 240");
        ColorInfo.insert(3,"0 255 0");
        ColorInfo.insert(4,"127 255 0");
    }
    emit BackgroundColorBroadcast(color);
    emit FontColorBroadcast(ColorInfo);
}

Color ColorAdmin::ReturnAdmin()
{
    if(ALast == HasChanged)
        return HasChanged;
    else
        return NotChange;
}
