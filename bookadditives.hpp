#ifndef BOOKADDITIVES_HPP
#define BOOKADDITIVES_HPP

#include <QString>

class BookAdditives
{
public:
    BookAdditives();
    BookAdditives(const QString& reqAttachments);

    void setAttachments(const QString& text);
    QString attachments() const noexcept;

private:
    QString attachments_;
};

#endif // BOOKADDITIVES_HPP
