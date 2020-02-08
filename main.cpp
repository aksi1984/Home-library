#include "application.h"
#include "configuration.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Configuration::load();

    Application w;
    w.show();
    return a.exec();
}
