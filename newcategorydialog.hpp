#ifndef NEWCATEGORYDIALOG_HPP
#define NEWCATEGORYDIALOG_HPP

#include <QDialog>

namespace Ui {
class NewCategoryDialog;
}

class NewCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCategoryDialog(int spinMaximum, QWidget *parent = nullptr);
    ~NewCategoryDialog();

    QString getCategoryName() const noexcept;
    int getPlace() const noexcept;

private:
    Ui::NewCategoryDialog *ui;

    void connectInit();
};

#endif // NEWCATEGORYDIALOG_HPP
