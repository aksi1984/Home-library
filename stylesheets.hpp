#ifndef STYLESHEETS_HPP
#define STYLESHEETS_HPP

#include "fileinput.hpp"

class StyleSheets
{
public:
    StyleSheets() = default;

    static void load(QWidget *parent = nullptr);
    static QString get() noexcept;

private:
    static QString styles_;
};

#endif // STYLESHEETS_HPP
