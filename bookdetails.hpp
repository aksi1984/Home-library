#ifndef BOOKDATA_HPP
#define BOOKDATA_HPP

#include <QVariant>

#include "value.hpp"


class BookDetails
{
public:
    BookDetails() = default;
    BookDetails(int sz) :
        size_{sz} { }

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

    int size() const noexcept
    {
        return size_;
    }

private:

    int size_;
    QVariantList data_;
};



#endif // BOOKDATA_HPP
