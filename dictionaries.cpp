#include "dictionaries.hpp"
#include "ui_dictionaries.h"

Dictionaries::Dictionaries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dictionaries)
{
    ui->setupUi(this);

    initButtons();
    initListWidget();
}

Dictionaries::~Dictionaries()
{
    delete ui;
}

void Dictionaries::initButtons()
{
    connect(ui->btnClose, &QPushButton::clicked, this, &Dictionaries::close);
    connect(ui->btnAdd, &QPushButton::clicked, this, &Dictionaries::addCategory);
    connect(ui->btnRemove, &QPushButton::clicked, this, &Dictionaries::removeCategory);
}

void Dictionaries::initListWidget()
{
    auto labels = Categories::get();
    ui->dictionariesList->addItems(labels);
}

void Dictionaries::addCategory()
{
    NewCategoryDialog* newCategoryDialog = new NewCategoryDialog(ui->dictionariesList->count());

    if(newCategoryDialog->exec() == QDialog::Accepted)
    {
        ui->dictionariesList->insertItem(newCategoryDialog->getPlace(), newCategoryDialog->getCategoryName());
        Categories::insert(newCategoryDialog->getPlace(), newCategoryDialog->getCategoryName());
    }
}

void Dictionaries::removeCategory()
{
    auto selectedItems = ui->dictionariesList->selectedItems();
    Categories::remove(selectedItems[0]->text());

    qDeleteAll(selectedItems.begin(), selectedItems.end());
}

