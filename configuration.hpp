#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "categories.hpp"
#include "objectsnames.hpp"
#include "stylesheets.hpp"

class Configuration
{
public:
    Configuration();

    static void load();

private:
    static void loadCategories();
    static void loadObjectsNames();
    static void loadStyleSheets();
};

#endif // CONFIGURATION_HPP
