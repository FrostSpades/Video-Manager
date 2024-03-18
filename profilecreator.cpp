#include "profilecreator.h"
#include "ui_profilecreator.h"
#include <QFileDialog>
#include <QDir>

ProfileCreator::ProfileCreator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfileCreator)
{
    ui->setupUi(this);

    setMinimumSize(size());
    setMaximumSize(size());
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
    // Check if inputs are empty
    if (ui->inputName->toPlainText() == QString("") || ui->inputFolderPath->toPlainText() == QString("")) {
        emit error("Inputs cannot be empty");
        return;
    }

    QDir directory(ui->inputFolderPath->toPlainText());

    if (!directory.exists()){
        emit error("Directory does not exist");
        return;
    }

    if (!directory.isEmpty()) {
        emit error("Directory location needs to be empty");
        return;
    }

    emit clickSubmit(ui->inputName->toPlainText(), ui->inputFolderPath->toPlainText());
}

void ProfileCreator::onStart() {
    ui->inputFolderPath->setText(QString(""));
    ui->inputName->setText(QString(""));
}


void ProfileCreator::on_sourceButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(nullptr,
                                                          "Directory Selection",
                                                          QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->inputFolderPath->setText(directory);
}

