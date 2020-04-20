#ifndef BOOKBASICNUMBERS_HPP
#define BOOKBASICNUMBERS_HPP

//#include <QVariant>

class BookBasicNumbers
{
public:
    BookBasicNumbers();
    BookBasicNumbers(int reqPublicationDate, int reqEdition, int reqPages, int reqTome);

    int publicationDate() const noexcept;
    int edition() const noexcept;
    int numberOfPages() const noexcept;
    int tome() const noexcept;



private:

   // QVector<QVariant> variants_;

    int publicationDate_;
    int edition_;
    int numberOfPages_;
    int tome_;
};

#endif // BOOKBASICNUMBERS_HPP
