#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPathItem>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();

    QString selectedItemPatch() const noexcept;

signals:
    void itemIsSelected();

protected:
   void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

private:
   QString selectedItemPatch_;
};

#endif // SCENE_HPP
