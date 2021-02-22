#ifndef PASSPORT_H
#define PASSPORT_H


class Passport
{
public:
    Passport(unsigned int _number = 0, unsigned int _series = 0);
    void setPassport(unsigned int _number, unsigned int _series);

    unsigned int getNumber() const;
    unsigned int getSeries() const;

private:
    bool isCorrect();
    unsigned int number;
    unsigned int series;
};

#endif // PASSPORT_H
