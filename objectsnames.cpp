#include "objectsnames.hpp"

QStringList ObjectsNames::names_;

void ObjectsNames::init()
{
    BookEditor* bookEditor = new BookEditor;
    QTabWidget* tableWidget = bookEditor->findChild<QTabWidget*>("tabWidget");
    QList<QWidget*> children = tableWidget->findChildren<QWidget*>();

    for(int i = 0; i < children.size(); ++i)
    {
        if(qobject_cast<QLineEdit*>(children[i]) || qobject_cast<QSpinBox*>(children[i]) ||
           qobject_cast<QDoubleSpinBox*>(children[i]) || qobject_cast<QDateEdit*>(children[i]) ||
           qobject_cast<QTextEdit*>(children[i]) || qobject_cast<QCheckBox*>(children[i]))
        {
            QString name = children[i]->objectName();

            if(name != "qt_spinbox_lineedit")
            {
                names_.push_back(name);
            }
        }
    }

    delete bookEditor;
}

QStringList ObjectsNames::names()
{
    return names_;
}
