#ifndef MENUEDITOR_HPP
#define MENUEDITOR_HPP

#include <QMenu>

class MenuEditor
{
public:
    MenuEditor(const QList<QAction*>& actions, QWidget* parent = nullptr);

    QMenu* menu() const noexcept;

private:
    QMenu* menu_;
};

#endif // MENUEDITOR_HPP
