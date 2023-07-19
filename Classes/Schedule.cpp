/** @file Schedule.cpp
 *  @brief Contains the Schedule class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Schedule.h"
#include "Class.h"
#include "UC.h"
#include "Sorter.h"
#include <iostream>
#include <iomanip>

using namespace std;

Schedule::Schedule(const StudentPTR &student) : student(student),
                                             weekDays({"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}) {};


void Schedule::showLessonsByDay(string day) {
    vector<Lesson> lessonsByDay;
    string lastDay = "empty";
    int flag = 0;
    auto classeIT = student->getClasses().begin();
    auto ucIT = student->getUCs().begin();

    while (classeIT != student->getClasses().end()) {
        ClassPTR classe = *classeIT;
        UCPTR uc = *ucIT;
        if (day != lastDay) {
            cout << "On " << day << ":" << endl;
            lastDay = day;
            flag = 0;
        }
        Sorter tempSorter;
        for (Lesson lesson: classe->getLessons()) {
            if (lesson.getDay() == day) {
                flag = 1;
                cout << uc->getCode()+','+classe->getCode() << " | " << lesson << endl;
            }
        }
        classeIT++; ucIT++;
    }
    if (flag == 0) cout << "xxxxx No lessons found xxxxx" << endl;
    cout << "-------------------------------------" << endl;
}

void Schedule::showSchedule() {
    if (student == nullptr){
        cout << "Student code provided is invalid or intended student is not within the database";
        return;
    }
    cout << "================== Student " << student->getCode() << " Schedule =================" << endl;
    for (string day: weekDays)
        showLessonsByDay(day);
}
