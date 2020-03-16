#include "bookeditor.hpp"
#include "ui_bookeditor.h"
#include "objectsnames.hpp"
#include <QMessageBox>

BookEditor::BookEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookEditor),
    imageViev_{new ImageView(parent)},
    noFilledStyleSheet_{"border: 1px solid #ca1010;"},
    changesHaveBeenSaved_{true},
    firstTimeSaved_{false}
{
    ui->setupUi(this);

    ui->imageViewLayout->addWidget(imageViev_);

    defaultStyleSheet_ = ui->titleLine->styleSheet();

    setMaximumOfDateWidget();
    initTimer();
    initConnect();

    QLocale locale;
    ui->purchasePriceSpin->setSuffix(" " + locale.currencySymbol());
    ui->purchaseValuationSpin->setSuffix(" " + locale.currencySymbol());
}

BookEditor::BookEditor(const Book& reqBook, QWidget* parent) :
    QDialog{parent},
    ui{new Ui::BookEditor},
    book_{reqBook},
    imageViev_{new ImageView},
    changesHaveBeenSaved_{true}
{
    ui->setupUi(this);
    ui->imageViewLayout->addWidget(imageViev_);

    setMaximumOfDateWidget();
    initTimer();
    initConnect();
    loadData();
}

BookEditor::~BookEditor()
{
    delete ui;
}

void BookEditor::setMaximumOfDateWidget()
{
    ui->publicationDateSpin->setMaximum(QDate::currentDate().year());
}

void BookEditor::initTimer()
{
    timer_.setInterval(1000);
    timer_.start();
}

void BookEditor::initConnect()
{
    connect(&timer_, &QTimer::timeout, this, &BookEditor::updateWidgetsState);
    connect(ui->categoryButton, &QPushButton::clicked, this, &BookEditor::openCategories);
    connect(ui->pdfButton, &QPushButton::clicked, this, &BookEditor::createPdf);
    connect(ui->buttonSave, &QPushButton::clicked, this, &BookEditor::saveBook);
    connect(ui->buttonOK, &QPushButton::clicked, this, &BookEditor::accept);
    connect(ui->buttonClose, &QPushButton::clicked, this, &BookEditor::aboutClose);
    connect(imageViev_, &ImageView::imageWasLoaded, this, &BookEditor::addImage);
    connect(imageViev_, &ImageView::imageWasRemoved, this, &BookEditor::removeImage);

    QList<QLineEdit*> lineEdits = ui->tabWidget->findChildren<QLineEdit*>();

    for(auto lineEdit : lineEdits)
    {
        connect(lineEdit, &QLineEdit::textChanged, this, &BookEditor::dataWasBeenChanged);
    }
}

void BookEditor::openCategories()
{
    CategorySelection* categories = new CategorySelection;

    if(categories->exec() == QDialog::Accepted)
    {
        ui->categoryLine->setText(categories->getCategory());
    }
}

void BookEditor::addImage()
{
    BookImage image(imageViev_->fileName());
    book_.setImage(image);

    changesHaveBeenSaved_ = false;
}

void BookEditor::removeImage()
{
    BookImage image;
    book_.setImage(image);

    changesHaveBeenSaved_ = false;
}

void BookEditor::saveBook()
{
    saveBasic();
    saveBasicNumbers();
    saveRatings();
    saveStorageLocation();
    savePurchase();
    saveSeries();
    saveTranslation();
    saveLoaned();
    saveLent();
    saveSale();
    saveStatus();
    saveSourceOfOrigin();
    saveAdditives();
    saveDescritpion();

    changesHaveBeenSaved_ = true;

    if(!firstTimeSaved_)
    {
        firstTimeSaved_ = true;
    }
}

void BookEditor::saveBasic()
{
    QList<QLineEdit*> children = ui->tab->findChildren<QLineEdit*>();

    QStringList data;

    for(int i = 0; i < 15; ++i)
    {
        QString text = ( !children[i]->text().isEmpty() ? children[i]->text() : "-" );
        data.push_back(text);
    }

    BookBasic bookBasic(data);
    book_.setBasic(bookBasic);
}

void BookEditor::saveBasicNumbers()
{
    BookBasicNumbers basicNumbers(ui->publicationDateSpin->value(), ui->editionSpin->value(),
                                  ui->numberOfPagesSpin->value(), ui->tomeSpin->value());

    book_.setBasicNumbers(basicNumbers);
}

