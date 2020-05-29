#include "scene.hpp"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QKeyEvent>
#include <QIcon>

Scene::Scene() { }

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    auto selectedItems = this->selectedItems();

    QMessageBox::Icon icon;
    QString message;
    QString title;

    if(selectedItems.size() > 1)
    {
        title = "Warning";
        icon = QMessageBox::Icon::Warning;
        message = "The number of selected images must be exaclty 1.";
    }
    else
    {
        selectedItemPatch_ = selectedItems[0]->data(0).toString();
        title = "Image selected";
        icon = QMessageBox::Icon::Information;
        message = "The image " + selectedItemPatch_ + " will be show.";

        emit itemIsSelected();
    }

    QMessageBox mb(icon, title, message, QMessageBox::Ok);
    mb.exec();
}

QString Scene::selectedItemPatch() const noexcept
{
    return selectedItemPatch_;
}
