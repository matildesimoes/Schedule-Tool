/** @file Lesson.h
 *  @brief Contains the Lesson class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_LESSON_H
#define AED_FEUP_PROJ_22_23_LESSON_H

#include <string>
#include <vector>

using namespace std;

/** @brief Represents all lessons that belong to the database.
 *
 *  Each lesson has a day, a start hour, a duration and a type.
 *
 */
class Lesson {

private:

    //! @brief Holds the day of the lesson.
    const string day;

    //! @brief Holds the start hour of the lesson.
    const double startHour;

    //! @brief Holds the duration of the lesson.
    const double duration;

    //! @brief Holds the type of the lesson.
    const string type;
public:

    /** @brief Create a new Lesson.
     *
     * @param day Of type const string.
     * @param startHour Of type const double.
     * @param duration Of type const double.
     * @param type Of type const string.
     */
    Lesson(const string day, const double startHour, const double duration, const string type);

    /** @brief Returns the start hour of the class.
     *
     *  @return Double start hour.
     */
    const double getStartHour();

    /** @brief Returns the duration of the class.
     *
     *  @return Double duration.
     */
    const double getDuration();

    /** @brief Returns the day of the class.
    *
    *  @return String day.
    */
    const string getDay();

    /** @brief Returns the type of the class.
    *
    *  @return String type.
    */
    const string getType();

    /** @brief Provides the system a way to output lessons to ostream.
    *
    *  @return os, of ostream type.
    */
    friend ostream& operator<<(ostream& os, Lesson lesson);
};


#endif //AED_FEUP_PROJ_22_23_LESSON_H
