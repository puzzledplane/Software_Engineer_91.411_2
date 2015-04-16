/* 
 * File:   Device.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Device class to facilitate easy conversion to
 *                   data-interchange formats.
 *
 * Created on April 3, 2015, 6:46 PM
 */

#ifndef DEVICE_H
#define	DEVICE_H

#include <QWidget>
#include <QDate>
#include <QString>

class Device : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString getTypeStr READ getTypeStr WRITE setTypeStr)
    Q_PROPERTY(QString getIdStr READ getIdStr WRITE setIdStr)
    Q_PROPERTY(QString getIpAddressStr READ getIpAddressStr WRITE setIpAddressStr)
            
private:
    QString typeStr;
    QString idStr;
    QString ipAddressStr;
    
public:
    Device(QObject* parent = 0);
    QString getTypeStr() const;
    void setTypeStr(const QString& typeStr);
    QString getIdStr() const;
    void setIdStr(const QString& idStr);
    QString getIpAddressStr();
    void setIpAddressStr(const QString& ipAddressStr);
    ~Device();
};


#endif	/* DEVICE_H */

