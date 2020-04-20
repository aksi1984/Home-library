#ifndef BOOKDATAIO_HPP
#define BOOKDATAIO_HPP

#include <QSettings>

#include "bookscollection.hpp"

inline void saveBookData(QVariantList varList, QDataStream& out)
{
    for(auto x : varList) out << x;
}

inline QDataStream& operator<<(QDataStream& out, const Book& book)
{
    saveBookData(book.basic().data(), out);
    saveBookData(book.ratings().data(), out);

    return out;
}

////////////////////////////////////////////////////////////////////

inline QVariantList loadBookData(QDataStream& in, int range)
{
    QVariantList varList;

    for(int i = 0; i < range; ++i)
    {
        QVariant var;
        in >> var;
        varList.push_back(var);
    }

    return varList;
}

inline QDataStream& operator>>(QDataStream& in, Book& book)
{
    auto basic = loadBookData(in, book.basic().size());
    book.basic().data() = basic;

    auto ratings = loadBookData(in, book.ratings().size());
    book.ratings().data() = ratings;

    return in;
}

#endif // BOOKDATAIO_HPP
