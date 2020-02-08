#ifndef CATEGORYSELECTION_HPP
#define CATEGORYSELECTION_HPP

#include <QDialog>
#include <QTimer>

#include "categories.hpp"

namespace Ui {
class CategorySelection;
}

class CategorySelection : public QDialog
{
    Q_OBJECT

public:
    explicit CategorySelection(QWidget *parent = nullptr);
    ~CategorySelection();

    QString getCategory() const noexcept;

private slots:

    void updateButtonActivity();

private:
    Ui::CategorySelection *ui;

    void initCategories();
    void initTimer();
    void initConnect();

    QTimer timer;
};

#endif // CATEGORYSELECTION_HPP
