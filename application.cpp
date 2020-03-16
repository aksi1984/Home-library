#include "application.h"
#include "ui_application.h"
#include <QMessageBox>
Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
    , tableOfBooks(new TableOfBooks)
{
    ui->setupUi(this);
    ui->tableLayout->addWidget(tableOfBooks);

    initTimer();
    initConnect();

    FileInput fi;
    fi.load(R"(D:\Documents\Projects\HomeLibrary\txt\categories.txt)");
}

Application::~Application()
{
    delete ui;
}

void Application::initTimer()
{
    timer_.setInterval(1000);
    timer_.start();
}

void Application::initConnect()
{
    connect(&timer_, &QTimer::timeout, this, &Application::updateButtonsEnabled);
    connect(ui->actionClose, &QAction::triggered, this, &Application::close);
    connect(ui->actionDictionaries, &QAction::triggered, this, &Application::openDictionaries);
    connect(ui->actionAdd, &QAction::triggered, this, &Application::openBookEditor);
    connect(ui->actionEdit, &QAction::triggered, this, &Application::editBook);
    connect(ui->actionRemove, &QAction::triggered, this, &Application::removeBook);
}

// Slots

void Application::openDictionaries()
{
    Dictionaries* dictionaries = new Dictionaries;

    dictionaries->exec();
}

void Application::makeCopy()
{
    Book bookCopy = BooksCollection::getBook(tableOfBooks->selected());

    tableOfBooks->addBook(bookCopy);
    BooksCollection::addBook(bookCopy);
}

void Application::openBookEditor()
{
    BookEditor* bookEditor = new BookEditor;

    if(bookEditor->exec() == QDialog::Accepted)
    {
        tableOfBooks->addBook(bookEditor->book());

        BooksCollection::addBook(bookEditor->book());
    }
}

void Application::editBook()
{
    Book book = BooksCollection::getBook(tableOfBooks->selected());

    BookEditor* bookEditor = new BookEditor(book);

    if(bookEditor->exec() == QDialog::Accepted)
    {
        tableOfBooks->updateBook(bookEditor->book());
        BooksCollection::updateBook(bookEditor->book(), tableOfBooks->selected());
    }
}

void Application::removeBook()
{
    tableOfBooks->removeBook();
}

void Application::updateButtonsEnabled()
{
    bool enabled = ( tableOfBooks->isSelected() ? true : false );

    ui->actionMakeCopy->setEnabled(enabled);
    ui->actionRemove->setEnabled(enabled);
    ui->actionEdit->setEnabled(enabled);
}
