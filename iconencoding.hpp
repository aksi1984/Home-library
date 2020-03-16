#ifndef ICONENCODING_HPP
#define ICONENCODING_HPP

#include <QToolBar>
#include <QFontDatabase>
#include <QMessageBox>

class IconEncoding
{
public:
    IconEncoding() = default;

    static void setActionsTexts(QToolBar* toolBar, QWidget* parent);

private:
    static QStringList texts_;
    static QString file_;
};

#endif // ICONENCODING_HPP
