#include "pdfdocument.hpp"

#include <QMessageBox>

PdfDocument::PdfDocument(const QString &reqFileName, const Book &reqBook, QList<QLabel*> labels, const QVector<int> &checked) :
    fileName_{reqFileName},
    book_{reqBook},
    labels_{labels},
    printer_{QPrinter::PrinterResolution},
    textCursor_{&textDocument_},
    checked_{checked},
    cols_{2},
    functions_{
                [this]{ addGeneral(); },
                [this]{ addRatings(); },
                [this]{ addStorageLocation(); },
                [this]{ addPurchase(); },
                [this]{ addSeries(); },
                [this]{ addTranslation(); },
                [this]{ addLoaned(); },
                [this]{ addLent(); },
                [this]{ addSale(); },
                [this]{ addSource(); },
                [this]{ addAttach(); },
                [this]{ addDescr(); }
               }
{
    createPrinter();
    createTableFormat();
    createCharFormat();
}

void PdfDocument::start()
{
    for(auto x : checked_)
    {
        functions_[x]();
    }

    textDocument_.print(&printer_);
}

void PdfDocument::create(const QString& category, const QStringList &labels, const QStringList &data)
{
    QTextCharFormat categoryFormat;
    categoryFormat.setFont(QFont("Times", 10, QFont::Bold));
    categoryFormat.setUnderlineStyle(QTextCharFormat::UnderlineStyle::SingleUnderline);

    textCursor_.insertText(category, categoryFormat);
    textCursor_.insertBlock();
    textCursor_.insertBlock();

    QTextTable* textTable = textCursor_.insertTable(labels.size(), cols_, textTableFormat_);
    QTextCursor temp;

    for(int i = 0; i < textTable->rows(); ++i)
    {
        QTextTableCell descrCell = textTable->cellAt(i, TableCol::Description);
        QTextCursor descrCursor = descrCell.firstCursorPosition();
        descrCursor.insertText(labels[i]);

        QTextTableCell dataCell = textTable->cellAt(i, TableCol::Data);
        QTextCursor dataCursor = dataCell.firstCursorPosition();
        dataCursor.insertText(" : " + data[i]);

        if(i == textTable->rows() - 1)
        {
            temp = descrCursor;
        }
    }

    temp.movePosition(QTextCursor::Down);
    textCursor_ = temp;

    textCursor_.insertBlock();
    textCursor_.insertBlock();
    textCursor_.insertBlock();
}

QStringList PdfDocument::getDescription(int first, int last)
{
    QStringList descr;

    for(int i = first; i < last; ++i)
    {
        descr.push_back(labels_[i]->text());
    }

    return descr;
}

void PdfDocument::addGeneral()
{
    QStringList descr = getDescription(15, 30);

    QStringList data = book_.basic().data();

    data += QStringList{QString::number(book_.basicNumbers().publicationDate()),
                        QString::number(book_.basicNumbers().numberOfPages()),
                        QString::number(book_.basicNumbers().tome())};

    create("BASIC INFORMATION", descr, data);
}

void PdfDocument::addRatings()
{
    QStringList descr{"Points", "Read", "Recommended"};

    QString isRecommendedStr = ( book_.rating().isRecommended() ? "Yes" : "No" );
    QString isReadStr = ( book_.rating().isRead() ? "Yes" : "No" );

    QStringList data{QString::number(book_.rating().points()), isReadStr, isRecommendedStr};

    create("RATINGS", descr, data);
}

void PdfDocument::addStorageLocation()
{
    QStringList descr = getDescription(32, 36);

    QStringList data{book_.storageLocation().placeName(),
                     book_.storageLocation().room(),
                     QString::number(book_.storageLocation().bookstand()),
                     QString::number(book_.storageLocation().shelf())
                    };

    create("STORAGE LOCATION", descr, data);
}

void PdfDocument::addPurchase()
{
    QLocale locale;

    QStringList descr = getDescription(36, 40);

    QStringList data{book_.purchase().place(),
                     book_.purchase().date().toString(),
                     QString::number(book_.purchase().price()) + " " + locale.currencySymbol(),
                     QString::number(book_.purchase().valuation()) + " " + locale.currencySymbol()
                    };

    create("PURCHASE", descr, data);
}

void PdfDocument::addSeries()
{
    QStringList descr = getDescription(0, 3);

    QStringList data{book_.series().name(),
                     QString::number(book_.series().part()),
                     QString::number(book_.series().number())
                    };

    create("SERIES", descr, data);
}

void PdfDocument::addTranslation()
{
    QStringList descr = getDescription(3, 5);

    QStringList data{book_.translation().originalLanguage(),
                     book_.translation().author()
                    };

    create("TRANSLATION", descr, data);
}

void PdfDocument::addLoaned()
{
    QStringList descr = getDescription(5, 7);

    QStringList data{book_.loaned().date().toString(),
                     book_.loaned().personName()
                    };

    create("LOANED", descr, data);
}

void PdfDocument::addLent()
{
    QStringList descr = getDescription(7, 9);

    QStringList data{book_.lent().date().toString(),
                     book_.lent().personName()
                    };

    create("LENT", descr, data);
}

void PdfDocument::addSale()
{
    QLocale locale;

    QStringList descr = getDescription(9, 12);

    QStringList data{book_.sale().date().toString(),
                     book_.sale().personName(),
                     QString::number(book_.sale().price()) + locale.currencySymbol()
                    };

    create("SALE", descr, data);
}

void PdfDocument::addSource()
{
    QStringList descr = getDescription(12, 14);

    QStringList data{book_.sourceOfOrigin().category(),
                     book_.sourceOfOrigin().description()
                    };

    create("SOURCE OF ORIGIN", descr, data);
}

void PdfDocument::addAttach()
{
    QStringList descr = getDescription(14, 15);
    QStringList data{book_.additives().attachments()};

    create("ADDITIVES", descr, data);
}

void PdfDocument::addDescr()
{
    QStringList descr{"Comments", "Review"};

    QStringList data{book_.description().comments(),
                     book_.description().review()
                    };

    create("DESCRIPTION", descr, data);
}

void PdfDocument::createPrinter()
{
    printer_.setPageMargins(QMargins(30, 10, 30, 10));
    printer_.setPageSize(QPrinter::A4);
    printer_.setOutputFormat(QPrinter::PdfFormat);
    printer_.setOutputFileName(fileName_);
}

void PdfDocument::createTableFormat()
{
    textTableFormat_.setAlignment(Qt::AlignLeft);
    textTableFormat_.setCellPadding(0);
    textTableFormat_.setCellSpacing(0);
    textTableFormat_.setBorder(2);
    textTableFormat_.setBorderBrush(QBrush(Qt::white));
}

void PdfDocument::createCharFormat()
{
    charFormat_.setFont(QFont("Times", 20, QFont::Bold));
}

