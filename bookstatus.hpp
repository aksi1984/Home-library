#ifndef BOOKSTATUS_HPP
#define BOOKSTATUS_HPP


class BookStatus
{
public:
    BookStatus();
    BookStatus(bool reqDamaged, bool reqGift, bool reqUsed);

    void setBookDamaged(bool isDamaged);
    void setBookGift(bool isGift);
    void setBookUsed(bool isUsed);

    bool isBookDamaged() const noexcept;
    bool isBookGift() const noexcept;
    bool isBookUsed() const noexcept;

private:
    bool isBookDamaged_;
    bool isBookGift_;
    bool isBookUsed_;
};

#endif // BOOKSTATUS_HPP
