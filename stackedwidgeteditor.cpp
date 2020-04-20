#include "stackedwidgeteditor.hpp"

StackedWidgetEditor::StackedWidgetEditor() :
    stackedWidget_{new QStackedWidget} { }

void StackedWidgetEditor::setWidget(QStackedWidget *stackedWidget)
{
    stackedWidget_ = stackedWidget;

    for(int i = 0; i < labels.size(); ++i)
    {
       QTreeView* view = new QTreeView;
       QStandardItemModel* model = new QStandardItemModel;
       view->setModel(model);
       views_.push_back(view);
       models_.push_back(model);
       stackedWidget_->insertWidget(i, views_[i]);
    }

    setParenthsModelText();

    stackedWidget_->setCurrentIndex(0);
}

void StackedWidgetEditor::setParenthsModelText()
{
    for(int i = 0; i < labels.size(); ++i)
    {
        QStandardItem* item = new QStandardItem(labels[i]);
        item->setEditable(false);
        models_[i]->setItem(0, 0, item);
    }
}

void StackedWidgetEditor::update(const QString& text, int index)
{
    QStandardItem* item = new QStandardItem(text);
    item->setEditable(false);
    models_[index]->item(0, 0)->insertRow(models_[index]->item(0, 0)->rowCount(), item);
}
