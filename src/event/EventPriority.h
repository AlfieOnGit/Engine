//
// Created by Alfie on 24/12/2024.
//

#ifndef EVENTPRIORITY_H
#define EVENTPRIORITY_H
#include <cstdint>

enum EventPriority : uint8_t
{
    MONITOR, // Events should NOT be cancelled or edited when listened to using this priority
    LATE,
    DEFAULT,
    EARLY
};

#endif //EVENTPRIORITY_H
