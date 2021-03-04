#ifndef DIRECTORCABINET_H
#define DIRECTORCABINET_H

#include "cabinet.h"

class DirectorCabinet : public Cabinet
{
public:
    DirectorCabinet();

private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // DIRECTORCABINET_H
