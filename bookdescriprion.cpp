#include "bookdescriprion.hpp"

BookDescriprion::BookDescriprion() { }

BookDescriprion::BookDescriprion(const QString& reqComments, const QString& reqReview) :
    comments_{reqComments},
    review_{reqReview} { }

void BookDescriprion::setComments(const QString &text)
{
    comments_ = text;
}

void BookDescriprion::setReview(const QString &text)
{
    review_ = text;
}

QString BookDescriprion::comments() const noexcept
{
    return comments_;
}

QString BookDescriprion::review() const noexcept
{
    return review_;
}
