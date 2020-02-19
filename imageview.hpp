#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <QDialog>

namespace Ui {
class ImageView;
}

class ImageView : public QDialog
{
    Q_OBJECT

public:
    explicit ImageView(QWidget *parent = nullptr);
    ~ImageView();

private:
    Ui::ImageView *ui;
};

#endif // IMAGEVIEW_HPP
