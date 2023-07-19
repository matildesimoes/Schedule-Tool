/** @file Class.h
 *  @brief Contains the Class class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_CLASS_H
#define AED_FEUP_PROJ_22_23_CLASS_H
#include "Student.h"
#include "Lesson.h"
#include <list>

/** @brief Class class to represent each class within the database.
 *
 *  This file contains the Class class
 *  that represents each class from all UCs, read
 *  from the inputs files. And it contains
 *  the prototypes for the functions that handle
 *  its data changes and accesses.
 */
class Class {

private:

    //! @brief Holds the class code, that is unique and identifies the class.
    const string code;

    //! @brief Holds all the students that belongs to the class.
    vector<StudentPTR> students;

    //! @brief Holds all the lessons that belongs to the class.
    vector<Lesson> lessons;
public:

    /** @brief Create a new Class with only code.
    *
    * @param code Of type string.
    */
    Class(string code);

    /** @brief Returns the uC code.
    *
    *  @return string code.
    */
    const string getCode();

    /** @brief Returns the vector of students that belong to the class.
    *
    *  @return vector of students Of type StudentPTR, by reference.
    */
    vector<StudentPTR>& getStudents();

    /** @brief Adds the student to the vector of students.
     *
     * @param student Of type StudentPTR.
     * @return Void.
     */
    void addStudent(const StudentPTR student);

    /** @brief Returns a vector of lessons that belongs to the class.
     *
     * @return vector of lessons Of type Lesson, by reference.
     */
    vector<Lesson>& getLessons();

    /** @brief Adds the lesson to the vector of lessons.
     *
     * @param lesson Of type Lesson.
     * @return Void.
     */
    void addLesson(Lesson lesson);

    /** @brief Removes the student from  the vector of students.
     *
     * It will search the student iterator, using the argument
     * and then erase the student, if it is possible.
     *
     * @param student Of type StudentPTR.
     * @return True if the remove granted, False if otherwise.
     */
    bool removeStudents(StudentPTR student);
};

#endif //AED_FEUP_PROJ_22_23_CLASS_H
