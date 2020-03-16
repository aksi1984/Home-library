#include "book.hpp"

Book::Book() { }

void Book::setBasic(const BookBasic &bookBasic)
{
    basic_ = bookBasic;
}

BookBasic Book::basic() const noexcept
{
    return basic_;
}

void Book::setBasicNumbers(const BookBasicNumbers &bookBasic)
{
    basicNumbers_ = bookBasic;
}

BookBasicNumbers Book::basicNumbers() const noexcept
{
    return basicNumbers_;
}

void Book::setRating(const BookRating &bookRating)
{
    rating_ = bookRating;
}

BookRating Book::rating() const noexcept
{
    return rating_;
}

void Book::setStorageLocation(const StorageLocation &location)
{
    storageLocation_ = location;
}

StorageLocation Book::storageLocation() const noexcept
{
    return storageLocation_;
}

void Book::setPurchase(const BookPurchase &bookPurchase)
{
    purchase_ = bookPurchase;
}

BookPurchase Book::purchase() const noexcept
{
    return purchase_;
}

void Book::setSeries(const BookSeries &bookSeries)
{
    series_ = bookSeries;
}

BookSeries Book::series() const noexcept
{
    return series_;
}

void Book::setTranslation(const BookTranslation &bookTranslation)
{
    translation_ = bookTranslation;
}

BookTranslation Book::translation() const noexcept
{
    return translation_;
}

void Book::setLoaned(const BookRentalStatus &rentalStatus)
{
    loaned_ = rentalStatus;
}

BookRentalStatus Book::loaned() const noexcept
{
    return loaned_;
}

void Book::setLent(const BookRentalStatus &rentalStatus)
{
    lent_ = rentalStatus;
}

BookRentalStatus Book::lent() const noexcept
{
    return lent_;
}

void Book::setSale(const BookSale &bookSale)
{
    sale_ = bookSale;
}

BookSale Book::sale() const noexcept
{
    return sale_;
}

void Book::setStatus(const BookStatus &bookStatus)
{
    status_ = bookStatus;
}

BookStatus Book::status() const noexcept
{
    return status_;
}

void Book::setSourceOfOrigin(const BookSourceOfOrigin &bookSourceOfOrigin)
{
    sourceOfOrigin_ = bookSourceOfOrigin;
}

BookSourceOfOrigin Book::sourceOfOrigin() const noexcept
{
    return sourceOfOrigin_;
}

void Book::setAdditives(const BookAdditives &bookAdditives)
{
    additives_ = bookAdditives;
}

BookAdditives Book::additives() const noexcept
{
    return additives_;
}

void Book::setDescription(const BookDescriprion &bookDesription)
{
    description_ = bookDesription;
}

BookDescriprion Book::description() const noexcept
{
    return description_;
}

void Book::setImage(const BookImage &image)
{
    bookImage_ = image;
}

BookImage Book::image() const noexcept
{
    return bookImage_;
}
