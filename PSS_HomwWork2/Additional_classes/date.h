#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date(unsigned short y = 0, unsigned short m = 0, unsigned short d = 0);

    int getAgeDiff(const Date &right) const;

    void setDate(unsigned short y, unsigned short m, unsigned short d);

private:
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

#endif // DATE_H
