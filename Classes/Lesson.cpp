/** @file Lesson.cpp
 *  @brief Contains the Lesson class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <cmath>
#include <iomanip>
#include "Lesson.h"
#include "ostream"

Lesson::Lesson(const string day, const double startHour, const double duration, const string type) :
        day(day), startHour(startHour), duration(duration), type(type) {}

const double Lesson::getStartHour() {
    return startHour;
};

const double Lesson::getDuration() {
    return duration;
};

const string Lesson::getDay() {
    return day;
}

const string Lesson::getType() {
    return type;
}

ostream& operator<<(ostream& os, Lesson lesson){
    os << std::left;
    os << std::setw(2) << lesson.type << " | ";
    os << std::right;
    os << std::setfill('0') << setw(2);
    os << to_string((int)floor(lesson.startHour)) << "h";
    os << std::setfill('0') << setw(2);
    os << to_string((int)(60 * (lesson.startHour - floor(lesson.startHour)))) << 'm';
    os << '-';
    float endHour = lesson.startHour+lesson.duration;
    os << std::setfill('0') << setw(2);
    os << to_string((int)floor(endHour)) << "h";
    os << std::setfill('0') << setw(2);
    os << to_string((int)(60 * (endHour - floor(endHour)))) << 'm';
    os << std::setfill(' ');
    return os;
}






