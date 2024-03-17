#include "mainwindow.h"
#include "ui_homepage.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , homePage(new HomePage)
    , videoPage(new VideoPage)
    , startupPage(new StartupPage)
    , profileCreator(new ProfileCreator)
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
}

void MainWindow::changeToHomePage() {
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::changeToRoomPage() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::showProfileCreator() {
    profileCreator->exec();
}

void MainWindow::hideProfileCreator() {
    profileCreator->close();
}

void MainWindow::initializeSignalSlots() {
    connect(startupPage, &StartupPage::clickCreateProfile, this, &MainWindow::showProfileCreator);
    connect(profileCreator, &ProfileCreator::clickCancel, this, &MainWindow::hideProfileCreator);
}
