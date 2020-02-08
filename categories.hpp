#ifndef CATEGORIES_HPP
#define CATEGORIES_HPP

#include <QListWidgetItem>
#include "fileinput.hpp"

class Categories
{
public:
    Categories();

    static void load();
    static void save();
    static QStringList get() noexcept;
    static void insert(int index, const QString& text);
    static void remove(const QString& text);

private:

    static QStringList names;

};

#endif // CATEGORIES_HPP
