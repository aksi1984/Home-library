#include "bookrentalstatus.hpp"

BookRentalStatus::BookRentalStatus() { }

BookRentalStatus::BookRentalStatus(const QDate& reqDate, const QString& reqPersonalName) :
    date_{reqDate},
    personName_{reqPersonalName} { }

void BookRentalStatus::setDate(const QDate &d)
{
    date_ = d;
}

void BookRentalStatus::setPersonName(const QString &text)
{
    personName_ = text;
}

QDate BookRentalStatus::date() const noexcept
{
    return date_;
}

QString BookRentalStatus::personName() const noexcept
{
    return personName_;
}
