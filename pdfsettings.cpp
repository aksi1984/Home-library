#include "pdfsettings.hpp"
#include "ui_pdfsettings.h"

PdfSettings::PdfSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PdfSettings)
{
    ui->setupUi(this);
}

PdfSettings::~PdfSettings()
{
    delete ui;
}
