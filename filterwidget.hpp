#ifndef FILTERWIDGET_HPP
#define FILTERWIDGET_HPP

#include <QWidget>

#include "tableeditor.hpp"

namespace Ui {
class FilterWidget;
}

class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = nullptr);
    ~FilterWidget();

    QString title() const noexcept;
    QString author() const noexcept;
    QString category() const noexcept;

signals:
    void titleSelected();
    void authorSelected();
    void categorySelected();

protected slots:
    void titleSelectedEmit();
    void authorSelectedEmit();
    void categorySelectedEmit();
    void reset();

private:
    void initConnect();

    Ui::FilterWidget *ui;
};

#endif // FILTERWIDGET_HPP
