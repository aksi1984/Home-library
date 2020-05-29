#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "bookdataio.hpp"
#include "conversion.hpp"


Q_DECLARE_METATYPE(Book);

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
