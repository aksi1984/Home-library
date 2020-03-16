#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <QDialog>
#include <QFileDialog>
#include <QPicture>
#include <QTimer>

namespace Ui {
class ImageView;
}

class ImageView : public QDialog
{
    Q_OBJECT

public:
    explicit ImageView(QWidget *parent = nullptr);
    ~ImageView();

    void load(const QString& reqFileName);
    QString fileName() const noexcept;

signals:
    void imageWasLoaded();
    void imageWasRemoved();

private slots:
    void updateRemoveButtonEnabled();
    void loadImage();
    void removeImage();

private:
    Ui::ImageView *ui;

    void initTimer();
    void initConnect();
    void loadPixmap();
    void fitToLabel(QPixmap &pixmap);

    QTimer timer_;
    QString fileName_;

    const int labelWidth_;
    const int labelHeight_;
};

#endif // IMAGEVIEW_HPP
