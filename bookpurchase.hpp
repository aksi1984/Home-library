#ifndef BOOKPURCHASE_HPP
#define BOOKPURCHASE_HPP

#include <QDate>

class BookPurchase
{
public:
    BookPurchase();

    void setPlace(const QString& text);
    void setDate(const QDate& reqDate);
    void setPrice(double value);
    void setValuation(double value);

    QString place() const noexcept;
    QDate date() const noexcept;
    double price() const noexcept;
    double valuation() const noexcept;

private:
    QString place_;
    QDate date_;

    double price_;
    double valuation_;
};

#endif // BOOKPURCHASE_HPP
