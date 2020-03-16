#ifndef BOOKEDITOR_HPP
#define BOOKEDITOR_HPP

#include <QDialog>
#include <QCloseEvent>
#include <QLocale>
#include <QMessageBox>

#include "categoryselection.hpp"
#include "book.hpp"
#include "imageview.hpp"
#include "pdfdocument.hpp"
#include "pdfsettings.hpp"

inline void saveToFile(QWidget* widget, const Book& book, const QVector<int>& checked)
{
    QString fileName = QFileDialog::getSaveFileName(widget, "Save", "/home", "PDF document(*.pdf)");
    QList<QLabel*> labels = widget->findChildren<QLabel*>();

    PdfDocument pdfDocument(fileName, book, labels, checked);
    pdfDocument.start();

    QMessageBox::information(widget, "File saved", "File saved in path: " + fileName + ".", QMessageBox::ButtonRole::ApplyRole);
}


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
    void dataWasBeenChanged();
    void createPdf();

    void aboutClose();

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

    int closeWarning();
    virtual void closeEvent(QCloseEvent *) override;

    QStringList generalData_;

    Book book_;
    ImageView* imageViev_;
    QTimer timer_;

    QString defaultStyleSheet_;
    QString noFilledStyleSheet_;

    bool changesHaveBeenSaved_;
    bool firstTimeSaved_;
};

#endif // BOOKEDITOR_HPP
