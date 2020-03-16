#ifndef BOOKRATING_HPP
#define BOOKRATING_HPP


class BookRating
{
public:
    BookRating();
    BookRating(int reqPoints, bool reqIsRead, bool reqIRecomm);

    void setPoints(int value);
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
