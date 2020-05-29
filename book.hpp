#ifndef BOOK_HPP
#define BOOK_HPP

#include "bookimage.hpp"
#include "bookdetails.hpp"

class Book
{
public:
    Book();

    void setBasic(const BookDetails& data);
    BookDetails& basic();
    BookDetails basic() const noexcept;

    void setRatings(const BookDetails& data);
    BookDetails& ratings();
    BookDetails ratings() const noexcept;

    void setStorageLocation(const BookDetails& data);
    BookDetails& storageLocation();
    BookDetails storageLocation() const noexcept;

    void setPurchase(const BookDetails& data);
    BookDetails& purchase();
    BookDetails purchase() const noexcept;

    void setSeries(const BookDetails& data);
    BookDetails& series();
    BookDetails series() const noexcept;

    void setTranslation(const BookDetails& data);
    BookDetails& translation();
    BookDetails translation() const noexcept;

    void setLoaned(const BookDetails& data);
    BookDetails& loaned();
    BookDetails loaned() const noexcept;

    void setLent(const BookDetails& data);
    BookDetails& lent();
    BookDetails lent() const noexcept;

    void setSale(const BookDetails& data);
    BookDetails& sale();
    BookDetails sale() const noexcept;

    void setStatus(const BookDetails& data);
    BookDetails& status();
    BookDetails status() const noexcept;

    void setSource(const BookDetails& data);
    BookDetails& source();
    BookDetails source() const noexcept;

    void setDescription(const BookDetails& data);
    BookDetails& description();
    BookDetails description() const noexcept;

    void setImage(const BookImage& image);
    BookImage image() const noexcept;
    BookImage& image();

private:

    BookDetails basic_;
    BookDetails ratings_;
    BookDetails storageLocation_;
    BookDetails purchase_;
    BookDetails series_;
    BookDetails translation_;
    BookDetails loaned_;
    BookDetails lent_;
    BookDetails sale_;
    BookDetails status_;
    BookDetails sourceOfOrigin_;
    BookDetails description_;
    BookImage bookImage_;

    //QStringList numbers_;
};

#endif // BOOK_HPP
