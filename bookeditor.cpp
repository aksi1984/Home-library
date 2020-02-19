#include "bookeditor.hpp"
#include "ui_bookeditor.h"

BookEditor::BookEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookEditor)
{
    ui->setupUi(this);
}

BookEditor::~BookEditor()
{
    delete ui;
}
