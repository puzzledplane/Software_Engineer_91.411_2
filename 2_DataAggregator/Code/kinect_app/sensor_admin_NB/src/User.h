/* 
 * File:   Person.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: User class to facilitate easy conversion to
 *                   data-interchange formats.
 *
 * Created on April 3, 2015, 1:07 PM
 */

#ifndef PERSON_H
#define	PERSON_H

#include <QWidget>
#include <QDate>
#include <QString>

class User : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString getNameStr READ getNameStr WRITE setNameStr)
    Q_PROPERTY(QString getUsernameStr READ getUsernameStr WRITE setUsernameStr)
    Q_PROPERTY(QString getPasswordStr READ getPasswordStr WRITE setPasswordStr)
    Q_PROPERTY(QString getEmailAddressStr READ getEmailAddressStr WRITE setEmailAddressStr)
    Q_PROPERTY(QVector<QString> getExercisesVec READ getExercisesVec WRITE setExercisesVec)
    Q_PROPERTY(QString getNoteStr READ getNoteStr WRITE setNoteStr)

private:
    QString nameStr;
    QString usernameStr;
    QString passwordStr;
    QString emailAddressStr;
    QVector<QString> exercisesVec;
    QString noteStr;

public:
    User(QObject* parent = 0);
    QString getNameStr() const;
    void setNameStr(const QString& nameStr);
    QString getUsernameStr() const;
    void setUsernameStr(const QString& usernameStr);
    QString getPasswordStr() const;
    void setPasswordStr(const QString& passwordStr);
    QString getEmailAddressStr() const;
    void setEmailAddressStr(const QString& emailAddressStr);
    //enums?
    //QString getAccountTypeStr() const;
    //void setAccountTypeStr(const QString& accountTypeStr);
    QVector<QString> getExercisesVec() const;
    void setExercisesVec(const QVector<QString> exercisesVec);
    QString getNoteStr() const;
    void setNoteStr(const QString& noteStr);
    ~User();
};

#endif	/* PERSON_H */
