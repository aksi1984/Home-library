#ifndef BOOKEDITOR_HPP
#define BOOKEDITOR_HPP

#include <QDialog>

namespace Ui {
class BookEditor;
}

class BookEditor : public QDialog
{
    Q_OBJECT

public:
    explicit BookEditor(QWidget *parent = nullptr);
    ~BookEditor();

private:
    Ui::BookEditor *ui;
};

#endif // BOOKEDITOR_HPP
