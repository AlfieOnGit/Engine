//
// Contributors: Alfie
//

#ifndef EVENTPRIORITY_H
#define EVENTPRIORITY_H
#include <cstdint>

enum EventPriority : uint8_t
{
    MONITOR,
    LATE,
    NORMAL,
    EARLY
};

#endif //EVENTPRIORITY_H
