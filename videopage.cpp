#include "videopage.h"
#include "ui_videopage.h"

VideoPage::VideoPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoPage)
{
    ui->setupUi(this);
}

VideoPage::~VideoPage()
{
    delete ui;
}


