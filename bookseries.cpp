#include "bookseries.hpp"

BookSeries::BookSeries() { }

BookSeries::BookSeries(const QString& reqName, int reqPart, int reqNumber) :
    name_{reqName},
    part_{reqPart},
    number_{reqNumber} { }

void BookSeries::setName(const QString &text)
{
    name_ = text;
}

void BookSeries::setPart(int value)
{
    part_ = value;
}

void BookSeries::setNumber(int value)
{
    number_ = value;
}

QString BookSeries::name() const noexcept
{
    return name_;
}

int BookSeries::part() const noexcept
{
    return part_;
}

int BookSeries::number() const noexcept
{
    return number_;
}
