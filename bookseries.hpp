#ifndef BOOKSERIES_HPP
#define BOOKSERIES_HPP

#include <QString>

class BookSeries
{
public:
    BookSeries();
    BookSeries(const QString& reqName, int reqPart, int reqNumber);

    void setName(const QString& text);
    void setPart(int value);
    void setNumber(int value);

    QString name() const noexcept;
    int part() const noexcept;
    int number() const noexcept;

private:
    QString name_;
    int part_;
    int number_;
};

#endif // BOOKSERIES_HPP
