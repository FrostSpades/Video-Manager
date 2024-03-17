#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "homepage.h"
#include "videopage.h"
#include "startuppage.h"
#include "profileCreator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    HomePage *homePage;
    VideoPage *videoPage;
    StartupPage *startupPage;
    ProfileCreator *profileCreator;
    QStackedWidget *stackedWidget;

    void initializeSignalSlots();

public slots:
    void changeToRoomPage();
    void changeToHomePage();

    /**
     * @brief showProfileCreator
     * Shows the profile creation box.
     */
    void showProfileCreator();

    /**
     * @brief hideProfileCreator
     * Hides the profile creation box.
     */
    void hideProfileCreator();
};
#endif // MAINWINDOW_H
