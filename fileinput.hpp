#ifndef FILEINPUT_HPP
#define FILEINPUT_HPP

#include <QFile>
#include <QTextStream>

enum ResourceType
{
    String,
    StringList
};

class FileInput
{
public:
    FileInput();

    void load(const QString& fileName, ResourceType type, QWidget* parent);
    void loadStr(const QString& fileName);
    void save(const QString& fileName, const QStringList& data);
    QStringList getList() const noexcept;
    QString getStr() const noexcept;

private:
    QStringList strList_;
    QString str_;
};

#endif // FILEINPUT_HPP
