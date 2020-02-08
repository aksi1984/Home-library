#ifndef TABLEBOOKS_HPP
#define TABLEBOOKS_HPP

#include <QWidget>

#include "book.hpp"

namespace Ui {
class TableBooks;
}

class TableBooks : public QWidget
{
    Q_OBJECT

public:
    explicit TableBooks(QWidget *parent = nullptr);
    ~TableBooks();

    void addBook(const Book& book);

private:
    Ui::TableBooks *ui;

    void setNonEditable(int row);
};

#endif // TABLEBOOKS_HPP
