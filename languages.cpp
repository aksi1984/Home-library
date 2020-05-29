#include "languages.hpp"
#include <QMessageBox>
Languages::Languages() :
    path_(R"(D:\Documents\Projects\HomeLibrary\languages)") { }

void Languages::addMenu(QMenu *menu)
{
    menu_ = menu;
}

void Languages::createActions()
{
    QDir dir(path_);
    fileNames_ = dir.entryList(QStringList{"lang*.qm"});

    for(int i = 0; i < fileNames_.size(); ++i)
    {
        QString suffix;
        std::copy(fileNames_[i].begin() + (fileNames_[i].lastIndexOf('_') + 1), fileNames_[i].begin() + fileNames_[i].lastIndexOf('.'),
                  std::back_inserter(suffix));

        QLocale locale(suffix);

        menu_->actions()[i]->setData(suffix);
        menu_->actions()[i]->setCheckable(true);
    }
}

void Languages::addActionGroup(QActionGroup *actionGroup)
{
    actionGroup->setExclusive(true);

    for(auto x : menu_->actions())
    {
        actionGroup->addAction(x);
    }
}

void Languages::changeLanguage(QAction *action)
{
    QString name = action->data().toString();

    QMessageBox mb;
    mb.setText(name);
    mb.exec();

    QLocale locale(name);
    QLocale::setDefault(locale);

    QString native = locale.name();

    QString helper;
    std::copy(native.begin(), native.begin() + native.indexOf('_'), std::back_inserter(helper));

    QString result;

    for(int i = 0; i < fileNames_.size(); ++i)
    {
        QString test;
        std::copy(fileNames_[i].begin() + fileNames_[i].indexOf('_') + 1, fileNames_[i].begin() + fileNames_[i].indexOf('.'), std::back_inserter(test));

        if(test == helper)
        {
            currentLanguage_ = fileNames_[i];
            break;
        }
    }
}

QString Languages::currentLanguage() const noexcept
{
    return path_ + R"(\)" + currentLanguage_;
}
