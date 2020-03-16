#ifndef TABLE_HPP
#define TABLE_HPP

#include <QWidget>

#include "tableeditor.hpp"
#include "book.hpp"
#include "othercategory.hpp"
#include "menueditor.hpp"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

    TableEditor tableEditor() const noexcept;

    void createContextMenu(const QList<QAction*>& actions);

signals:
    void contextMenu();

private slots:
    void updateSelectedTableRow();
    void takeComboItemText();
    void resetFilterWidgets();
    void contextMenuIsRequested(QPoint);

private:
    void createTable();
    void createConnect();
    QString takeTextFromEditor();

    Ui::Table *ui;

    TableEditor tableEditor_;
    QPoint contextMenuPoint_;
};

#endif // TABLE_HPP
