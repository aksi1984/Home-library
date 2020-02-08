#ifndef FILEINPUT_HPP
#define FILEINPUT_HPP

#include <QFile>
#include <QTextStream>

class FileInput
{
public:
    FileInput();

    void load(const QString& fileName);
    QStringList get() const noexcept;

private:
    QStringList text;
};

#endif // FILEINPUT_HPP
