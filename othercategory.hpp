#ifndef OTHERCATEGORY_HPP
#define OTHERCATEGORY_HPP

#include <QDialog>

namespace Ui {
class OtherCategory;
}

class OtherCategory : public QDialog
{
    Q_OBJECT

public:
    explicit OtherCategory(QWidget *parent = nullptr);
    ~OtherCategory();

private:
    Ui::OtherCategory *ui;
};

#endif // OTHERCATEGORY_HPP
