#include "functionTime.h"
unsigned int millis_since_midnight()
{
    // current time
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    // get midnight
    time_t tnow = std::chrono::system_clock::to_time_t(now);
    tm *date = std::localtime(&tnow);
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    auto midnight = std::chrono::system_clock::from_time_t(std::mktime(date));

    // number of milliseconds between midnight and now, ie current time in millis
    // The same technique can be used for time since epoch
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - midnight).count();
}