#include "User.h"

User::User(QObject* parent) : QObject(parent)
{
    ;
}


QString User::getNameStr() const
{
    return nameStr;
}


void User::setNameStr(const QString& nameStr)
{
    this->nameStr = nameStr;
}


QString User::getUsernameStr() const
{
    return usernameStr;
}


void User::setUsernameStr(const QString& usernameStr)
{
    this->usernameStr = usernameStr;
}


QString User::getPasswordStr() const
{
    return passwordStr;
}


void User::setPasswordStr(const QString& passwordStr)
{
    this->passwordStr = passwordStr;
}


QString User::getEmailAddressStr() const
{
    return emailAddressStr;
}


void User::setEmailAddressStr(const QString& emailAddressStr)
{
    this->emailAddressStr = emailAddressStr;
}


QVector<QString> User::getExercisesVec() const
{
    return exercisesVec;
}


void User::setExercisesVec(const QVector<QString> exercisesVec)
{
    this->exercisesVec = exercisesVec;
}


QString User::getNoteStr() const
{
    return noteStr;
}


void User::setNoteStr(const QString& noteStr)
{
    this->noteStr = noteStr;
}

User::~User()
{
    ;
}