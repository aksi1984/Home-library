#include "booktranslation.hpp"

BookTranslation::BookTranslation() { }

BookTranslation::BookTranslation(const QString& reqOrigTrans, const QString& reqAuthor) :
    originalLanguage_{reqOrigTrans},
    author_{reqAuthor} { }

void BookTranslation::setOriginalLanguage(const QString &text)
{
    originalLanguage_ = text;
}

void BookTranslation::setAuthor(const QString &text)
{
    author_ = text;
}

QString BookTranslation::originalLanguage() const noexcept
{
    return originalLanguage_;
}

QString BookTranslation::author() const noexcept
{
    return author_;
}
