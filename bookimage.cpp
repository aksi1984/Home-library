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

void BookImage::addFileName(const QString &name)
{
    fileNames_.push_back(name);
}

QVector<QString> BookImage::fileNames() const noexcept
{
    return fileNames_;
}

void BookImage::setFileNameToShow(const QString &name)
{
    fileNameToShow_ = name;
}

QString BookImage::fileNameToShow() const noexcept
{
    return fileNameToShow_;
}

int BookImage::size() const noexcept
{
    return fileNames_.size();
}
