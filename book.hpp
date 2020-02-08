#ifndef BOOK_HPP
#define BOOK_HPP

#include "general.hpp"
#include "bookrating.hpp"
#include "storageplace.hpp"
#include "bookpurchase.hpp"


class Book
{
public:
    Book();

    void setGeneral(const General& reqGeneral);
    void setBookRating(const BookRating& rating);
    void setStoragePlace(const StoragePlace& place);
    void setBookPurchase(const BookPurchase& purchase);

    General general() const noexcept;
    BookRating bookRating() const noexcept;
    StoragePlace storagePlace() const noexcept;
    BookPurchase bookPurchase() const noexcept;

private:
    General general_;
    BookRating bookRating_;
    StoragePlace storagePlace_;
    BookPurchase bookPurchase_;
};

#endif // BOOK_HPP
