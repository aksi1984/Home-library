#include "book.hpp"
#include <QApplication>
Book::Book() :
    basic_(16, "Basic"),
    ratings_(3, "Ratings"),
    storageLocation_(4, "Storage location"),
    purchase_(4, "Purchase"),
    series_(3, "Series"),
    translation_(2, "Translation"),
    loaned_(2, "Loaned"),
    lent_(2, "Lent"),
    sale_{3, "Sale"},
    status_{3, "Status"},
    sourceOfOrigin_{3, "Source of origin"},
    description_{2, "Description"} { }

void Book::setBasic(const BookDetails &data)
{
    basic_ = data;
}

BookDetails Book::basic() const noexcept
{
    return basic_;
}

BookDetails& Book::basic()
{
    return basic_;
}

void Book::setRatings(const BookDetails &data)
{
    ratings_ = data;
}

BookDetails Book::ratings() const noexcept
{
    return ratings_;
}

BookDetails& Book::ratings()
{
    return ratings_;
}

void Book::setStorageLocation(const BookDetails &data)
{
    storageLocation_ = data;
}

BookDetails Book::storageLocation() const noexcept
{
    return storageLocation_;
}

BookDetails& Book::storageLocation()
{
    return storageLocation_;
}

void Book::setPurchase(const BookDetails &data)
{
    purchase_ = data;
}

BookDetails Book::purchase() const noexcept
{
    return purchase_;
}

BookDetails& Book::purchase()
{
    return purchase_;
}

void Book::setSeries(const BookDetails &data)
{
    series_ = data;
}

BookDetails Book::series() const noexcept
{
    return series_;
}

BookDetails& Book::series()
{
    return series_;
}

void Book::setTranslation(const BookDetails &data)
{
    translation_ = data;
}

BookDetails Book::translation() const noexcept
{
    return translation_;
}

BookDetails& Book::translation()
{
    return translation_;
}

void Book::setLoaned(const BookDetails &data)
{
    loaned_ = data;
}

BookDetails Book::loaned() const noexcept
{
    return loaned_;
}

BookDetails& Book::loaned()
{
    return loaned_;
}

void Book::setLent(const BookDetails &data)
{
    lent_ = data;
}

BookDetails Book::lent() const noexcept
{
    return lent_;
}

BookDetails& Book::lent()
{
    return lent_;
}

void Book::setSale(const BookDetails &data)
{
    sale_ = data;
}

BookDetails Book::sale() const noexcept
{
    return sale_;
}

BookDetails& Book::sale()
{
    return sale_;
}

void Book::setStatus(const BookDetails &data)
{
    status_ = data;
}

BookDetails Book::status() const noexcept
{
    return status_;
}

BookDetails& Book::status()
{
    return status_;
}

void Book::setSource(const BookDetails &data)
{
    sourceOfOrigin_ = data;
}

BookDetails Book::source() const noexcept
{
    return sourceOfOrigin_;
}

BookDetails& Book::source()
{
    return sourceOfOrigin_;
}

void Book::setDescription(const BookDetails &data)
{
    description_ = data;
}

BookDetails Book::description() const noexcept
{
    return description_;
}

BookDetails& Book::description()
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

BookImage &Book::image()
{
    return bookImage_;
}
