#include "booksettings.hpp"
#include "ui_booksettings.h"
#include <QMessageBox>

BookSettings::BookSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookSettings)
{
    ui->setupUi(this);

    setMaximumYear();
    initTimer();
    initConnect();
}

BookSettings::~BookSettings()
{
    delete ui;
}

void BookSettings::setMaximumYear()
{
    ui->publicationDateSpinBox->setMaximum(QDate::currentDate().year());
}

void BookSettings::initTimer()
{
    timer.setInterval(1000);
    timer.start();
}

void BookSettings::initConnect()
{
    connect(&timer, &QTimer::timeout, this, &BookSettings::checkIfFieldsFilled);
    connect(ui->btnSave, &QPushButton::clicked, this, &BookSettings::createBook);
    connect(ui->btnCategory, &QPushButton::clicked, this, &BookSettings::openCategories);
    connect(ui->btnOK, &QPushButton::clicked, this, &BookSettings::accept);
}

void BookSettings::openCategories()
{
    CategorySelection* categorySelection = new CategorySelection;

    if(categorySelection->exec() == QDialog::Accepted)
    {
        ui->categoryLineEdit->setText(categorySelection->getCategory());
    }
}

void BookSettings::checkIfFieldsFilled()
{
    bool buttonEnabled = ( ui->titleLineEdit->text() != "" ? true : false );
    QString borderStyleSheet = ( buttonEnabled ? R"(QLineEdit{border: 1px solid black;})" : R"(border: 1px solid red;)" );

    ui->btnSave->setEnabled(buttonEnabled);
    ui->btnOK->setEnabled(buttonEnabled);

    ui->titleLineEdit->setStyleSheet(borderStyleSheet);
}

void BookSettings::createBook()
{
    createGeneral();
    createBookRating();
    createStoragePlace();
    createBookPurchase();
}

void BookSettings::createGeneral()
{
    General general;

    general.setTitle(ui->titleLineEdit->text());
    general.setSubTitle(ui->subtitleLineEdit->text());
    general.setOriginalTitle(ui->originalTitleLineEdit->text());
    general.setAuthor(ui->authorLineEdit->text());
    general.setEditorialOffice(ui->editOfficeLineEdit->text());
    general.setCategory(ui->categoryLineEdit->text());
    general.setPublisher(ui->publisherLineEdit->text());
    general.setPlaceOfPublication(ui->placeOfPublLineEdit->text());
    general.setPrintingHouse(ui->printLineEdit->text());
    general.setLanguage(ui->languageLineEdit->text());
    general.setISBN(ui->ISBNLineEdit->text());
    general.setID(ui->IDLineEdit->text());
    general.setEdition(ui->editOfficeLineEdit->text().toInt());
    general.setTome(ui->tomeLineEdit->text().toInt());
    general.setPublicationDate(ui->publicationDateSpinBox->value());
    general.setNumberOfPages(ui->numberOfPagesSpinBox->value());
    //general.setAvailable(ui->)

    book_.setGeneral(general);
}

Book BookSettings::book() const noexcept
{
    return book_;
}

void BookSettings::createBookRating()
{
    BookRating bookRating;

    bookRating.setPoints(ui->pointsSpinBox->value());
    bookRating.setRead(ui->readCheck->isChecked());
    bookRating.setRecommended(ui->recommCheck->isChecked());

    book_.setBookRating(bookRating);
}

void BookSettings::createStoragePlace()
{
    StoragePlace storagePlace;

    storagePlace.setPlaceName(ui->placeLineEdit->text());
    storagePlace.setRoom(ui->roomLineEdit->text());
    storagePlace.setBookstand(ui->bookstandLineEdit->text().toUInt());
    storagePlace.setShelf(ui->shelfLineEdit->text().toUInt());

    book_.setStoragePlace(storagePlace);
}

void BookSettings::createBookPurchase()
{
    BookPurchase bookPurchase;

    bookPurchase.setPlace(ui->purchasePlaceLineEdit->text());
    bookPurchase.setDate(ui->purchaseDateEdit->date());
    bookPurchase.setPrice(ui->priceSpinBox->value());
    bookPurchase.setValuation(ui->valuationSpinBox->value());

    book_.setBookPurchase(bookPurchase);
}
