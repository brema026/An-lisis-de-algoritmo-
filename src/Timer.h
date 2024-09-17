#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    void start();
    long long stop();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif
