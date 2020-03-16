#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "categories.hpp"
#include "objectsnames.hpp"

class Configuration
{
public:
    Configuration();

    static void load();

private:
    static void loadCategories();
    static void loadObjectsNames();
};

#endif // CONFIGURATION_HPP
