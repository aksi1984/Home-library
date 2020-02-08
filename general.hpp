#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <QString>

class General
{
public:
    General();

    void setTitle(const QString &text);
    void setSubTitle(const QString& text);
    void setOriginalTitle(const QString& text);
    void setAuthor(const QString& text);
    void setEditorialOffice(const QString& text);
    void setCategory(const QString& text);
    void setSubCategory(const QString& text);
    void setPublisher(const QString& text);
    void setPlaceOfPublication(const QString& text);
    void setPrintingHouse(const QString& text);
    void setLanguage(const QString& text);
    void setBinding(const QString& text);
    void setISBN(const QString& text);
    void setID(const QString& text);
    void setEdition(int value);
    void setTome(int value);
    void setPublicationDate(int value);
    void setNumberOfPages(int value);
    void setAvailable(bool cond);

    QString title() const noexcept;
    QString subTitle() const noexcept;
    QString originalTitle() const noexcept;
    QString author() const noexcept;
    QString editorialOffice() const noexcept;
    QString category() const noexcept;
    QString subCategory() const noexcept;
    QString publisher() const noexcept;
    QString placeOfPublication() const noexcept;
    QString printingHouse() const noexcept;
    QString language() const noexcept;
    QString binding() const noexcept;
    QString ISBN() const noexcept;
    QString ID() const noexcept;

    int edition() const noexcept;
    int tome() const noexcept;
    int publicationDate() const noexcept;
    int numberOfPages() const noexcept;

    bool available() const noexcept;

private:
    QString title_;
    QString subTitle_;
    QString originalTitle_;
    QString author_;
    QString editorialOffice_;
    QString category_;
    QString subCategory_;
    QString publisher_;
    QString placeOfPublication_;
    QString printingHouse_;
    QString language_;
    QString binding_;
    QString ISBN_;
    QString ID_;

    int edition_;
    int tome_;
    int publicationDate_;
    int numberOfPages_;

    bool available_;
};

#endif // GENERAL_HPP
