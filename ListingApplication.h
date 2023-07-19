/** @file ListingApplication.h
 *  @brief Contains the ListingApplication class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_LISTINGAPPLICATION_H
#define AED_FEUP_PROJ_22_23_LISTINGAPPLICATION_H

#include "DataBase.h"
#include "Menu.h"
#include "Class.h"
#include "Searcher.h"

/** @brief ListingApplication class to deal with all the listing and the occupation of UC, Classes, Year...
 *
 *  Intended to be instanced once.
 *  It is used to list students by input criteria and to know the number
 *  of students that belong to a certain UC, or class, or year...
 */
class ListingApplication {

private:

    //! @brief A shared pointer referring to the Sorter object of the Application.
    SorterPTR sorterPtr;

    //! @brief A shared pointer referring to the Database object of the Application.
    DataBasePTR dataBasePtr;

    //! @brief A shared pointer referring to the Searcher object of the Application..
    SearcherPTR searcherPtr;

public:

    /** Create a new ListingApplication with a databasePtr, a searcher, and a sorterPtr.
     *
     * @param dataBasePtr Of Type DataBasePTR.
     * @param searcher Of Type Searcher.
     * @param sorterPtr Of Type SorterPTR.
     */
    ListingApplication(DataBasePTR dataBasePtr, SorterPTR sorterPtr, SearcherPTR searcherPtr);

    /** @brief Occupation of students per class.
     *
     * Temporal Complexity: O(log(n) + log(m)),
     * in which n is the number of elements in the vector of UCs
     * and m is the number of elements in the corresponding vector of Classes.
     *
     * @param classe Of type ClassPTR.
     * @param ucCode Of type string.
     * @return Void.
     */
    void showOccupationByClass(string classCode, string ucCode);

    /** @brief Occupation of students per year.
     *
     * Temporal Complexity: O(log(n),
     * in which n is the number of elements in the set of Students.
     *
     * @param year Of type char.
     * @return Void.
     */
    void showOccupationByYear(char year);

    /** @brief Occupation of students per UC.
     *
     * Temporal Complexity: O(log(n),
     * in which n is the number of elements in the vector of UCs.
     *
     * @param ucCode Of type UCPTR.
     * @return Void.
     */
    void showOccupationByUC(string ucCode);

    /** @brief Lists students that belongs to a certain class.
     *
     * Temporal Complexity: O(log(n) + log(m) + p),
     * in which n is the number of elements in the vector of UCs
     * m is the number of elements in the corresponding vector of Classes
     * and p is the number of students within the class.
     *
     * @param classCode Of type string.
     * @param ucCode Of type string.
     * @return Void.
     */
    void listStudentsByClass(string classCode, string ucCode);

    /** @brief Lists students that belongs to a certain uc.
     *
     * Temporal Complexity: O(log(n) + mp),
     * in which n is the number of elements in the vector of UCs
     * m is the number of elements in the corresponding vector of Classes
     * and p is the number of students within each class.
     *
     * @param ucCode Of type string.
     * @return Void.
     */
    void listStudentsByUC(string ucCode);

    /** @brief Lists students that belongs to a certain year.
     *
     * Temporal Complexity: O(log(n)),
     * in which n  is the total number of elements within the set of Students.
     *
     * @param year Of type char.
     * @return Void.
     */
    void listStudentsByYear(char year);

    /** @brief Lists all UCs.
     *
     * Temporal Complexity: O(log(n)),
     * in which n  is the number of total elements within the vector of UCs.
     *
     * @return Void.
     */
    void listUCs();

    /** @brief Lists all classes by UC.
     *
     * Temporal Complexity: O(log(n) + m),
     * in which n is the number of elements in the vector of UCs
     * and m is the number of elements in the corresponding vector of Classes.
     *
     * @param ucCode Of type string.
     * @return Void.
     */
    void listClassesByUC(string ucCode);

    /** @brief Lists all students.
     *
     * Temporal Complexity: O(log(n)),
     * in which n is the number of elements in the set of Students.
     *
     * @return Void.
     */
    void listAllStudents();
};


#endif //AED_FEUP_PROJ_22_23_LISTINGAPPLICATION_H
