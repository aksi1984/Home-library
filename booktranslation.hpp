#ifndef BOOKTRANSLATION_HPP
#define BOOKTRANSLATION_HPP

#include <QString>

class BookTranslation
{
public:
    BookTranslation();
    BookTranslation(const QString& reqOrigTrans, const QString& reqAuthor);

    void setOriginalLanguage(const QString& text);
    void setAuthor(const QString& text);

    QString originalLanguage() const noexcept;
    QString author() const noexcept;

private:
    QString originalLanguage_;
    QString author_;
};

#endif // BOOKTRANSLATION_HPP
