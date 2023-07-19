/** @file Schedule.h
 *  @brief Contains the Schedule class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_SCHEDULE_H
#define AED_FEUP_PROJ_22_23_SCHEDULE_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Lesson.h"

/** @brief Holds the student schedule.
 *
 *  Store student information relevant to their schedule.
 *  Provides methods to display the schedule.
 */
class Schedule {

private:

    //! @brief Holds the student.
    StudentPTR student;

    //! @brief Holds the week days, monday to friday.
    vector<string> weekDays;

    //! @brief Holds all lessons that belongs to the student.
    vector<Lesson> lessons;

public:

    /** @brief Creates a new schedule.
     *
     * @param student Of type const StudentPTR.
     */
    Schedule(const StudentPTR &student);

    /** @brief Shows lessons by day of the week.
     *
     * @param day Of type string.
     * @return Void.
     */
    void showLessonsByDay(string day);

    /** @brief Shows student schedule.
     *
     * It will invoke showLessonsByDay per day of the week.
     *
     * @return Void.
     */
    void showSchedule();

};


#endif //AED_FEUP_PROJ_22_23_SCHEDULE_H
