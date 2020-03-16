#include "menueditor.hpp"

MenuEditor::MenuEditor(const QList<QAction *> &actions, QWidget *parent) :
    menu_{new QMenu{parent}}
{
    menu_->addActions(actions);
}

QMenu* MenuEditor::menu() const noexcept
{
    return menu_;
}
