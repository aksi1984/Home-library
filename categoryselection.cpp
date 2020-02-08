#include "categoryselection.hpp"
#include "ui_categoryselection.h"

CategorySelection::CategorySelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategorySelection)
{
    ui->setupUi(this);

    initCategories();
    initTimer();
    updateButtonActivity();
    initConnect();
}

CategorySelection::~CategorySelection()
{
    delete ui;
}

void CategorySelection::initCategories()
{
    auto labels = Categories::get();
    ui->categoriesList->addItems(labels);
}

void CategorySelection::initTimer()
{
    timer.setInterval(1000);
    timer.start();
}

void CategorySelection::updateButtonActivity()
{
    bool buttonEnabled = ( !ui->categoriesList->selectedItems().empty() ? true : false);
    ui->btnSelect->setEnabled(buttonEnabled);
}

void CategorySelection::initConnect()
{
    connect(ui->btnSelect, &QPushButton::clicked, this, &CategorySelection::accept);
    connect(&timer, &QTimer::timeout, this, &CategorySelection::updateButtonActivity);
}

QString CategorySelection::getCategory() const noexcept
{
    return ui->categoriesList->selectedItems()[0]->text();
}


