#ifndef XMLFILE_HPP
#define XMLFILE_HPP

#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QWidget>
#include <QFile>

#include "bookscollection.hpp"

class XMLFile
{
public:
    XMLFile();

    void save(QWidget* parent);

private:
    void saveBook(const Book &book, QXmlStreamWriter& writer);
    void saveBookDetails(const BookDetails& bookDetails, QXmlStreamWriter& writer);
};

#endif // XMLFILE_HPP
