#include "shortdescription.hpp"
#include "ui_shortdescription.h"

ShortDescription::ShortDescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortDescription)
{
    ui->setupUi(this);
}

ShortDescription::~ShortDescription()
{
    delete ui;
}
