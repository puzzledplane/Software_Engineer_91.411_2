#include "JsonParser.h"


template<class T>
JsonParser<T>::JsonParser()
{
    ;
}


template<class T>
void JsonParser<T>::toJson(T objectForJsonation)
{
    variant = QObjectHelper::qobject2qvariant(&objectForJsonation);
    serializer->setIndentMode(QJson::IndentFull);
    //qDebug() << serializer->serialize(*variant);
}


template<class T>
T JsonParser<T>::fromJson()
{
    ;
}


template<class T>
JsonParser<T>::~JsonParser()
{
    ;
}