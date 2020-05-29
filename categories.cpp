#include "categories.hpp"

QStringList Categories::names;

Categories::Categories() { }

void Categories::load(QWidget* parent)
{
    FileInput fileInput;
    fileInput.load(R"(D:\Documents\Projects\HomeLibrary\txt\categories.txt)", ResourceType::StringList, parent);
    names = fileInput.getList();
}

void Categories::save()
{
    FileInput fileInput;
    fileInput.save(R"(D:\Documents\Projects\HomeLibrary\txt\categories.txt)", names);
}

QStringList Categories::get() noexcept
{
    return names;
}

void Categories::insert(int index, const QString& text)
{
    names.insert(index, text);
}

void Categories::remove(const QString& text)
{
    names.erase( std::remove_if(names.begin(), names.end(), [text](QString str){ return str == text; }), names.end() );
}

