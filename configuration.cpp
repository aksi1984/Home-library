#include "configuration.hpp"

Configuration::Configuration() { }

void Configuration::load()
{
    loadCategories();
    loadObjectsNames();
}

void Configuration::loadCategories()
{
    Categories::load();
}

void Configuration::loadObjectsNames()
{
    ObjectsNames::init();
}
