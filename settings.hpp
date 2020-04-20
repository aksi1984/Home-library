#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "bookdataio.hpp"
#include "conversion.hpp"

Q_DECLARE_METATYPE(Book);

/*template<typename... Ts>
QStringList getList(Ts... ts)
{
    QVector<QVariant> variants;
    ( variants.push_back(ts), ... );

    QStringList list;

    for(auto x : variants) list.push_back(x.toString());

    return list;
}*/

class Settings
{
public:
    Settings();

    static void saveBooks();
    static void loadBooks();

private:

    static void removeBooks();

    static QString scope_;
};

#endif // SETTINGS_HPP
