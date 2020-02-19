#include "bookcollection.hpp"

QVector<Book> BookCollection::books_;

Book BookCollection::getBook(int index) noexcept
{
    return books_[index];
}

void BookCollection::addBook(const Book &book)
{
    books_.push_back(book);
}

void BookCollection::removeBook(int index)
{
    books_.remove(index);
}
