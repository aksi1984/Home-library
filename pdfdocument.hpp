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

    void addGeneral();
    void addRatings();
    void addStorageLocation();
    void addPurchase();
    void addSeries();
    void addTranslation();
    void addLoaned();
    void addLent();
    void addSale();
    void addSource();
    void addAttach();
    void addDescr();

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
