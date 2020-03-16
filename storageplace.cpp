#include "storageplace.hpp"

StorageLocation::StorageLocation() { }

StorageLocation::StorageLocation(const QString& reqPlace, const QString& reqRoom, int reqBookst, int reqShelf) :
    placeName_{reqPlace},
    room_{reqRoom},
    bookstand_{reqBookst},
    shelf_{reqShelf} { }

void StorageLocation::setPlaceName(const QString &text)
{
    placeName_ = text;
}

void StorageLocation::setRoom(const QString &text)
{
    room_ = text;
}

void StorageLocation::setBookstand(int value)
{
    bookstand_ = value;
}

void StorageLocation::setShelf(int value)
{
    shelf_ = value;
}

QString StorageLocation::placeName() const noexcept
{
    return placeName_;
}

QString StorageLocation::room() const noexcept
{
    return room_;
}

int StorageLocation::bookstand() const noexcept
{
    return bookstand_;
}

int StorageLocation::shelf() const noexcept
{
    return shelf_;
}