void BookEditor::saveRatings()
{
    BookRating rating(ui->pointsSpin->value(), ui->readCheckBox->isChecked(), ui->iRecommentCheck->isChecked());
    book_.setRating(rating);
}

void BookEditor::saveStorageLocation()
{
    StorageLocation location(ui->placeLine->text(), ui->roomLine->text(),
                             ui->storageBookstandSpin->value(), ui->storageShelfSpin->value());

    book_.setStorageLocation(location);
}

void BookEditor::savePurchase()
{
    BookPurchase purchase(ui->purchasePlaceLine->text(), ui->purchaseDate->date(),
                          ui->purchasePriceSpin->value(), ui->purchaseValuationSpin->value());

    book_.setPurchase(purchase);
}

void BookEditor::saveSeries()
{
    BookSeries series(ui->nameLine->text(), ui->partSpin->value(), ui->numberSpin->value());
    book_.setSeries(series);
}

void BookEditor::saveTranslation()
{
    BookTranslation translation(ui->fromLanguageLine->text(), ui->translationAuthorLine->text());
    book_.setTranslation(translation);
}

void BookEditor::saveLoaned()
{
    BookRentalStatus loaned(ui->loanedDateDate->date(), ui->loanedToWhomLine->text());
    book_.setLoaned(loaned);
}

void BookEditor::saveLent()
{
    BookRentalStatus lent(ui->lentDateDate->date(), ui->lentToWhomLine->text());
    book_.setLent(lent);
}

void BookEditor::saveSale()
{
    BookSale bookSale(ui->saleDateDate->date(), ui->salePlaceLine->text(), ui->salePriceSpin->value());
    book_.setSale(bookSale);
}

void BookEditor::saveStatus()
{
    BookStatus bookStatus(ui->damagedCheck->isChecked(), ui->giftCheck->isChecked(), ui->usedCheck->isChecked());
    book_.setStatus(bookStatus);
}

void BookEditor::saveSourceOfOrigin()
{
    BookSourceOfOrigin sourceOfOrigin(ui->sourceOfOriginCategoryLine->text(), ui->sourceOfOriginDescrLine->text());
    book_.setSourceOfOrigin(sourceOfOrigin);
}

void BookEditor::saveAdditives()
{
    BookAdditives additives(ui->attachmentsLine->text());
    book_.setAdditives(additives);
}

void BookEditor::saveDescritpion()
{
    BookDescriprion description(ui->commentsTextEdit->toPlainText(), ui->reviewTextEdit->toPlainText());
    book_.setDescription(description);
}

void BookEditor::loadData()
{
    loadBasic();
    loadBasicNumbers();
    loadRatings();
    loadStorageLocation();
    loadPurchase();
    loadSeries();
    loadTranslation();
    loadLoaned();
    loadLent();
    loadSale();
    loadStatus();
    loadSourceOfOrigin();
    loadAdditives();
    loadDescription();
    loadImage();
}

void BookEditor::loadBasic()
{
    QList<QLineEdit*> children = ui->tab->findChildren<QLineEdit*>();

    QStringList data = book_.basic().data();

    for(int i = 0; i < 15; ++i)
    {
        children[i]->setText(data[i]);
    }
}

void BookEditor::loadBasicNumbers()
{
    BookBasicNumbers basicNumbers = book_.basicNumbers();

    ui->publicationDateSpin->setValue(basicNumbers.publicationDate());
    ui->editionSpin->setValue(basicNumbers.edition());
    ui->numberOfPagesSpin->setValue(basicNumbers.numberOfPages());
    ui->tomeSpin->setValue(basicNumbers.tome());
}

void BookEditor::loadRatings()
{
    BookRating rating = book_.rating();

    ui->pointsSpin->setValue(rating.points());
    ui->readCheckBox->setChecked(rating.isRead());
    ui->iRecommentCheck->setChecked(rating.isRecommended());
}

void BookEditor::loadStorageLocation()
{
    StorageLocation location = book_.storageLocation();

    ui->placeLine->setText(location.placeName());
    ui->roomLine->setText(location.room());
    ui->storageBookstandSpin->setValue(location.bookstand());
    ui->storageShelfSpin->setValue(location.shelf());
}

void BookEditor::loadPurchase()
{
    BookPurchase purchase = book_.purchase();

    ui->purchasePlaceLine->setText(purchase.place());
    ui->purchaseDate->setDate(purchase.date());
    ui->purchasePriceSpin->setValue(purchase.price());
    ui->purchaseValuationSpin->setValue(purchase.valuation());
}

