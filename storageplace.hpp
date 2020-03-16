#ifndef STORAGEPLACE_HPP
#define STORAGEPLACE_HPP

#include <QString>

class StorageLocation
{
public:
    StorageLocation();
    StorageLocation(const QString& reqPlace, const QString& reqRoom, int reqBookst, int reqShelf);

    void setPlaceName(const QString& text);
    void setRoom(const QString& text);
    void setBookstand(int value);
    void setShelf(int value);

    QString placeName() const noexcept;
    QString room() const noexcept;
    int bookstand() const noexcept;
    int shelf() const noexcept;

private:
    QString placeName_;
    QString room_;
    int bookstand_;
    int shelf_;
};

#endif // STORAGEPLACE_HPP
