#include "othercategory.hpp"
#include "ui_othercategory.h"

OtherCategory::OtherCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OtherCategory)
{
    ui->setupUi(this);

    initTimer();
    initConnect();

    ui->buttonOK->setEnabled(false);
}

OtherCategory::~OtherCategory()
{
    delete ui;
}

void OtherCategory::initTimer()
{
    timer_.setInterval(1000);
    timer_.start();
}

void OtherCategory::initConnect()
{
    connect(&timer_, &QTimer::timeout, this, &OtherCategory::updateButtonEnabled);
    connect(ui->buttonOK, &QPushButton::clicked, this, &OtherCategory::accept);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &OtherCategory::reject);
}

QString OtherCategory::text() const noexcept
{
    return ui->categoryLineEdit->text();
}

void OtherCategory::updateButtonEnabled()
{
    bool enabled = ( !ui->categoryLineEdit->text().isEmpty() ? true : false );
    ui->buttonOK->setEnabled(enabled);
}
