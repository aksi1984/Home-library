#ifndef TREE_HPP
#define TREE_HPP

#include <QWidget>

namespace Ui {
class Tree;
}

class Tree : public QWidget
{
    Q_OBJECT

public:
    explicit Tree(QWidget *parent = nullptr);
    ~Tree();

private:
    Ui::Tree *ui;
};

#endif // TREE_HPP
