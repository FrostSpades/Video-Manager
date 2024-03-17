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
private slots:
    void on_cancelButton_clicked();
    void on_submitButton_clicked();
};

#endif // PROFILECREATOR_H
