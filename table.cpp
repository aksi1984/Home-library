#include "table.hpp"
#include "ui_table.h"


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
}

TableEditor Table::tableEditor() const noexcept
{
    return tableEditor_;
}

TableEditor& Table::tableEditor()
{
    return tableEditor_;
}

void Table::createContextMenu(const QList<QAction*>& actions)
{
    MenuEditor menuEditor(actions, ui->tableView);
    QMenu* menu = menuEditor.menu();
    menu->popup(ui->tableView->viewport()->mapToGlobal(contextMenuPoint_));
}

void Table::setCategoryFromFilter(const QString &category)
{
    QString text = category;

    if(category == "No modif.")
    {
        text = "";
    }
    else if(category == "Other...")
    {
        text = takeTextFromEditor();
    }
    else
    {
        text = category;
    }

    tableEditor_.setPattern(text, 3);
}

//Slots
void Table::updateSelectedTableRow()
{
    tableEditor_.setSelectedRow();
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
