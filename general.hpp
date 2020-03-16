#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <QStringList>

class General
{
public:
    General();

    void setData(const QStringList& dt);
    QStringList data() const noexcept;

private:
    QStringList data_;
};

#endif // GENERAL_HPP
