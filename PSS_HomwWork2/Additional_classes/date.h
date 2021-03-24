#ifndef DATE_H
#define DATE_H


class Date
{
public:
    static Date current_date;

    Date(unsigned short d = 0, unsigned short m = 0, unsigned short y = 0);

    unsigned short getAgeDiff(const Date &right) const;

    void setDate(unsigned short y, unsigned short m, unsigned short d);

    bool isCorrect() const;

    static Date getNowDate();
private:
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

#endif // DATE_H
