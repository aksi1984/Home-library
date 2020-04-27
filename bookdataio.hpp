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
    saveBookData(book.storageLocation().data(), out);
    saveBookData(book.purchase().data(), out);
    saveBookData(book.series().data(), out);
    saveBookData(book.translation().data(), out);
    saveBookData(book.loaned().data(), out);
    saveBookData(book.lent().data(), out);
    saveBookData(book.sale().data(), out);
    saveBookData(book.status().data(), out);
    saveBookData(book.source().data(), out);
    saveBookData(book.description().data(), out);

    if(auto imageFileName = book.image().fileName(); imageFileName != std::nullopt)
    {
        out << imageFileName.value();
    }

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

    auto storageLocation = loadBookData(in, book.storageLocation().size());
    book.storageLocation().data() = storageLocation;

    auto purchase = loadBookData(in, book.purchase().size());
    book.purchase().data() = purchase;

    auto series = loadBookData(in, book.series().size());
    book.series().data() = series;

    auto translation = loadBookData(in, book.translation().size());
    book.translation().data() = translation;

    auto loaned = loadBookData(in, book.loaned().size());
    book.loaned().data() = loaned;

    auto lent = loadBookData(in, book.lent().size());
    book.lent().data() = lent;

    auto sale = loadBookData(in, book.sale().size());
    book.sale().data() = sale;

    auto status = loadBookData(in, book.status().size());
    book.status().data() = status;

    auto source = loadBookData(in, book.source().size());
    book.source().data() = source;

    auto description = loadBookData(in, book.description().size());
    book.description().data() = description;

    QString imageFileName;
    in >> imageFileName;

    book.setImage(BookImage{imageFileName});

    return in;
}

#endif // BOOKDATAIO_HPP
