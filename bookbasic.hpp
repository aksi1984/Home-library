#ifndef BOOKBASIC_HPP
#define BOOKBASIC_HPP

#include <QStringList>

class BookBasic
{
public:
    BookBasic();
    BookBasic(const QStringList& reqData);

    QStringList data() const noexcept;

private:
    QStringList data_;

};

#endif // BOOKBASIC_HPP
