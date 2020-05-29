#include "xmlfile.hpp"

XMLFile::XMLFile() { }

void XMLFile::save(QWidget *parent)
{
    QString fileName = QFileDialog::getSaveFileName(parent, "Save file", "books", "XML files(*.xml)");

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement("BOOKS");

    auto books = BooksCollection::get();

    for(int i = 0; i < books.size(); ++i)
    {
        writer.writeStartElement("Book_" + QString::number(i));
        saveBook(books[i], writer);
        writer.writeEndElement();
    }

    writer.writeStartElement("Data status");
    writer.writeTextElement("Total books", QString::number(books.size()));
    writer.writeEndElement();
    writer.writeEndElement();

    writer.writeEndDocument();

    file.close();
}

void XMLFile::saveBook(const Book& book, QXmlStreamWriter& writer)
{
    saveBookDetails(book.basic(), writer);
    saveBookDetails(book.ratings(), writer);
    saveBookDetails(book.storageLocation(), writer);
    saveBookDetails(book.purchase(), writer);
    saveBookDetails(book.series(), writer);
    saveBookDetails(book.translation(), writer);
    saveBookDetails(book.loaned(), writer);
    saveBookDetails(book.lent(), writer);
    saveBookDetails(book.status(), writer);
    saveBookDetails(book.source(), writer);
    saveBookDetails(book.description(), writer);
}

void XMLFile::saveBookDetails(const BookDetails &bookDetails, QXmlStreamWriter &writer)
{
    writer.writeStartElement(bookDetails.storageTypeName());
    auto data = bookDetails.data();

    for(int i = 0; i < data.size(); ++i)
    {
        QString text = data[i].toString();
        writer.writeTextElement("data_" + QString::number(i), text);
    }

    writer.writeEndElement();
}
