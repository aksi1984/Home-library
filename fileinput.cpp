#include "fileinput.hpp"
#include <QMessageBox>

FileInput::FileInput() { }

void FileInput::load(const QString &fileName)
{
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);

        while(!textStream.atEnd())
        {
            text.push_back(textStream.readLine());
        }
    }
}

QStringList FileInput::get() const noexcept
{
    return text;
}
