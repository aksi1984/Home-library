#include "tableeditor.hpp"

TableEditor::TableEditor() :
    tableView_{new QTableView},
    itemModel_{new QStandardItemModel},
    filter_{new QSortFilterProxyModel},
    selectedRow_{} { }

void TableEditor::setTable(QTableView *tableView)
{
    tableView_ = tableView;
    itemModel_->setColumnCount(labels.size());
    itemModel_->setHorizontalHeaderLabels(labels);
    filter_->setSourceModel(itemModel_);

    tableView_->setSortingEnabled(true);
    tableView_->setModel(filter_);
}

void TableEditor::addBook(const Book &book)
{
    resizeRows();
    addData(book.basic().data(), itemModel_->rowCount());
}

void TableEditor::updateBook(const Book &book)
{
    itemModel_->removeRow(selectedRow_);
    addData(book.basic().data(), selectedRow_);
}

void TableEditor::removeBook()
{
    itemModel_->removeRow(selectedRow_);
}

void TableEditor::setSelectedRow()
{
    QItemSelection itemSelection = tableView_->selectionModel()->selection();
    selectedRow_ = itemSelection.indexes()[0].row();
    tableView_->selectRow(selectedRow_);
}

bool TableEditor::hasSelectedRow()
{
    QItemSelection selection = tableView_->selectionModel()->selection();
    return !selection.isEmpty();
}

int TableEditor::selectedRow() const noexcept
{
    return selectedRow_;
}

void TableEditor::setPattern(const QPair<QString, int> &data)
{
    setPattern(data.first, data.second);
}

void TableEditor::setPattern(const QString &pattern, int column)
{
    filter_->setFilterRegExp(pattern);
    filter_->setFilterKeyColumn(column);
}

bool TableEditor::isEmpty() const noexcept
{
    return itemModel_->rowCount() == 0;
}

//Private
void TableEditor::resizeRows()
{
    itemModel_->setRowCount(itemModel_->rowCount());
}

void TableEditor::addData(const QStringList &data, int row)
{
    QList<QStandardItem*> itemsList;

    for(int i = 0; i < labels.size() + 2; ++i)
    {
        if( (i != 1) && (i != 5) )
        {
            QStandardItem* item = new QStandardItem(data[i]);

            /*if( !(itemModel_->rowCount() % 2) )
            {
                item->setBackground(QBrush(QColor::fromRgb(172, 163, 163)));
            }*/

            item->setTextAlignment(Qt::AlignCenter);
            item->setEditable(false);
            itemsList.push_back(item);
        }
    }

    itemModel_->insertRow(row, itemsList);
}
