#include "tablebooks.hpp"
#include "ui_tablebooks.h"
#include <QMessageBox>

TableBooks::TableBooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableBooks)
{
    ui->setupUi(this);
}

TableBooks::~TableBooks()
{
    delete ui;
}

void TableBooks::addBook(const Book &book)
{

    ui->booksTableWidget->insertRow(ui->booksTableWidget->rowCount());
    int currentRow = ui->booksTableWidget->rowCount() - 1;

    General general = book.general();

    ui->booksTableWidget->setItem(currentRow, 0, new QTableWidgetItem(currentRow));
    ui->booksTableWidget->setItem(currentRow, 1, new QTableWidgetItem(general.ISBN()));
    ui->booksTableWidget->setItem(currentRow, 2, new QTableWidgetItem(general.title()));
    ui->booksTableWidget->setItem(currentRow, 3, new QTableWidgetItem(general.author()));
    ui->booksTableWidget->setItem(currentRow, 4, new QTableWidgetItem(general.category()));
    ui->booksTableWidget->setItem(currentRow, 5, new QTableWidgetItem(general.language()));
    ui->booksTableWidget->setItem(currentRow, 6, new QTableWidgetItem(general.publisher()));
    ui->booksTableWidget->setItem(currentRow, 7, new QTableWidgetItem(QString::number(general.publicationDate())));
    ui->booksTableWidget->setItem(currentRow, 8, new QTableWidgetItem(QString::number(general.numberOfPages())));

    QString isLoanedText = ( general.available() ? "Yes" : "No" );

    ui->booksTableWidget->setItem(currentRow, 9, new QTableWidgetItem(isLoanedText));

    setNonEditable(currentRow);
}

void TableBooks::setNonEditable(int row)
{
    for(int i = 0; i < ui->booksTableWidget->columnCount(); ++i)
    {
        ui->booksTableWidget->item(row, i)->setFlags(ui->booksTableWidget->item(row, i)->flags() ^ Qt::ItemIsEditable);
    }
}
