#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <QVariantList>

inline QStringList toStringList(const QVariantList& varList)
{
    QStringList data;

    for(auto x : varList) data.push_back(x.toString());

    return data;
}


#endif // CONVERSION_HPP
