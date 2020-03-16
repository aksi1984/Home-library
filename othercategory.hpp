#ifndef OTHERCATEGORY_HPP
#define OTHERCATEGORY_HPP

#include <QDialog>
#include <QTimer>

namespace Ui {
class OtherCategory;
}

class OtherCategory : public QDialog
{
    Q_OBJECT

public:
    explicit OtherCategory(QWidget *parent = nullptr);
    ~OtherCategory();

    QString text() const noexcept;

private slots:
    void updateButtonEnabled();

private:
    void initTimer();
    void initConnect();

    Ui::OtherCategory *ui;

    QTimer timer_;
};

#endif // OTHERCATEGORY_HPP
