#ifndef BOOKSOURCEOFORIGIN_HPP
#define BOOKSOURCEOFORIGIN_HPP

#include <QString>

class BookSourceOfOrigin
{
public:
    BookSourceOfOrigin();
    BookSourceOfOrigin(const QString& reqCategory, const QString& reqDescription);

    void setCategory(const QString& text);
    void setDescription(const QString& text);

    QString category() const noexcept;
    QString description() const noexcept;

private:
    QString category_;
    QString description_;
};

#endif // BOOKSOURCEOFORIGIN_HPP
