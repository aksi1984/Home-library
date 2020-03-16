#include "iconencoding.hpp"

QStringList IconEncoding::texts_
{
    "\uf15b",
    "\uf07b",
    "\uf0c7",
    "\uf0c7",
    "\uf52a",
    "\uf0fe",
    "\uf0fe",
    "\uf24d",
    "\uf044",
    "\uf146"
};

QString IconEncoding::file_ = R"(D:\Documents\Projects\HomeLibrary\icons\Font Awesome 5 Free-Solid-900.otf)";

void IconEncoding::setActionsTexts(QToolBar *toolBar, QWidget *parent)
{
    if(QFontDatabase::addApplicationFont(file_) < 0)
    {
        QMessageBox::warning(parent,
                             "Warning",
                             "Unable to load file " + file_ +
                             ". Invalid file type of file does not exist",
                             QMessageBox::Ok);

        return;
    }

    QFont font;
    font.setFamily("Font Awesome 5 Free-Solid-900");
    font.setPixelSize(19);

    for(int i = 0; i < texts_.size(); ++i)
    {
        toolBar->actions()[i]->setFont(font);
        toolBar->actions()[i]->setText(texts_[i]);
    }
}
