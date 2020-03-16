#include "bookscollection.hpp"

QVector<Book> BooksCollection::books_;

Book BooksCollection::getBook(int index) noexcept
{
    return books_[index];
}

void BooksCollection::addBook(const Book &book)
{
    books_.push_back(book);
}

void BooksCollection::updateBook(const Book &book, int index)
{
    books_[index] = book;
}

void BooksCollection::removeBook(int index)
{
    books_.remove(index);
}
