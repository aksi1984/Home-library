#include "book.hpp"

Book::Book() { }

void Book::setGeneral(const General &reqGeneral)
{
    general_ = reqGeneral;
}

void Book::setBookRating(const BookRating &rating)
{
    bookRating_ = rating;
}

void Book::setStoragePlace(const StoragePlace &place)
{
    storagePlace_ = place;
}

void Book::setBookPurchase(const BookPurchase &purchase)
{
    bookPurchase_ = purchase;
}

General Book::general() const noexcept
{
    return general_;
}

BookRating Book::bookRating() const noexcept
{
    return bookRating_;
}

StoragePlace Book::storagePlace() const noexcept
{
    return storagePlace_;
}

BookPurchase Book::bookPurchase() const noexcept
{
    return bookPurchase_;
}
