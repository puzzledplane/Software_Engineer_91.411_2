/* 
 * File:   LocalDBMaster.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class stores certain data attributes in a local
 *                   database on the host system, implemented with SQLite.
 * 
 * References: http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 *
 * Created on April 7, 2015, 3:47 PM
 */

#ifndef LOCAL_DB_MASTER_H
#define	LOCAL_DB_MASTER_H

#include <stdio.h>
#include <sqlite3.h>

#include <qjson/parser.h>
#include <qjson/parserrunnable.h>
#include <qjson/qjson_export.h>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>
#include <qjson/serializerrunnable.h>

#include <string>
#include <iostream>

using namespace QJson;
using namespace std;


class LocalDBMaster
{
private:
    sqlite3* db;
    bool connectionFailed;
    
    Serializer* serializer;
    
public:
    LocalDBMaster();
    void connectDB();
    void writeUser(QVariantMap* variant);//write user data to database.
    QVariantMap* readUser(int index);
    void writeDevice(QVariantMap* variant);
    QVariantMap* readDevice(int index);
    void disconnectDB();
    ~LocalDBMaster();
    
};

#endif	/* LOCAL_DB_MASTER_H */

