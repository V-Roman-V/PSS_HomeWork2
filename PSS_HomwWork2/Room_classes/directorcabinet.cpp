#include "directorcabinet.h"

DirectorCabinet::DirectorCabinet()
{

}

AccessLevel DirectorCabinet::neededAccessLevel()
{
    return AccessLevel::black;
}
