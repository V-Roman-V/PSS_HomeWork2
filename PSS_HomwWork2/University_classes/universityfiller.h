#ifndef UNIVERSITYFILLER_H
#define UNIVERSITYFILLER_H

#include <queue>
#include <vector>
#include "University_classes/university.h"
#include "Additional_classes/peoplegenerator.h"

template<class T>
struct myQueue : public std::queue<T>{
    T pickLast(){T item = this->front(); this->pop();return item;}
};

struct UniversityFiller
{
    static void fillStartingData(University& university);
};

#endif // UNIVERSITYFILLER_H
