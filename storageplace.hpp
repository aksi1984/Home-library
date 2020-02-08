#ifndef STORAGEPLACE_HPP
#define STORAGEPLACE_HPP

#include <QString>

class StoragePlace
{
public:
    StoragePlace();

    void setPlaceName(const QString& text);
    void setRoom(const QString& text);
    void setBookstand(unsigned value);
    void setShelf(unsigned value);

    QString placeName() const noexcept;
    QString room() const noexcept;
    unsigned bookstand() const noexcept;
    unsigned shelf() const noexcept;

private:
    QString placeName_;
    QString room_;
    unsigned bookstand_;
    unsigned shelf_;
};

#endif // STORAGEPLACE_HPP
