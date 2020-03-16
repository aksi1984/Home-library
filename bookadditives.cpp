#include "bookadditives.hpp"

BookAdditives::BookAdditives() { }

BookAdditives::BookAdditives(const QString& reqAttachments) :
    attachments_{reqAttachments} { }

void BookAdditives::setAttachments(const QString &text)
{
    attachments_ = text;
}

QString BookAdditives::attachments() const noexcept
{
    return attachments_;
}
