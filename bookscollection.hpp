#ifndef BOOKCOLLECTION_HPP
#define BOOKCOLLECTION_HPP

#include <QVector>

#include "book.hpp"

class BooksCollection
{
public:
    BooksCollection() = default;
    BooksCollection(const BooksCollection& copy) = delete;

    BooksCollection& operator=(const BooksCollection& rhs) = delete;

    static Book getBook(int index) noexcept;
    static void addBook(const Book& book);
    static void updateBook(const Book& book, int index);
    static void removeBook(int index);

private:
    static QVector<Book> books_;
};

#endif // BOOKCOLLECTION_HPP
