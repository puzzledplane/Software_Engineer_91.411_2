/* 
 * File: JsonParser.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This file converts data to JSON for storage, and
 *                   parses it back for retrieval.
 * 
 * Reference: http://qjson.sourceforge.net/usage/
 *            http://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
 * 
 * Created on April 7, 2015, 10:37 PM
 */

#ifndef JSON_PARSER_H
#define	JSON_PARSER_H

#include <QString>
#include <QVector>
#include <QDebug>

#include <qjson/parser.h>
#include <qjson/parserrunnable.h>
#include <qjson/qjson_export.h>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>
#include <qjson/serializerrunnable.h>

#include <iostream>

using namespace std;
using namespace QJson;

template<class T>
class JsonParser
{
private:
    Parser* parser;
    bool ok;
    
    QVariantMap* variant;
    Serializer* serializer;
    
    
public:
    JsonParser();
    void toJson(T objectForJsonization);
    T fromJson();
    ~JsonParser();
};

#endif	/* JSON_PARSER_H */

