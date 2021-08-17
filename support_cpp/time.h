#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer{
private:
    std::chrono::high_resolution_clock::time_point last_time;
public:
    Timer();
    void start();
    int64_t getRunningTime();
};

Timer::Timer(){
    last_time = std::chrono::high_resolution_clock::now();
}

void Timer::start(){
    last_time = std::chrono::high_resolution_clock::now();
}

int64_t Timer::getRunningTime(){
    auto curTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(curTime - last_time);
    return duration.count();
}

#endif
