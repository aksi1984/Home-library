#ifndef BOOKDATA_HPP
#define BOOKDATA_HPP

#include <QVariant>

#include "value.hpp"


class BookDetails
{
public:
    BookDetails() = default;
    BookDetails(int reqSize, const QString& reqStorageTypeName) :
        size_{reqSize},
        storageTypeName_{reqStorageTypeName} { }

    template<typename... Args>
    void setData(Args... args)
    {
        data_ = getVariants(size_, args...);
    }

    QVariantList data() const noexcept
    {
        return data_;
    }

    QVariantList& data()
    {
        return data_;
    }

    QString storageTypeName() const noexcept
    {
        return storageTypeName_;
    }

    int size() const noexcept
    {
        return size_;
    }

private:

    int size_;
    QString storageTypeName_;
    QVariantList data_;
};



#endif // BOOKDATA_HPP
