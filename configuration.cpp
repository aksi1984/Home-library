#include "configuration.hpp"

Configuration::Configuration() { }

void Configuration::load()
{
    loadCategories();
}

void Configuration::loadCategories()
{
    Categories::load();
}
