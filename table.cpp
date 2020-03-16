#include "table.hpp"
#include "ui_table.h"
#include <QMessageBox>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    createTable();
    createConnect();


}

Table::~Table()
{
    delete ui;
}

void Table::createTable()
{
    tableEditor_.setTable(ui->tableView);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
}

void Table::createConnect()
{
    connect(ui->tableView, &QTableView::clicked, this, &Table::updateSelectedTableRow);
    connect(ui->tableView, &QTableView::customContextMenuRequested, this, &Table::contextMenuIsRequested);
    connect(ui->filterTitleLine, &QLineEdit::textChanged, [this]{ tableEditor_.setPattern(ui->filterTitleLine->text(), 0); });
    connect(ui->filterAuthorLine, &QLineEdit::textChanged, [this]{ tableEditor_.setPattern(ui->filterAuthorLine->text(), 1); });
    connect(ui->filterCategoryCombo, &QComboBox::currentTextChanged, this, &Table::takeComboItemText);
    connect(ui->filterButtonReset, &QPushButton::clicked, this, &Table::resetFilterWidgets);
}

TableEditor Table::tableEditor() const noexcept
{
    return tableEditor_;
}

void Table::createContextMenu(const QList<QAction*>& actions)
{
    MenuEditor menuEditor(actions, ui->tableView);
    QMenu* menu = menuEditor.menu();
    menu->popup(ui->tableView->viewport()->mapToGlobal(contextMenuPoint_));
}

//Slots
void Table::updateSelectedTableRow()
{
    tableEditor_.setSelectedRow();
}

void Table::takeComboItemText()
{
    QString text = ui->filterCategoryCombo->currentText();

    if(ui->filterCategoryCombo->currentText() == "No modif.")
    {
        text = "";
    }
    else if(ui->filterCategoryCombo->currentText() == "Other...")
    {
        text = takeTextFromEditor();
    }
    else
    {
        text = ui->filterCategoryCombo->currentText();
    }

    tableEditor_.setPattern(text, 3);
}

QString Table::takeTextFromEditor()
{
    OtherCategory* other = new OtherCategory(this);
    QString text;

    if(other->exec() == QDialog::Accepted)
    {
        text = other->text();
    }

    return text;
}

void Table::resetFilterWidgets()
{
    ui->filterTitleLine->setText("");
    ui->filterAuthorLine->setText("");
    ui->filterCategoryCombo->setCurrentIndex(0);
}

void Table::contextMenuIsRequested(QPoint point)
{
    QModelIndex index = ui->tableView->indexAt(point);

    if(!tableEditor_.isEmpty() && index.isValid())
    {
        contextMenuPoint_ = point;
        tableEditor_.setSelectedRow();

        emit contextMenu();
    }
}
