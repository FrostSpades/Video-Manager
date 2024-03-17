#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <QString>

class Profile
{
public:
    Profile();
    Profile(std::string name, QString path);
private:
    std::string name;
    QString path;
};

#endif // PROFILE_H
