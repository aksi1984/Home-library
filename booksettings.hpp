#ifndef BOOKSETTINGS_HPP
#define BOOKSETTINGS_HPP

#include <QDialog>
#include <QLineEdit>
#include <QColor>

#include "bookcollection.hpp"
#include "categoryselection.hpp"

namespace Ui {
class BookSettings;
}

class BookSettings : public QDialog
{
    Q_OBJECT

public:
    explicit BookSettings(QWidget *parent = nullptr);
    ~BookSettings();

    Book book() const noexcept;

private slots:

    void openCategories();
    void checkIfFieldsFilled();
    void createBook();

private:
    Ui::BookSettings *ui;

    void initTimer();
    void initConnect();
    void setMaximumYear();

    void createGeneral();
    void createBookRating();
    void createStoragePlace();
    void createBookPurchase();

    Book book_;

    QTimer timer;
};

#endif // BOOKSETTINGS_HPP
