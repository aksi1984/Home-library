#ifndef BOOKIMAGE_HPP
#define BOOKIMAGE_HPP

#include <QString>
#include <optional>

class BookImage
{
public:
    BookImage();
    BookImage(const QString& reqFileName);

    std::optional<QString> fileName();

private:
    std::optional<QString> fileName_;
};

#endif // BOOKIMAGE_HPP
