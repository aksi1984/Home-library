#include "pdfsettings.hpp"
#include "ui_pdfsettings.h"

PdfSettings::PdfSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PdfSettings)
{
    ui->setupUi(this);

    initCheckBoxesList();
    initTimer();
    initConnect();
}

PdfSettings::~PdfSettings()
{
    delete ui;
}

void PdfSettings::initCheckBoxesList()
{
    checkBoxesList_ = ui->optionsGroupBox->findChildren<QCheckBox*>();
}

void PdfSettings::initTimer()
{
    timer_.setInterval(1000);
    timer_.start();
}

void PdfSettings::initConnect()
{
    connect(&timer_, &QTimer::timeout, this, &PdfSettings::countChecked);
    connect(ui->buttonOK, &QPushButton::clicked, this, &PdfSettings::accept);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &PdfSettings::reject);
}

void PdfSettings::setAcceptButtonEnabled()
{
    bool enabled = ( checked_.isEmpty() ? false : true );

    ui->buttonOK->setEnabled(enabled);
}

void PdfSettings::countChecked()
{
    QVector<int> temp;

    for(int i = 0; i < checkBoxesList_.size(); ++i)
    {
        if(checkBoxesList_[i]->isChecked())
        {
            temp.push_back(i);
        }
    }

    checked_ = qMove(temp);

    setAcceptButtonEnabled();
}

QVector<int> PdfSettings::checked() const noexcept
{
    return checked_;
}
