#ifndef BOOKEDITOR_HPP
#define BOOKEDITOR_HPP

#include <QDialog>

#include "categoryselection.hpp"
#include "book.hpp"
#include "imageview.hpp"

namespace Ui {
class BookEditor;
}

class BookEditor : public QDialog
{
    Q_OBJECT

public:
    explicit BookEditor(QWidget *parent = nullptr);
    explicit BookEditor(const Book& reqBook, QWidget* parent = nullptr);
    ~BookEditor();

    Book book() const noexcept;

private slots:
    void openCategories();
    void saveBook();
    void addImage();
    void removeImage();
    void updateWidgetsState();

private:
    Ui::BookEditor *ui;

    void setMaximumOfDateWidget();
    void initTimer();
    void initConnect();

    void saveBasic();
    void saveBasicNumbers();
    void saveRatings();
    void saveStorageLocation();
    void savePurchase();
    void saveSeries();
    void saveTranslation();
    void saveLoaned();
    void saveLent();
    void saveSale();
    void saveStatus();
    void saveSourceOfOrigin();
    void saveAdditives();
    void saveDescritpion();

    void loadData();
    void loadBasic();
    void loadBasicNumbers();
    void loadRatings();
    void loadStorageLocation();
    void loadPurchase();
    void loadSeries();
    void loadTranslation();
    void loadLoaned();
    void loadLent();
    void loadSale();
    void loadStatus();
    void loadSourceOfOrigin();
    void loadAdditives();
    void loadDescription();
    void loadImage();

    void updateStyleSheet(bool isFilled);
    void updateButtonsEnabled(bool isFilled);

    QStringList generalData_;

    Book book_;
    ImageView* imageViev_;
    QTimer timer_;

    QString defaultStyleSheet_;
    QString noFilledStyleSheet_;
};

#endif // BOOKEDITOR_HPP
