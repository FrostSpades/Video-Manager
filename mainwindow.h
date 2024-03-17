#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "homepage.h"
#include "videopage.h"
#include "startuppage.h"
#include "profileCreator.h"
#include "videomanagermodel.h"

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
    VideoManagerModel *videoManagerModel;
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

    /**
     * @brief handleNewProfile
     * Handles the submission of a new profile.
     * @param name
     * @param folderPath
     */
    void onProfileCreated(QString name, QString folderPath);

signals:
    /**
     * @brief startProfileCreator
     * Signal that profile creator
     * has started.
     */
    void startProfileCreator();
};
#endif // MAINWINDOW_H
