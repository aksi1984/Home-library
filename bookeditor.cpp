#include "bookeditor.hpp"
#include "ui_bookeditor.h"
#include "objectsnames.hpp"


BookEditor::BookEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookEditor),
    imageViev_{parent},
    noFilledStyleSheet_{"border: 1px solid #ca1010;"},
    changesHaveBeenSaved_{true},
    firstTimeSaved_{false}
{
    ui->setupUi(this);

    ui->imageViewLayout->addWidget(&imageViev_);

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
    imageViev_{parent},
    changesHaveBeenSaved_{true},
    firstTimeSaved_{true}
{
    ui->setupUi(this);
    ui->imageViewLayout->addWidget(&imageViev_);

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
    connect(&imageViev_, &ImageView::imageWasLoaded, this, &BookEditor::addImage);
    connect(&imageViev_, &ImageView::imageWasRemoved, this, &BookEditor::removeImage);
    connect(imageViev_.scene(), &Scene::itemIsSelected, this, &BookEditor::setImageToShow);

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
    book_.image().addFileName(imageViev_.fileName());
    changesHaveBeenSaved_ = false;
}

void BookEditor::setImageToShow()
{
    book_.image().setFileNameToShow(imageViev_.scene()->selectedItemPatch());
}

void BookEditor::removeImage()
{
    BookImage image{};
    book_.setImage(image);

    changesHaveBeenSaved_ = false;
}

void BookEditor::saveBook()
{
    saveBasic();
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
    book_.basic().setData(children);
}

void BookEditor::saveRatings()
{
    book_.ratings().setData(ui->pointsSpin, ui->readCheckBox, ui->iRecommentCheck);
}

void BookEditor::saveStorageLocation()
{
    book_.storageLocation().setData(ui->placeLine, ui->roomLine, ui->storageBookstandSpin, ui->storageShelfSpin);
}

void BookEditor::savePurchase()
{
    book_.purchase().setData(ui->purchasePlaceLine, ui->purchaseDate, ui->purchasePriceSpin, ui->purchaseValuationSpin);
}

void BookEditor::saveSeries()
{
    book_.series().setData(ui->nameLine, ui->partSpin, ui->numberSpin);
}

void BookEditor::saveTranslation()
{
    book_.translation().setData(ui->fromLanguageLine, ui->translationAuthorLine);
}

void BookEditor::saveLoaned()
{
    book_.loaned().setData(ui->loanedDateDate, ui->loanedToWhomLine);
}

void BookEditor::saveLent()
{
    book_.lent().setData(ui->lentDateDate, ui->lentToWhomLine);
}

void BookEditor::saveSale()
{
    book_.sale().setData(ui->saleDateDate, ui->salePlaceLine, ui->salePriceSpin);
}

void BookEditor::saveStatus()
{
    book_.status().setData(ui->damagedCheck, ui->giftCheck, ui->usedCheck);
}

void BookEditor::saveSourceOfOrigin()
{
    book_.source().setData(ui->sourceOfOriginCategoryLine, ui->sourceOfOriginDescrLine, ui->attachmentsLine);
}

void BookEditor::saveDescritpion()
{
    book_.description().setData(ui->commentsTextEdit, ui->reviewTextEdit);
}

void BookEditor::loadData()
{
    loadBasic();
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
    loadDescription();
    loadImage();
}

void BookEditor::loadBasic()
{
    QList<QLineEdit*> children = ui->tab->findChildren<QLineEdit*>();

    auto variants = book_.basic().data();
    putDataInWidget<QList<QLineEdit*>>(variants, children);
}

void BookEditor::loadRatings()
{
    auto variants = book_.ratings().data();
    putDataInWidget<QSpinBox*, QCheckBox*, QCheckBox*>(variants, ui->pointsSpin, ui->readCheckBox, ui->iRecommentCheck);
}

void BookEditor::loadStorageLocation()
{
    auto variants = book_.storageLocation().data();
    putDataInWidget<QLineEdit*, QLineEdit*, QSpinBox*, QSpinBox*>(variants, ui->placeLine, ui->roomLine, ui->storageBookstandSpin, ui->storageShelfSpin);
}

void BookEditor::loadPurchase()
{
    auto variants = book_.purchase().data();
    putDataInWidget<QLineEdit*, QDateEdit*, QDoubleSpinBox*, QDoubleSpinBox*>(variants, ui->purchasePlaceLine, ui->purchaseDate, ui->purchasePriceSpin, ui->purchaseValuationSpin);
}

void BookEditor::loadSeries()
{
    auto variants = book_.series().data();
    putDataInWidget<QLineEdit*, QSpinBox*, QSpinBox*>(variants, ui->nameLine, ui->partSpin, ui->numberSpin);
}

void BookEditor::loadTranslation()
{
    auto variants = book_.translation().data();
    putDataInWidget<QLineEdit*, QLineEdit*>(variants, ui->fromLanguageLine, ui->translationAuthorLine);
}

void BookEditor::loadLoaned()
{
    auto variants = book_.loaned().data();
    putDataInWidget<QDateEdit*, QLineEdit*>(variants, ui->loanedDateDate, ui->loanedToWhomLine);
}

void BookEditor::loadLent()
{
    auto variants = book_.lent().data();
    putDataInWidget<QDateEdit*, QLineEdit*>(variants, ui->lentDateDate, ui->lentToWhomLine);
}

void BookEditor::loadSale()
{
    auto variants = book_.sale().data();
    putDataInWidget<QDateEdit*, QLineEdit*, QDoubleSpinBox*>(variants, ui->saleDateDate, ui->salePlaceLine, ui->salePriceSpin);
}

void BookEditor::loadStatus()
{
    auto variants = book_.status().data();
    putDataInWidget<QCheckBox*, QCheckBox*, QCheckBox*>(variants, ui->damagedCheck, ui->giftCheck, ui->usedCheck);
}

void BookEditor::loadSourceOfOrigin()
{
    auto variants = book_.source().data();
    putDataInWidget<QLineEdit*, QLineEdit*, QLineEdit*>(variants, ui->sourceOfOriginCategoryLine, ui->sourceOfOriginDescrLine, ui->attachmentsLine);
}

void BookEditor::loadDescription()
{
    auto variants = book_.description().data();
    putDataInWidget<QTextEdit*, QTextEdit*>(variants, ui->commentsTextEdit, ui->reviewTextEdit);
}

void BookEditor::loadImage()
{
    for(int i = 0; i < book().image().fileNames().size(); ++i)
    {
        imageViev_.load(book().image().fileNames()[i]);
    }

    imageViev_.setImageChecked(book_.image().fileNameToShow());
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
                emit closeWithSaveData();

                saveBook();
                event->accept();
                QDialog::accept();
            }
            break;
            case QMessageBox::Cancel:
            {
                emit closeWithoutSaveData();

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
