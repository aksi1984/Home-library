#include "application.hpp"
#include "ui_application.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
    , filterWidget_{new FilterWidget(this)}
    , table_{new Table}
    , tree_(new Tree)
    , shortDecription_{new ShortDescription(this)}
    , dataHasBeenSaved_{true}
{
    ui->setupUi(this);

    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(filterWidget_);
    rightLayout->addWidget(table_);
    rightLayout->addWidget(shortDecription_);
    mainLayout->addWidget(tree_);
    mainLayout->addLayout(rightLayout);
    widget->setLayout(mainLayout);

    actionGroup_ = new QActionGroup(ui->menuLanguage);

    languages_.addMenu(ui->menuLanguage);
    languages_.createActions();
    languages_.addActionGroup(actionGroup_);

    table_->tableEditor().setItemsText(tree_->itemsText());

    initTimer();
    initConnect();

    Settings::loadBooks();
    table_->tableEditor().load();
    tree_->load();
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
    connect(ui->actionSave, &QAction::triggered, this, &Application::saveProgram);
    connect(ui->actionSave_as, &QAction::triggered, this, &Application::save);
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
    connect(actionGroup_, SIGNAL(triggered(QAction*)), this, SLOT(languageChanged(QAction*)));

    connect(filterWidget_, &FilterWidget::titleSelected, [this]{ table_->tableEditor().setPattern(filterWidget_->title(), 0); });
    connect(filterWidget_, &FilterWidget::authorSelected, [this]{ table_->tableEditor().setPattern(filterWidget_->author(), 1); });
    connect(filterWidget_, &FilterWidget::categorySelected, [this]{ table_->setCategoryFromFilter(filterWidget_->category()); });
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

    setAsUnsaved();
}

void Application::openBookEditor()
{
    BookEditor bookEditor(this);

    if(bookEditor.exec() == QDialog::Accepted)
    {
        table_->tableEditor().addBook(bookEditor.book());
        BooksCollection::addBook(bookEditor.book());
        tree_->addRow();
        setAsUnsaved();
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
        setAsUnsaved();
    }
}

void Application::removeBook()
{
    table_->tableEditor().removeBook();

    setAsUnsaved();
}

void Application::updateSelectedTableRow()
{
    table_->tableEditor().setSelectedRow();
}

void Application::updateButtonsEnabled()
{
    bool enabled = { table_->tableEditor().hasSelectedRow() ? true : false };

    ui->actionSave->setEnabled(!dataHasBeenSaved_);
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
        shortDecription_->setText(book);
        shortDecription_->setImage(book.image().fileNameToShow());
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

void Application::languageChanged(QAction* action)
{
    languages_.changeLanguage(action);
    qApp->removeTranslator(&translator_);
    translator_.load(languages_.currentLanguage());
    qApp->installTranslator(&translator_);

    ui->retranslateUi(this);
}

void Application::saveProgram()
{
    Categories::save();
    Settings::saveBooks();

    setAsSaved();
}

void Application::save()
{
    XMLFile xmlFile;
    xmlFile.save(this);
}

void Application::setAsSaved()
{
    dataHasBeenSaved_ = true;
}

void Application::setAsUnsaved()
{
    dataHasBeenSaved_ = false;
}

void Application::closeEvent(QCloseEvent *e)
{
    if(!dataHasBeenSaved_)
    {
        int ret = QMessageBox::warning(this, "Warning",
                                       "Program data has not been saved. Do you want to save?",
                                       QMessageBox::Save |
                                       QMessageBox::Discard |
                                       QMessageBox::Cancel);

        switch(ret)
        {
        case 0:
        {
            saveProgram();
            e->accept();
        }
            break;
        case 1:
        {
            e->accept();
        }
            break;
        default: break;

        }

        e->accept();
    }
    else
    {
        e->accept();
    }
}

