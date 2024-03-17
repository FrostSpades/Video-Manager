#include "videomanagermodel.h"
#include <QDir>
#include <QSettings>

VideoManagerModel::VideoManagerModel() {

}

void VideoManagerModel::createProfile(QString name, QString folderPath) {
    createSettings(name, folderPath);
    createDatabase(folderPath);
    createVideoFolder(folderPath);

    emit finishProfileCreation();
}

void VideoManagerModel::createSettings(QString name, QString folderPath) {
    QSettings settings("FrostSpades", "Video Manager");

    settings.setValue("name", name);
    settings.setValue("path", folderPath);
    settings.setValue("openLastPath", true);
}

void VideoManagerModel::createDatabase(QString folderPath) {
    folderPath.append("/Data");
    QDir directory(folderPath);

    // Check if the folder already exists
    if (!directory.exists()) {
        // Create the folder
        if (!directory.mkpath(folderPath)) {
            qDebug() << "Failed to create folder.";
        }
    }
}

void VideoManagerModel::createVideoFolder(QString folderPath) {
    folderPath.append("/Videos");
    QDir directory(folderPath);

    // Check if the folder already exists
    if (!directory.exists()) {
        // Create the folder
        if (!directory.mkpath(folderPath)) {
            qDebug() << "Failed to create folder.";
        }
    }
}
