#include "imageview.hpp"
#include "ui_imageview.h"

ImageView::ImageView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageView)
{
    ui->setupUi(this);
}

ImageView::~ImageView()
{
    delete ui;
}
