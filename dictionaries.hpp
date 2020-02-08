#ifndef DICTIONARIES_HPP
#define DICTIONARIES_HPP

#include <QDialog>
#include <QtAlgorithms>

#include "categories.hpp"
#include "newcategorydialog.hpp"

namespace Ui {
class Dictionaries;
}

class Dictionaries : public QDialog
{
    Q_OBJECT

public:
    explicit Dictionaries(QWidget *parent = nullptr);
    ~Dictionaries();

private slots:

    void addCategory();
    void removeCategory();

private:
    Ui::Dictionaries *ui;

    void initButtons();
    void initListWidget();
};

#endif // DICTIONARIES_HPP
