#ifndef BOOKRENTALSTATUS_HPP
#define BOOKRENTALSTATUS_HPP

#include <QDate>

class BookRentalStatus
{
public:
    BookRentalStatus();
    BookRentalStatus(const QDate& reqDate, const QString& reqPersonalName);

    void setDate(const QDate& d);
    void setPersonName(const QString& text);

    QDate date() const noexcept;
    QString personName() const noexcept;

private:
    QDate date_;
    QString personName_;
};

#endif // BOOKRENTALSTATUS_HPP
