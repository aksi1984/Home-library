#include "bookpurchase.hpp"

BookPurchase::BookPurchase() { }

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

