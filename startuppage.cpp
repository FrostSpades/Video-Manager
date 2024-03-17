#include "startuppage.h"
#include "ui_startuppage.h"

StartupPage::StartupPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartupPage)
{
    ui->setupUi(this);
}

StartupPage::~StartupPage()
{
    delete ui;
}

void StartupPage::on_createProfileButton_clicked()
{
    emit clickCreateProfile();
}

