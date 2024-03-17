#ifndef VIDEOMANAGERMODEL_H
#define VIDEOMANAGERMODEL_H

#include <QObject>

class VideoManagerModel : public QObject
{
    Q_OBJECT
public:
    VideoManagerModel();
public slots:
    /**
     * @brief createProfile
     * Creates a new profile
     * @param name
     * @param folderPath
     */
    void createProfile(QString name, QString folderPath);

private:
    /**
     * @brief createSettings
     * Creates the persistent settings.
     * @param name
     * @param folderPath
     */
    void createSettings(QString name, QString folderPath);

    /**
     * @brief createDatabase
     * Creates the database
     * @param folderPath
     */
    void createDatabase(QString folderPath);

    /**
     * @brief createVideoFolder
     * Creates location for video storage
     * @param folderPath
     */
    void createVideoFolder(QString folderPath);

signals:
    /**
     * @brief finishProfileCreation
     * Sends signal that profile creation
     * is finished.
     */
    void finishProfileCreation();
};

#endif // VIDEOMANAGERMODEL_H
