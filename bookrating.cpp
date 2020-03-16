#include "bookrating.hpp"

BookRating::BookRating() { }

BookRating::BookRating(int reqPoints, bool reqIsRead, bool reqIRecomm) :
    points_{reqPoints},
    isRead_{reqIsRead},
    isRecommended_{reqIRecomm} { }

void BookRating::setPoints(int value)
{
    points_ = value;
}

void BookRating::setRead(bool cond)
{
    isRead_ = cond;
}

void BookRating::setRecommended(bool cond)
{
    isRecommended_ = cond;
}

int BookRating::points() const noexcept
{
    return points_;
}

bool BookRating::isRead() const noexcept
{
    return isRead_;
}

bool BookRating::isRecommended() const noexcept
{
    return isRecommended_;
}
