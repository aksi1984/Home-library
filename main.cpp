#include "application.hpp"
#include "configuration.hpp"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Configuration::load();
    // Load books and set the table and the tree. Must be a special class to it.

    a.setStyleSheet(StyleSheets::get());

    Application w;
    w.show();
    return a.exec();
}
