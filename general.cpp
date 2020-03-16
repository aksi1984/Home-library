#include "general.hpp"

General::General() { }

void General::setData(const QStringList &dt)
{
    data_ = dt;
}

QStringList General::data() const noexcept
{
    return data_;
}
