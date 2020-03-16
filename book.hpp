#ifndef BOOK_HPP
#define BOOK_HPP

#include "bookbasic.hpp"
#include "bookbasicnumbers.hpp"
#include "bookrating.hpp"
#include "storageplace.hpp"
#include "bookpurchase.hpp"
#include "bookseries.hpp"
#include "booktranslation.hpp"
#include "bookrentalstatus.hpp"
#include "bookstatus.hpp"
#include "booksourceoforigin.hpp"
#include "booksale.hpp"
#include "bookadditives.hpp"
#include "bookdescriprion.hpp"
#include "bookimage.hpp"

class Book
{
public:
    Book();

    void setBasic(const BookBasic& bookBasic);
    BookBasic basic() const noexcept;

    void setBasicNumbers(const BookBasicNumbers& bookBasic);
    BookBasicNumbers basicNumbers() const noexcept;

    void setRating(const BookRating& bookRating);
    BookRating rating() const noexcept;

    void setStorageLocation(const StorageLocation& location);
    StorageLocation storageLocation() const noexcept;

    void setPurchase(const BookPurchase& bookPurchase);
    BookPurchase purchase() const noexcept;

    void setSeries(const BookSeries& bookSeries);
    BookSeries series() const noexcept;

    void setTranslation(const BookTranslation& bookTranslation);
    BookTranslation translation() const noexcept;

    void setLoaned(const BookRentalStatus& rentalStatus);
    BookRentalStatus loaned() const noexcept;

    void setLent(const BookRentalStatus& rentalStatus);
    BookRentalStatus lent() const noexcept;

    void setSale(const BookSale& bookSale);
    BookSale sale() const noexcept;

    void setStatus(const BookStatus& bookStatus);
    BookStatus status() const noexcept;

    void setSourceOfOrigin(const BookSourceOfOrigin& bookSourceOfOrigin);
    BookSourceOfOrigin sourceOfOrigin() const noexcept;

    void setAdditives(const BookAdditives& bookAdditives);
    BookAdditives additives() const noexcept;

    void setDescription(const BookDescriprion& bookDesription);
    BookDescriprion description() const noexcept;

    void setImage(const BookImage& image);
    BookImage image() const noexcept;

private:
    BookBasic basic_;
    BookBasicNumbers basicNumbers_;
    BookRating rating_;
    StorageLocation storageLocation_;
    BookPurchase purchase_;
    BookSeries series_;
    BookTranslation translation_;
    BookRentalStatus loaned_;
    BookRentalStatus lent_;
    BookSale sale_;
    BookStatus status_;
    BookSourceOfOrigin sourceOfOrigin_;
    BookAdditives additives_;
    BookDescriprion description_;
    BookImage bookImage_;
};

#endif // BOOK_HPP
