//
// Created by Alfie on 24/12/2024.
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
