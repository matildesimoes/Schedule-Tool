/** @file Searcher.h
 *  @brief Contains the Searcher class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_SEARCHER_H
#define AED_FEUP_PROJ_22_23_SEARCHER_H


#include "DataBase.h"

/** @brief The class is used to search students using different criteria.
 *
 */
class Searcher {

    //! @brief A copy of object DataBasePTR.
    DataBasePTR dataBasePtr;

public:

    /** @brief Creates a new Searcher with only dataBasePtr.
     *
     * @param dataBasePtr Of type DataBAsePTR.
     */
    Searcher(DataBasePTR dataBasePtr);

    /** @brief Find UC using uc code.
     *
     * It uses binary search to find the uc.
     *
     * Temporal Complexity: O(log(n)),
     * in which n is the number of elements in the vector of UCs.
     *
     * @param ucCode Of type string.
     * @return UC corresponding to the uc code if it is found, nullptr if not.
     */
    UCPTR findUC(string ucCode);

    /** @brief Find class using class code and uc code.
     *
     * It uses binary search to find the class.
     *
     * Temporal Complexity: O(log(n) + log(m)),
     * in which n is the number of elements in the vector of UCs
     * and m is the number of elements in the corresponding vector of Classes.
     *
     * @param classCode Of type string.
     * @param ucCode Of type string.
     * @return Class corresponding to the class code and uc code if it is found, nullptr if not.
     */
    ClassPTR findClass(string classCode, string ucCode);

    /** @brief Find student using student code and the class.
     *
     * It uses binary search to find the student.
     *
     * Temporal Complexity: O(log(n)),
     * in which n is the number of elements in the vector of Students within the given Class.
     *
     * @param StudentCode Of type string.
     * @param classe Of type ClassPTR.
     * @return Student corresponding to the student code and the class, if it is found, nullptr if not.
     */
    StudentPTR findStudentInClass(string studentCode, ClassPTR classe);

    /** @brief Find Student using student code.
     *
     * It uses binary search to find the student.
     *
     * Temporal Complexity: O(log(n)),
     * in which n is the total number of elements in the set of Students.
     *
     * @param studentCode Of type string.
     * @return Student corresponding to the student code if it is found, nullptr if not.
     */
    StudentPTR findStudent(string studentCode);
};


#endif //AED_FEUP_PROJ_22_23_SEARCHER_H
