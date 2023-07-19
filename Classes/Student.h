/** @file Student.h
 *  @brief Contains the Student class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_STUDENT_H
#define AED_FEUP_PROJ_22_23_STUDENT_H

#include <string>
#include <vector>
#include <map>
#include "Pointers.h"

using namespace std;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class UC;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Class;


/** @brief Represents all Students that belong to database.
 *
 *  Each Student has a name, a code, a vector of ucs and a vector of classes.
 */
class Student {

private:

    //! @brief Holds the Student code, that is unique and identifies the student.
    unsigned code;

    //! @brief Holds the name of the student.
    string name;

    //! @brief Holds the vector of ucs that belong to the student.
    vector<UCPTR> ucs;

    //! @brief Holds the uc code that belong to the student.
    vector<ClassPTR> classes;

public:

    /** @brief Create a new Student with only code and name.
     *
     * @param code Of type const unsigned int.
     * @param name Of type const string.
     */
    Student(const unsigned int code, const string name);

    /** @brief The copy constructor.
     *
     * @param student Of type Student const.
     */
    Student(Student const &student);

    /** @brief Returns the code of the student.
     *
     * @return Unsigned code of the student.
     */
    const unsigned getCode();

    /** @brief Sets the code to the given argument.
     *
     * @param code Of type string.
     * @return Void.
     */
    void setCode(string code);

    /** @brief Returns the name of the student.
     *
     * @return String name of the student.
     */
    const string getName();

    /** @brief Sets the name to the given argument.
     *
     * @param name Of type string.
     * @return Void.
     */
    void setName(string name);

    /** @brief Returns a vector of ucs that belongs to the student.
     *
     * @return Vector of ucs Of type UCPTR, by reference.
     */
    vector<UCPTR>& getUCs();

    /** @brief Adds the student to the vector of ucs.
     *
     * @param uc Of type UCPTR.
     * @return Void.
     */
    void addUC(UCPTR uc);

    /** @brief Removes the student to the vector of ucs.
     *
     * It will search the uc iterator, using the argument
     * and then erase the student, if it is possible.
     *
     * @param uc Of type UCPTR.
     * @return True if the remove granted, False if otherwise.
     */
    bool removeUC(UCPTR uc);

    /** @brief Adds the student to the vector of classes.
     *
     * @param classe Of type ClassPTR.
     * @return Void.
     */
    void addClass(ClassPTR classe);

    /** @brief Removes the student from the vector of classes.
     *
     * It will search the class iterator, using the argument
     * and then erase the student, if it is possible.
     *
     * @param classe Of type ClassPTR.
     * @return True if the remove granted, False if otherwise.
     */
    bool removeClass(ClassPTR classe);

    /** @brief Returns a vector of classes that belongs to the student.
     *
     * @return Vector of classes Of type ClassPTR, by reference.
     */
    vector<ClassPTR>& getClasses();
};



#endif //AED_FEUP_PROJ_22_23_STUDENT_H
