#include "LocalDBMaster.h"


LocalDBMaster::LocalDBMaster()
{
    ;
}


void LocalDBMaster::connectDB()
{
    connectionFailed = sqlite3_open("test.db", &db);
    
    if(connectionFailed)
    {
        cerr << "Connection failed" << endl;
    }
    else
    {
        cout << "Connection established" << endl;
    }
    
    sqlite3_close(db);
}


void LocalDBMaster::writeUser(QVariantMap* variant)
{
    serializer->setIndentMode(QJson::IndentFull);
    string tmpStr = (string) serializer->serialize(*variant);
    const char* tmp = tmpStr.c_str();
    char* zErrMsg = 0;
    //cout << tmp << endl;
    
    connectionFailed = sqlite3_exec(db, tmp, 0, 0, &zErrMsg);
    
}


QVariantMap* LocalDBMaster::readUser(int index)
{
    ;
}


void LocalDBMaster::writeDevice(QVariantMap* variant)
{
    ;
}


QVariantMap* LocalDBMaster::readDevice(int index)
{
    ;
}


void LocalDBMaster::disconnectDB()
{
    sqlite3_close(db);
}


LocalDBMaster::~LocalDBMaster()
{
    ;
}