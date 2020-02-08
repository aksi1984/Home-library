#include "newcategorydialog.hpp"
#include "ui_newcategorydialog.h"

NewCategoryDialog::NewCategoryDialog(int spinMaximum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCategoryDialog)
{
    ui->setupUi(this);
    ui->placeSpinBox->setMaximum(spinMaximum);

    connectInit();
}

NewCategoryDialog::~NewCategoryDialog()
{
    delete ui;
}

void NewCategoryDialog::connectInit()
{
    connect(ui->btnOK, &QPushButton::clicked, this, &NewCategoryDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &NewCategoryDialog::reject);
}

QString NewCategoryDialog::getCategoryName() const noexcept
{
    return ui->categoryEdit->text();
}

int NewCategoryDialog::getPlace() const noexcept
{
    return ui->placeSpinBox->value();
}
