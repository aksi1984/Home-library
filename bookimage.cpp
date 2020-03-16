#include "bookimage.hpp"

BookImage::BookImage() :
    fileName_{std::nullopt} { }

BookImage::BookImage(const QString& reqFileName) :
    fileName_{reqFileName} { }

std::optional<QString> BookImage::fileName()
{
    if(fileName_.has_value())
    {
        return fileName_.value();
    }
    else
    {
        return std::nullopt;
    }
}
