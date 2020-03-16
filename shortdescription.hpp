#ifndef SHORTDESCRIPTION_HPP
#define SHORTDESCRIPTION_HPP

#include <QDialog>

namespace Ui {
class ShortDescription;
}

class ShortDescription : public QDialog
{
    Q_OBJECT

public:
    explicit ShortDescription(QWidget *parent = nullptr);
    ~ShortDescription();

private:
    Ui::ShortDescription *ui;
};

#endif // SHORTDESCRIPTION_HPP
