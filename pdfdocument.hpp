#ifndef PDFDOCUMENT_HPP
#define PDFDOCUMENT_HPP

#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>
#include <QTextCursor>
#include <QPdfWriter>
#include <QTextTable>
#include <QLabel>
#include <QScopedPointer>
#include <QCheckBox>
#include <QLocale>

#include "book.hpp"

enum TableCol
{
    Description,
    Data
};

inline QStringList variantToString(const QVariantList& list)
{
    QStringList strList;

    std::generate_n(std::back_inserter(strList), list.size(), [list, i = 0]()mutable{ return list[i++].toString(); });

    return strList;
}

class PdfDocument
{
public:
    PdfDocument(const QString& reqFileName, const Book& reqBook, QList<QLabel*> labels, const QVector<int>& checked);

    void start();

private:
    void createPrinter();
    void createTextCursor();
    void createTableFormat();
    void createCharFormat();

    void sendData(const QString& title, const QVariantList& varList, const QStringList& labels_t);
    void create(const QString &category, const QStringList& labels, const QStringList& data);
    QStringList getDescription(int first, int last);

    QString fileName_;
    Book book_;

    QList<QLabel*> labels_;

    QScopedPointer<QTextTable> textTable_;
    QTextDocument textDocument_;
    QPrinter printer_;
    QTextTableFormat textTableFormat_;
    QTextCharFormat charFormat_;
    QTextCursor textCursor_;

    QVector<int> checked_;

    const int cols_;

    QVector<std::function<void()>> functions_;

};

#endif // PDFDOCUMENT_HPP
