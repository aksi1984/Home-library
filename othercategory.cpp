#include "othercategory.hpp"
#include "ui_othercategory.h"

OtherCategory::OtherCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OtherCategory)
{
    ui->setupUi(this);
}

OtherCategory::~OtherCategory()
{
    delete ui;
}
