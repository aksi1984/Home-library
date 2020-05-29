#ifndef BOOKIMAGE_HPP
#define BOOKIMAGE_HPP

#include <QVector>
#include <QString>
#include <optional>

class BookImage
{
public:
    BookImage();
    BookImage(const QString& reqFileName);

    std::optional<QString> fileName();
    void addFileName(const QString& name);
    QVector<QString> fileNames() const noexcept;
    void setFileNameToShow(const QString& name);
    QString fileNameToShow() const noexcept;
    int size() const noexcept;

private:
    QVector<QString> fileNames_;
    std::optional<QString> fileName_;
    QString fileNameToShow_;
};

#endif // BOOKIMAGE_HPP
