#include "configuration.hpp"

Configuration::Configuration() { }

void Configuration::load()
{
    loadCategories();
    loadObjectsNames();
    loadStyleSheets();
}

void Configuration::loadCategories()
{
    Categories::load();
}

void Configuration::loadObjectsNames()
{
    ObjectsNames::init();
}

void Configuration::loadStyleSheets()
{
    StyleSheets::load();
}
