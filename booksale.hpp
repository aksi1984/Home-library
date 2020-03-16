#ifndef BOOKSALE_HPP
#define BOOKSALE_HPP

#include <QDate>

class BookSale
{
public:
    BookSale();
    BookSale(const QDate& reqDate, const QString& reqPersonName, double reqPrice);

    void setPersonName(const QString& text);
    void setDate(const QDate& d);
    void setPrice(double value);

    QString personName() const noexcept;
    QDate date() const noexcept;
    double price() const noexcept;

private:
    QDate date_;
    QString personName_;
    double price_;
};

#endif // BOOKSALE_HPP
