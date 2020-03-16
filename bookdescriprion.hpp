#ifndef BOOKDESCRIPRION_HPP
#define BOOKDESCRIPRION_HPP

#include <QString>

class BookDescriprion
{
public:
    BookDescriprion();
    BookDescriprion(const QString& reqComments, const QString& reqReview);

    void setComments(const QString& text);
    void setReview(const QString& text);

    QString comments() const noexcept;
    QString review() const noexcept;

private:
    QString comments_;
    QString review_;
};

#endif // BOOKDESCRIPRION_HPP
