#ifndef OBJECTSNAMES_HPP
#define OBJECTSNAMES_HPP

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QDateEdit>
#include <QCheckBox>

#include "bookeditor.hpp"

template<typename Iterator>
QString getString(Iterator begin, Iterator end)
{
    QString str;

    for(auto iter = begin; iter != end; ++iter)
    {
        str.push_back(*iter);
    }

    return str;
}

/////////////////////////////////////////////////////

class ObjectsNames
{    
public:
    ObjectsNames() = default;

    static void init();
    static QStringList names();

private:
    static QStringList names_;
};

#endif // OBJECTSNAMES_HPP
