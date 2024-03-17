#include "profilecreator.h"
#include "ui_profilecreator.h"

ProfileCreator::ProfileCreator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfileCreator)
{
    ui->setupUi(this);
}

ProfileCreator::~ProfileCreator()
{
    delete ui;
}

void ProfileCreator::on_cancelButton_clicked()
{
    emit clickCancel();
}


void ProfileCreator::on_submitButton_clicked()
{

}

