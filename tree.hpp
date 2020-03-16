#ifndef TREE_HPP
#define TREE_HPP

#include <QWidget>

#include "bookscollection.hpp"
#include "stackedwidgeteditor.hpp"

namespace Ui {
class Tree;
}

class Tree : public QWidget
{
    Q_OBJECT

public:
    explicit Tree(QWidget *parent = nullptr);
    ~Tree();

    void addRow();
    QPair<QString, int> selectedItem() const noexcept;

signals:
    void treeItemIsSelected();


private slots:
    void setCurrentIndex();

private:
    void createConnect();
    void setClickedItemNumber(int index);

    Ui::Tree *ui;

    StackedWidgetEditor editor_;

    QString selectedText_;
    int selectedIndex_;
};

#endif // TREE_HPP
