#include "booksourceoforigin.hpp"

BookSourceOfOrigin::BookSourceOfOrigin() { }

BookSourceOfOrigin::BookSourceOfOrigin(const QString& reqCategory, const QString& reqDescription) :
    category_{reqCategory},
    description_{reqDescription} { }

void BookSourceOfOrigin::setCategory(const QString &text)
{
    category_ = text;
}

void BookSourceOfOrigin::setDescription(const QString &text)
{
    description_ = text;
}

QString BookSourceOfOrigin::category() const noexcept
{
    return category_;
}

QString BookSourceOfOrigin::description() const noexcept
{
    return description_;
}
