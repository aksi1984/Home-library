#include "filterwidget.hpp"
#include "ui_filterwidget.h"

FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWidget)
{
    ui->setupUi(this);

    initConnect();
}

FilterWidget::~FilterWidget()
{
    delete ui;
}

void FilterWidget::initConnect()
{
    connect(ui->filterTitleLine, &QLineEdit::textChanged, this, &FilterWidget::titleSelectedEmit);
    connect(ui->filterAuthorLine, &QLineEdit::textChanged, this, &FilterWidget::authorSelectedEmit);
    connect(ui->filterCategoryCombo, &QComboBox::currentTextChanged, this, &FilterWidget::categorySelectedEmit);
    connect(ui->filterButtonReset, &QPushButton::clicked, this, &FilterWidget::reset);
}

QString FilterWidget::title() const noexcept
{
    return ui->filterTitleLine->text();
}

QString FilterWidget::author() const noexcept
{
    return ui->filterAuthorLine->text();
}

QString FilterWidget::category() const noexcept
{
    return ui->filterCategoryCombo->currentText();
}

//Slots

void FilterWidget::titleSelectedEmit()
{
    emit titleSelected();
}

void FilterWidget::authorSelectedEmit()
{
    emit authorSelected();
}

void FilterWidget::categorySelectedEmit()
{
    emit categorySelected();
}

void FilterWidget::reset()
{
    ui->filterTitleLine->setText("");
    ui->filterAuthorLine->setText("");
    ui->filterCategoryCombo->setCurrentIndex(0);
}
