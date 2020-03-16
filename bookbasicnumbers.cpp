#include "bookbasicnumbers.hpp"

BookBasicNumbers::BookBasicNumbers() { }

BookBasicNumbers::BookBasicNumbers(int reqPublicationDate, int reqEdition, int reqPages, int reqTome) :
    publicationDate_{reqPublicationDate},
    edition_{reqEdition},
    numberOfPages_{reqPages},
    tome_{reqTome} { }

int BookBasicNumbers::publicationDate() const noexcept
{
    return publicationDate_;
}

int BookBasicNumbers::edition() const noexcept
{
    return edition_;
}

int BookBasicNumbers::numberOfPages() const noexcept
{
    return numberOfPages_;
}

int BookBasicNumbers::tome() const noexcept
{
    return tome_;
}
