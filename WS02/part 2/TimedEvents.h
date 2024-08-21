// Workshop 2 
// TimedEvents.h
// Ali Riza Sevgili
// 135200228
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <chrono>
#include <string>

namespace seneca
{
    class TimedEvents
    {

        enum { MAX_NUMBER = 10 };
        size_t t_CurRecord{ 0u };

        std::chrono::steady_clock::time_point t_startTime;
        std::chrono::steady_clock::time_point t_endTime;

        struct Event {
            std::string e_name;
            std::string e_UnitTime;
            std::chrono::steady_clock::duration e_durationEvent;
            Event() : e_name(""), e_UnitTime("") {}
        } t_event[MAX_NUMBER];

    public:
        TimedEvents() {}

        void startClock();
        void stopClock();
        void addEvent(const char* src);

        friend std::ostream& operator<<(std::ostream& os, const TimedEvents& src);
    };
}
#endif // SENECA_TIMEDEVENTS_H