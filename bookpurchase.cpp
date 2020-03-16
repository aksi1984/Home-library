#include "bookpurchase.hpp"

BookPurchase::BookPurchase() { }

BookPurchase::BookPurchase(const QString& reqPlace, const QDate& reqDate, double reqPrice, double reqVal) :
    place_{reqPlace},
    date_{reqDate},
    price_{reqPrice},
    valuation_{reqVal} { }

void BookPurchase::setPlace(const QString &text)
{
    place_ = text;
}

void BookPurchase::setDate(const QDate &reqDate)
{
    date_ = reqDate;
}

void BookPurchase::setPrice(double value)
{
    price_ = value;
}

void BookPurchase::setValuation(double value)
{
    valuation_ = value;
}

QString BookPurchase::place() const noexcept
{
    return place_;
}

QDate BookPurchase::date() const noexcept
{
    return date_;
}

double BookPurchase::price() const noexcept
{
    return price_;
}

double BookPurchase::valuation() const noexcept
{
    return valuation_;
}

