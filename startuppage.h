#ifndef STARTUPPAGE_H
#define STARTUPPAGE_H

#include <QWidget>

namespace Ui {
class StartupPage;
}

class StartupPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartupPage(QWidget *parent = nullptr);
    ~StartupPage();

private:
    Ui::StartupPage *ui;

signals:
    /**
     * @brief clickCreateProfile
     * Sends signal that create profile button
     * was clicked.
     */
    void clickCreateProfile();
private slots:
    void on_createProfileButton_clicked();
};

#endif // STARTUPPAGE_H
