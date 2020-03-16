#include "bookbasic.hpp"

BookBasic::BookBasic() { }

BookBasic::BookBasic(const QStringList& reqData) :
    data_{reqData} { }

QStringList BookBasic::data() const noexcept
{
    return data_;
}
