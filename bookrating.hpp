#ifndef BOOKRATING_HPP
#define BOOKRATING_HPP


class BookRating
{
public:
    BookRating();

    void setPoints(unsigned value);
    void setRead(bool cond);
    void setRecommended(bool cond);

    int points() const noexcept;
    bool isRead() const noexcept;
    bool isRecommended() const noexcept;

public:
    int points_;
    bool isRead_;
    bool isRecommended_;
};

#endif // BOOKRATING_HPP
