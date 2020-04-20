#include "tree.hpp"
#include "ui_tree.h"
#include <QMessageBox>

Tree::Tree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tree),
    selectedText_{}
{
    ui->setupUi(this);

    ui->stackedWidget->setFixedWidth(200);
    ui->comboBox->setFixedWidth(200);

    editor_.setWidget(ui->stackedWidget);

    createConnect();
}

Tree::~Tree()
{
    delete ui;
}

void Tree::createConnect()
{
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Tree::setCurrentIndex);

    for(int i = 0; i < labels.size(); ++i)
    {
        QTreeView* tree = qobject_cast<QTreeView*>(ui->stackedWidget->widget(i));
        QItemSelectionModel* model = tree->selectionModel();

        connect(model, &QItemSelectionModel::selectionChanged, [this, i]{ setClickedItemNumber(i); });
    }
}

StackedWidgetEditor& Tree::editor()
{
    return editor_;
}

void Tree::addRow()
{
    auto text = BooksCollection::get()[BooksCollection::get().size() - 1];//1 5
    auto basic = text.basic().data();

    for(int i = 0, j = 0; i < basic.size() - 4; ++i)
    {
        if( (i != 1) && (i != 5) )
        {
            editor_.update(basic[i].toString(), j++);
        }
    }
}

QPair<QString, int> Tree::selectedItem() const noexcept
{
    return qMakePair(selectedText_, selectedIndex_);
}

void Tree::load()
{
    auto books = BooksCollection::get();

    for(int i = 0; i < books.size(); ++i)
    {
        for(int j = 0, k = 0; j < books[i].basic().data().size() - 4; ++j)
        {
            if( (j != 1) && (j != 5) )
            {
                editor_.update(books[i].basic().data()[j].toString(), k++);
            }
        }
    }

}

void Tree::setCurrentIndex()
{
    ui->stackedWidget->setCurrentIndex(ui->comboBox->currentIndex());
}

void Tree::setClickedItemNumber(int index)
{
    QTreeView* treeView = qobject_cast<QTreeView*>(ui->stackedWidget->widget(index));
    const QModelIndex model = treeView->selectionModel()->currentIndex();
    selectedText_ = model.data(Qt::DisplayRole).toString();
    selectedIndex_ = index;

    emit treeItemIsSelected();
}
