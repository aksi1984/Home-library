#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "categories.hpp"

class Configuration
{
public:
    Configuration();

    static void load();

private:
    static void loadCategories();
};

#endif // CONFIGURATION_HPP
