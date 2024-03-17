#ifndef VIDEOPAGE_H
#define VIDEOPAGE_H

#include <QWidget>

namespace Ui {
class VideoPage;
}

class VideoPage : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPage(QWidget *parent = nullptr);
    ~VideoPage();

signals:
    void clickVideoPageButton();

private:
    Ui::VideoPage *ui;
};

#endif // VIDEOPAGE_H
