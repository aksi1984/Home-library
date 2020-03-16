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

void Tree::addRow()
{
    auto text = BooksCollection::get()[BooksCollection::get().size() - 1];//1 5
    auto basic = text.basic().data();

    QStringList list;

    for(int i = 0; i < labels.size() + 2; ++i)
    {
        if( (i != 1) && (i != 5) )
        {
            list.push_back(basic[i]);
        }
    }

    for(int i = 0; i < list.size(); ++i)
    {
        editor_.update(list[i], i);
    }
}

QPair<QString, int> Tree::selectedItem() const noexcept
{
    return qMakePair(selectedText_, selectedIndex_);
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
