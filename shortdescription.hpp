#ifndef SHORTDESCRIPTION_HPP
#define SHORTDESCRIPTION_HPP

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "book.hpp"

namespace Ui {
class ShortDescription;
}

class ShortDescription : public QDialog
{
    Q_OBJECT

public:
    explicit ShortDescription(QWidget *parent = nullptr);
    ~ShortDescription();

    void setText(const Book& book);
    void setImage(const std::optional<QString> fileName);

private:
    Ui::ShortDescription *ui;

    QGraphicsScene scene_;
};

#endif // SHORTDESCRIPTION_HPP
