#include "booksale.hpp"

BookSale::BookSale() { }

BookSale::BookSale(const QDate& reqDate, const QString& reqPersonName, double reqPrice) :
    date_{reqDate},
    personName_{reqPersonName},
    price_{reqPrice} { }


void BookSale::setPersonName(const QString &text)
{
    personName_ = text;
}

void BookSale::setDate(const QDate &d)
{
    date_ = d;
}

void BookSale::setPrice(double value)
{
    price_ = value;
}

QString BookSale::personName() const noexcept
{
    return personName_;
}

QDate BookSale::date() const noexcept
{
    return date_;
}

double BookSale::price() const noexcept
{
    return price_;
}
