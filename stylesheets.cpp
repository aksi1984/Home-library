#include "stylesheets.hpp"

QString StyleSheets::styles_;

void StyleSheets::load(QWidget* parent)
{
    FileInput fileInput;
    fileInput.load(R"(D:\Documents\Projects\HomeLibrary\stylesheets\styles.css)", ResourceType::String, parent);
    styles_ = fileInput.getStr();
}

QString StyleSheets::get() noexcept
{
    return styles_;
}
