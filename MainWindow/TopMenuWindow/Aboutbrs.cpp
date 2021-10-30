#include "Aboutbrs.h"

AboutBRS::AboutBRS(QDialog* parent) : QDialog(parent)
{
    resize(300,100);
    AboutBRSLayout = new QGridLayout(this);
    BRSVersionLabel = new QLabel;
    BRSVersionLabel->setText("This is a C++ IDE");
    AboutBRSLayout->addWidget(BRSVersionLabel,0,0,1,3);
    OKBtn = new QPushButton;
    OKBtn->setText(tr("完成"));
    AboutBRSLayout->addWidget(OKBtn,1,3);
}

void AboutBRS::OKBtnClicked()
{
    this->close();
}
