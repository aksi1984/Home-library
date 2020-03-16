#include "application.hpp"
#include "ui_application.h"
#include <QMessageBox>


Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
    , table_{new Table}
    , tree_(new Tree(this))
    , shortDecription_{new ShortDescription(this)}
{
    ui->setupUi(this);

    setCentralWidget(table_);

    createDockWidgets();
    createToolBar();
    initTimer();
    initConnect();
}

Application::~Application()
{
    delete ui;
}

void Application::createDockWidgets()
{
    QDockWidget* leftDock = new QDockWidget("Tree", this);
    leftDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    leftDock->setWidget(tree_);

    QDockWidget* rightDock = new QDockWidget("Book description", this);
    rightDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    rightDock->setWidget(shortDecription_);

    addDockWidget(Qt::LeftDockWidgetArea, leftDock);
    addDockWidget(Qt::RightDockWidgetArea, rightDock);
}

void Application::createToolBar()
{
    IconEncoding::setActionsTexts(ui->toolBar, this);
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
    connect(ui->actionMakeCopy, &QAction::triggered, this, &Application::makeCopy);
    connect(ui->actionEdit, &QAction::triggered, this, &Application::editBook);
    connect(ui->actionRemove, &QAction::triggered, this, &Application::removeBook);
    connect(ui->toolBarActionAdd, &QAction::triggered, this, &Application::openBookEditor);
    connect(ui->toolBarActionMakeCopy, &QAction::triggered, this, &Application::makeCopy);
    connect(ui->toolBarActionEdit, &QAction::triggered, this, &Application::editBook);
    connect(ui->toolBarActionRemove, &QAction::triggered, this, &Application::removeBook);
    connect(tree_, &Tree::treeItemIsSelected, this, &Application::showText);
    connect(table_, &Table::contextMenu, this, &Application::createTableContextMenu);
}

// Slots

void Application::openDictionaries()
{
    Dictionaries dictionaries;

    dictionaries.exec();
}

void Application::makeCopy()
{
    Book bookCopy = BooksCollection::getBook(table_->tableEditor().selectedRow());

    table_->tableEditor().addBook(bookCopy);
    BooksCollection::addBook(bookCopy);
}

void Application::openBookEditor()
{
    BookEditor* bookEditor = new BookEditor(this);

    if(bookEditor->exec() == QDialog::Accepted)
    {
        table_->tableEditor().addBook(bookEditor->book());
        BooksCollection::addBook(bookEditor->book());
        tree_->addRow();
    }
}

void Application::editBook()
{
    Book book = BooksCollection::getBook(table_->tableEditor().selectedRow());

    BookEditor bookEditor(book);

    if(bookEditor.exec() == QDialog::Accepted)
    {
        table_->tableEditor().updateBook(bookEditor.book());
        BooksCollection::updateBook(bookEditor.book(), table_->tableEditor().selectedRow());
    }
}

void Application::removeBook()
{
    table_->tableEditor().removeBook();
}

void Application::updateSelectedTableRow()
{
    table_->tableEditor().setSelectedRow();
}

void Application::updateButtonsEnabled()
{
    bool enabled = { table_->tableEditor().hasSelectedRow() ? true : false };

    ui->actionMakeCopy->setEnabled(enabled);
    ui->actionRemove->setEnabled(enabled);
    ui->actionEdit->setEnabled(enabled);
    ui->toolBarActionMakeCopy->setEnabled(enabled);
    ui->toolBarActionRemove->setEnabled(enabled);
    ui->toolBarActionEdit->setEnabled(enabled);

    if(enabled)
    {
        int selectedBook = table_->tableEditor().selectedRow();
        Book book = BooksCollection::getBook(selectedBook);
        QString text = book.description().review();
        shortDecription_->setText(text);

        //if(auto fileName = book.image().fileName(); fileName != std::nullopt)
        //{
            shortDecription_->setImage(book.image().fileName());
        //}
    }
}

void Application::showText()
{
    table_->tableEditor().setPattern(tree_->selectedItem());
}

void Application::createTableContextMenu()
{
    auto actions = actionsInRange(5, 10, ui->toolBar->actions());

    table_->createContextMenu(actions);
}

