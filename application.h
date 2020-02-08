#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

#include "tablebooks.hpp"
#include "dictionaries.hpp"
#include "fileinput.hpp"
#include "booksettings.hpp"

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
    void openBookEdition();

private:
    Ui::Application *ui;

    void initButtons();

    TableBooks* tableBooks;
};
#endif // APPLICATION_H
