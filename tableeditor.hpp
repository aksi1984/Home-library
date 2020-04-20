#ifndef TABLEEDITOR_HPP
#define TABLEEDITOR_HPP

#include <QTableView>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include "common.hpp"
#include "book.hpp"
#include "settings.hpp"

inline QStringList convert(const QVariantList& variants)
{
    QStringList data;

    for(auto x : variants) data.push_back(x.toString());

    return data;
}

class TableEditor
{
public:
    TableEditor();

    void setTable(QTableView* tableView);
    void addBook(const Book& book);
    void updateBook(const Book& book);
    void removeBook();
    void setSelectedRow();
    bool hasSelectedRow();
    int selectedRow() const noexcept;
    void setPattern(const QPair<QString, int>& data);
    void setPattern(const QString& pattern, int column);
    bool isEmpty() const noexcept;
    void load();

private:
    void resizeRows();
    void addData(const QStringList& data, int row);
    void selectAllCells();

    QTableView* tableView_;
    QStandardItemModel* itemModel_;
    QSortFilterProxyModel* filter_;

    int selectedRow_;
};

#endif // TABLEEDITOR_HPP
