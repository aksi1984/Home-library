#include "bookrating.hpp"

BookRating::BookRating() { }

void BookRating::setPoints(unsigned int value)
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
