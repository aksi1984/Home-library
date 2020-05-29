#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QMainWindow>
#include <QTimer>
#include <QDockWidget>

#include "bookscollection.hpp"
#include "bookeditor.hpp"
#include "dictionaries.hpp"
#include "fileinput.hpp"
#include "filterwidget.hpp"
#include "table.hpp"
#include "tree.hpp"
#include "shortdescription.hpp"
#include "actionsrange.hpp"
#include "settings.hpp"
#include "languages.hpp"
#include "xmlfile.hpp"

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
    void updateSelectedTableRow();
    void updateButtonsEnabled();
    void showText();
    void createTableContextMenu();
    void languageChanged(QAction* action);
    void saveProgram();
    void setAsSaved();
    void setAsUnsaved();
    void save();

private:
    Ui::Application *ui;

    void closeEvent(QCloseEvent* e) override;

    void initTimer();
    void initConnect();

    QTimer timer_;
    FilterWidget* filterWidget_;
    Table* table_;
    Tree* tree_;
    ShortDescription* shortDecription_;
    Languages languages_;

    QActionGroup* actionGroup_;
    QTranslator translator_;

    bool dataHasBeenSaved_;
};
#endif // APPLICATION_HPP
