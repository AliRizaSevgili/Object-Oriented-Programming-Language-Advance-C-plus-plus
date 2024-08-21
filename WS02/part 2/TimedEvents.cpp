// Workshop 2 
// TimedEvents.cpp
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace seneca
{
    void TimedEvents::startClock() {
        t_startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        t_endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char* src) {
        if (t_CurRecord < MAX_NUMBER) {
            if (src != nullptr || src[0] != '\0') {
                t_event[t_CurRecord].e_name = src;
                t_event[t_CurRecord].e_UnitTime = "nanoseconds";

                
                t_event[t_CurRecord].e_durationEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(t_endTime - t_startTime);

                ++t_CurRecord;
            }
            else {
                t_event[t_CurRecord].e_name = "";
                t_event[t_CurRecord].e_UnitTime = "";
            }
        }
    }

    ostream& operator<<(ostream& os, const TimedEvents& src) {
        os << "--------------------------" << endl;
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;

        for (auto i = 0u; i < src.t_CurRecord; ++i) {
            os << setw(21) << left << src.t_event[i].e_name;
            os << setw(13) << right << src.t_event[i].e_durationEvent.count();
            os << " " << src.t_event[i].e_UnitTime << endl;
        }

        os << "--------------------------" << endl;

        return os;
    }
}