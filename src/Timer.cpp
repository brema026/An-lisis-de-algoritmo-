#include "Timer.h"

Timer::Timer() {}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

long long Timer::stop() {
    auto endTime = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}