void BookEditor::loadSeries()
{
    BookSeries series = book_.series();

    ui->nameLine->setText(series.name());
    ui->partSpin->setValue(series.part());
    ui->numberSpin->setValue(series.number());
}

void BookEditor::loadTranslation()
{
    BookTranslation translation = book_.translation();

    ui->fromLanguageLine->setText(translation.originalLanguage());
    ui->translationAuthor->setText(translation.author());
}

void BookEditor::loadLoaned()
{
    BookRentalStatus loaned = book_.loaned();

    ui->loanedDateDate->setDate(loaned.date());
    ui->loanedToWhomLine->setText(loaned.personName());
}

void BookEditor::loadLent()
{
    BookRentalStatus lent = book_.lent();

    ui->lentDateDate->setDate(lent.date());
    ui->lentToWhomLine->setText(lent.personName());
}

void BookEditor::loadSale()
{
    BookSale sale = book_.sale();

    ui->saleDateDate->setDate(sale.date());
    ui->salePlaceLine->setText(sale.personName());
    ui->salePriceSpin->setValue(sale.price());
}

void BookEditor::loadStatus()
{
    BookStatus status = book_.status();

    ui->damagedCheck->setChecked(status.isBookDamaged());
    ui->giftCheck->setChecked(status.isBookGift());
    ui->usedCheck->setChecked(status.isBookUsed());
}

void BookEditor::loadSourceOfOrigin()
{
    BookSourceOfOrigin sourceOfOrigin = book_.sourceOfOrigin();

    ui->sourceOfOriginCategoryLine->setText(sourceOfOrigin.category());
    ui->sourceOfOriginDescrLine->setText(sourceOfOrigin.description());
}

void BookEditor::loadAdditives()
{
    BookAdditives additives = book_.additives();

    ui->attachmentsLine->setText(additives.attachments());
}

void BookEditor::loadDescription()
{
    BookDescriprion description = book_.description();

    ui->commentsTextEdit->setPlainText(description.comments());
    ui->reviewTextEdit->setPlainText(description.review());
}

void BookEditor::loadImage()
{
    BookImage image = book_.image();

    if(image.fileName() != std::nullopt)
    {
        imageViev_->load(image.fileName().value());
    }
}

void BookEditor::updateStyleSheet(bool isFilled)
{
    QString currentStyleSheet = ( isFilled ? defaultStyleSheet_ : noFilledStyleSheet_ );
    ui->titleLine->setStyleSheet(currentStyleSheet);
}

void BookEditor::updateButtonsEnabled(bool isFilled)
{
    ui->pdfButton->setEnabled(isFilled);
    ui->buttonOK->setEnabled(isFilled && firstTimeSaved_);

    bool saveButtonEnabled = ( changesHaveBeenSaved_ ? false : true );
    ui->buttonSave->setEnabled(saveButtonEnabled);
}

void BookEditor::updateWidgetsState()
{
    bool isFilled = ( ui->titleLine->text().size() != 0 );

    updateStyleSheet(isFilled);
    updateButtonsEnabled(isFilled);
}

void BookEditor::dataWasBeenChanged()
{
    changesHaveBeenSaved_ = false;
}

void BookEditor::createPdf()
{
    PdfSettings pdfSettings(this);

    if(pdfSettings.exec() == QDialog::Accepted)
    {
        saveToFile(this, book_, pdfSettings.checked());
    }
}

void BookEditor::aboutClose()
{
    if(!changesHaveBeenSaved_)
    {
        int ret = closeWarning();

        switch(ret)
        {
        case QMessageBox::Save:
            {
                saveBook();

                QDialog::accept();
            }
            break;
        case QMessageBox::No:
            {
                QDialog::reject();
            }
            break;
        default:
            break;
        }
    }
    else
    {
        QDialog::reject();
    }
}

void BookEditor::closeEvent(QCloseEvent *event)
{
    if(!changesHaveBeenSaved_ && !firstTimeSaved_)
    {
        int ret = closeWarning();

        switch(ret)
        {
            case QMessageBox::Save:
            {
                saveBook();
                event->accept();
                QDialog::accept();
            }
            break;
            case QMessageBox::Cancel:
            {
                event->ignore();
            }
            break;
        default:
            break;
        }
    }
}

int BookEditor::closeWarning()
{
    int ret = QMessageBox::warning(this, "Warning", "The document has been modified\n"
                                   "Do you want to save your changes ?",
                                   QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);

    return ret;
}

Book BookEditor::book() const noexcept
{
    return book_;
}
