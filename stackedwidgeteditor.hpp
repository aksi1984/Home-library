#ifndef STACKEDWIDGETEDITOR_HPP
#define STACKEDWIDGETEDITOR_HPP

#include <QStackedWidget>
#include <QTreeView>
#include <QStandardItemModel>

#include "common.hpp"
//#include "tableeditor.hpp"

class StackedWidgetEditor
{
public:
    StackedWidgetEditor();

    void setWidget(QStackedWidget* stackedWidget);
    void setParenthsModelText();
    void update(const QString &text, int index);

private:
    QStackedWidget* stackedWidget_;

    QVector<QTreeView*> views_;
    QVector<QStandardItemModel*> models_;
};

#endif // STACKEDWIDGETEDITOR_HPP
