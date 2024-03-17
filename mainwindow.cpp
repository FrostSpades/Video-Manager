#include "mainwindow.h"
#include "ui_homepage.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , homePage(new HomePage)
    , videoPage(new VideoPage)
    , startupPage(new StartupPage)
    , profileCreator(new ProfileCreator)
    , videoManagerModel(new VideoManagerModel)
    , stackedWidget(new QStackedWidget(this))
{
    ui->setupUi(this);

    stackedWidget->addWidget(startupPage);
    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(videoPage);
    setCentralWidget(stackedWidget);

    initializeSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete homePage;
    delete videoPage;
    delete startupPage;
    delete profileCreator;
    delete videoManagerModel;
    delete stackedWidget;
}

void MainWindow::showProfileCreator() {
    profileCreator->exec();

    emit startProfileCreator();
}

void MainWindow::hideProfileCreator() {
    profileCreator->close();
}

void MainWindow::showError(QString errorMessage) {
    QMessageBox::critical(nullptr, "Error", errorMessage);
}

void MainWindow::onProfileCreated(QString name, QString folderPath) {
    hideProfileCreator();

    emit createProfileRequest(name, folderPath);
}

void MainWindow::navigateToHomePage() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::initializeSignalSlots() {
    connect(startupPage, &StartupPage::clickCreateProfile, this, &MainWindow::showProfileCreator);

    connect(profileCreator, &ProfileCreator::clickCancel, this, &MainWindow::hideProfileCreator);
    connect(profileCreator, &ProfileCreator::clickSubmit, this, &MainWindow::onProfileCreated);
    connect(profileCreator, &ProfileCreator::error, this, &MainWindow::showError);

    connect(this, &MainWindow::startProfileCreator, profileCreator, &ProfileCreator::onStart);
    connect(this, &MainWindow::createProfileRequest, videoManagerModel, &VideoManagerModel::createProfile);

    connect(videoManagerModel, &VideoManagerModel::finishProfileCreation, this, &MainWindow::navigateToHomePage);
}
