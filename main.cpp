#include "application.hpp"
#include "configuration.hpp"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Configuration::load();

    a.setStyleSheet(StyleSheets::get());

    Application w;
    w.show();
    return a.exec();
}
