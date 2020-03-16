#include "bookstatus.hpp"

BookStatus::BookStatus() { }

BookStatus::BookStatus(bool reqDamaged, bool reqGift, bool reqUsed) :
    isBookDamaged_{reqDamaged},
    isBookGift_{reqGift},
    isBookUsed_{reqUsed} { }

void BookStatus::setBookDamaged(bool isDamaged)
{
    isBookDamaged_ = isDamaged;
}

void BookStatus::setBookGift(bool isGift)
{
    isBookGift_ = isGift;
}

void BookStatus::setBookUsed(bool isUsed)
{
    isBookUsed_ = isUsed;
}

bool BookStatus::isBookDamaged() const noexcept
{
    return isBookDamaged_;
}

bool BookStatus::isBookGift() const noexcept
{
    return isBookGift_;
}

bool BookStatus::isBookUsed() const noexcept
{
    return isBookUsed_;
}
