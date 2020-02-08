#include "general.hpp"

General::General() { }

void General::setTitle(const QString& text)
{
    title_ = text;
}

void General::setSubTitle(const QString& text)
{
    subTitle_ = text;
}

void General::setOriginalTitle(const QString &text)
{
    originalTitle_ = text;
}

void General::setAuthor(const QString &text)
{
    author_ = text;
}

void General::setEditorialOffice(const QString &text)
{
    editorialOffice_ = text;
}

void General::setCategory(const QString &text)
{
    category_ = text;
}

void General::setSubCategory(const QString &text)
{
    subCategory_ = text;
}

void General::setPublisher(const QString &text)
{
    publisher_ = text;
}

void General::setPlaceOfPublication(const QString &text)
{
    placeOfPublication_ = text;
}

void General::setPrintingHouse(const QString &text)
{
    printingHouse_ = text;
}

void General::setLanguage(const QString &text)
{
    language_ = text;
}

void General::setBinding(const QString &text)
{
    binding_ = text;
}

void General::setISBN(const QString &text)
{
    ISBN_ = text;
}

void General::setID(const QString &text)
{
    ID_ = text;
}

void General::setEdition(int value)
{
    edition_ = value;
}

void General::setTome(int value)
{
    tome_ = value;
}

void General::setPublicationDate(int value)
{
    publicationDate_ = value;
}

void General::setNumberOfPages(int value)
{
    numberOfPages_ = value;
}

void General::setAvailable(bool cond)
{
    available_ = cond;
}

QString General::title() const noexcept
{
    return title_;
}

QString General::subTitle() const noexcept
{
    return subTitle_;
}

QString General::originalTitle() const noexcept
{
    return  originalTitle_;
}

QString General::author() const noexcept
{
    return author_;
}

QString General::editorialOffice() const noexcept
{
    return editorialOffice_;
}

QString General::category() const noexcept
{
    return category_;
}

QString General::subCategory() const noexcept
{
    return subCategory_;
}

QString General::publisher() const noexcept
{
    return publisher_;
}

QString General::placeOfPublication() const noexcept
{
    return placeOfPublication_;
}

QString General::printingHouse() const noexcept
{
    return language_;
}

QString General::language() const noexcept
{
    return language_;
}

QString General::binding() const noexcept
{
    return binding_;
}

QString General::ISBN() const noexcept
{
    return ISBN_;
}

QString General::ID() const noexcept
{
    return ID_;
}

int General::edition() const noexcept
{
    return edition_;
}

int General::tome() const noexcept
{
    return tome_;
}

int General::publicationDate() const noexcept
{
    return publicationDate_;
}

int General::numberOfPages() const noexcept
{
    return numberOfPages_;
}

bool General::available() const noexcept
{
    return available_;
}
