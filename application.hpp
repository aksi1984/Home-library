#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QTimer>

#include "tableofbooks.hpp"
#include "bookscollection.hpp"
#include "bookeditor.hpp"
#include "dictionaries.hpp"
#include "fileinput.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

private slots:
    void openDictionaries();
    void makeCopy();
    void openBookEditor();
    void editBook();
    void removeBook();
    void updateButtonsEnabled();

private:
    Ui::Application *ui;

    void initTimer();
    void initConnect();

    QTimer timer_;
    TableOfBooks* tableOfBooks;
};
#endif // APPLICATION_H
