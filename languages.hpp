#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <QApplication>
#include <QDir>
#include <QLocale>
#include <QTranslator>
#include <QStringList>
#include <QList>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

class Languages
{
    //Q_OBJECT

public:
    Languages();

    void addMenu(QMenu* menu);
    void createActions();
    void addActionGroup(QActionGroup* actionGroup);
    void changeLanguage(QAction* action);
    QString currentLanguage() const noexcept;

private:

    QString path_;
    QString currentPath_;
    QStringList fileNames_;
    QString currentLanguage_;

    QTranslator translator_;
    QMenu* menu_;
};

#endif // LANGUAGES_HPP
