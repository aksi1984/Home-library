#include "application.h"
#include "ui_application.h"
#include <QMessageBox>
Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application),
      tableBooks(new TableBooks)
{
    ui->setupUi(this);
    ui->tableLayout->addWidget(tableBooks);

    initButtons();

    FileInput fi;
    fi.load(R"(D:\Documents\Projects\HomeLibrary\txt\categories.txt)");
}

Application::~Application()
{
    delete ui;
}

void Application::initButtons()
{
    connect(ui->actionClose, &QAction::triggered, this, &Application::close);
    connect(ui->actionDictionaries, &QAction::triggered, this, &Application::openDictionaries);
    connect(ui->actionAdd, &QAction::triggered, this, &Application::openBookEdition);
}

// Slots

void Application::openDictionaries()
{
    Dictionaries* dictionaries = new Dictionaries;

    dictionaries->exec();
}

void Application::openBookEdition()
{
    BookSettings* bookSettings = new BookSettings;

    bookSettings->setModal(true);

    if(bookSettings->exec() == QDialog::Accepted)
    {
        BookCollection::addBook(bookSettings->book());
        tableBooks->addBook(bookSettings->book());
    }


}
