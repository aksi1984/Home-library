#include "fileinput.hpp"
#include <QMessageBox>

FileInput::FileInput() { }

void FileInput::load(const QString &fileName, ResourceType type, QWidget *parent)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(parent,
                             "Warning",
                             "Unable to load file " + fileName +
                             ". Invalid file type of file does not exist",
                             QMessageBox::Ok
                             );

        return;
    }
    else
    {
        QTextStream textStream(&file);

        while(!textStream.atEnd())
        {
            switch(type)
            {
                case ResourceType::String:
                {
                    str_ += textStream.readLine() + "\n";
                }
                break;

                case ResourceType::StringList:
                {
                    strList_.push_back(textStream.readLine());
                }
                break;
            }
        }
    }
}

QStringList FileInput::getList() const noexcept
{
    return strList_;
}

QString FileInput::getStr() const noexcept
{
    return str_;
}
