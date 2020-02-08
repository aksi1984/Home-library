#include "storageplace.hpp"

StoragePlace::StoragePlace() { }

void StoragePlace::setPlaceName(const QString &text)
{
    placeName_ = text;
}

void StoragePlace::setRoom(const QString &text)
{
    room_ = text;
}

void StoragePlace::setBookstand(unsigned int value)
{
    bookstand_ = value;
}

void StoragePlace::setShelf(unsigned int value)
{
    shelf_ = value;
}

QString StoragePlace::placeName() const noexcept
{
    return placeName_;
}

QString StoragePlace::room() const noexcept
{
    return room_;
}

unsigned StoragePlace::bookstand() const noexcept
{
    return bookstand_;
}

unsigned StoragePlace::shelf() const noexcept
{
    return shelf_;
}
