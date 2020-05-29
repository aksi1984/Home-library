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

                [this]{ sendData("General", book_.basic().data(), getDescription(15, 30)); },
                [this]{ sendData("Ratings", book_.ratings().data(), {"Points", "Read", "I recommended"}); },
                [this]{ sendData("Storage location", book_.storageLocation().data(), getDescription(32, 36)); },
                [this]{ sendData("Purchase", book_.purchase().data(), getDescription(36, 40)); },
                [this]{ sendData("Series", book_.series().data(), getDescription(0, 3)); },
                [this]{ sendData("Translation", book_.translation().data(), getDescription(3, 5)); },
                [this]{ sendData("Loaned", book_.loaned().data(), getDescription(5, 7)); },
                [this]{ sendData("Lent", book_.lent().data(), getDescription(7, 9)); },
                [this]{ sendData("Sale", book_.sale().data(), getDescription(9, 12)); },
                [this]{ sendData("Source", book_.source().data(), getDescription(12, 15)); },
                [this]{ sendData("Description", book_.description().data(), {"Comments", "Review"}); }

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

void PdfDocument::sendData(const QString &title, const QVariantList &varList, const QStringList &labels_t)
{
    auto data = variantToString(varList);
    create(title, labels_t, data);
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

