#include "settings.hpp"

QString Settings::scope_ = "BLib";

Settings::Settings() { }

void Settings::saveBooks()
{
    qRegisterMetaTypeStreamOperators<Book>("Book");

    QSettings settings("books", QSettings::IniFormat);

    auto books = BooksCollection::get();

    if(!books.isEmpty())
    {
        QString keyPattern = "book_";

        settings.setValue("size", BooksCollection::get().size());

        for(int i = 0; i < books.size(); ++i)
        {
            QString currentKey = keyPattern + QString::number(i);
            QVariant var;
            var.setValue(books[i]);
            settings.setValue(currentKey, var);
        }
    }
}

void Settings::loadBooks()
{
    qRegisterMetaTypeStreamOperators<Book>("Book");

    QSettings settings("books", QSettings::IniFormat);

    int size = settings.value("size").toInt();

    if(size != 0)
    {
        for(int i = 0; i < size; ++i)
        {
            QVariant var = settings.value("book_" + QString::number(i));
            Book book = var.value<Book>();
            BooksCollection::addBook(book);
        }
    }
}
