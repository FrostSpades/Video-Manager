#ifndef PROFILECREATOR_H
#define PROFILECREATOR_H

#include <QDialog>

namespace Ui {
class ProfileCreator;
}

class ProfileCreator : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileCreator(QWidget *parent = nullptr);
    ~ProfileCreator();

private:
    Ui::ProfileCreator *ui;

signals:
    /**
     * @brief clickCancel
     * Sends signal that the cancel
     * button was clicked.
     */
    void clickCancel();

    /**
     * @brief clickSubmit
     * Sends signal that the submit
     * button was clicked.
     * @param name name of the profile
     * @param folderPath folder path for the profile
     */
    void clickSubmit(QString name, QString folderPath);

public slots:
    /**
     * @brief onStart
     * Cleans window on start.
     */
    void onStart();
private slots:
    void on_cancelButton_clicked();
    void on_submitButton_clicked();
    void on_sourceButton_clicked();
};

#endif // PROFILECREATOR_H
