#pragma once

#include <ctime>
#include <iostream>

class Timer {
    clock_t m_start;
    clock_t m_end;
public:
    Timer() {
        reset();
    }
    inline void reset() {
        m_start = clock();
    }
    inline clock_t check() {
        m_end = clock();
        return m_end - m_start;
    }
    friend std::ostream& operator<<(std::ostream& os, const Timer& timer) {
        os << (timer.m_end - timer.m_start) << "ms";
        return os;
    }
};

