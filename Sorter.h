/** @file Sorter.h
 *  @brief Contains the Sorter class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_SORTER_CPP
#define AED_FEUP_PROJ_22_23_SORTER_CPP

#include <vector>
#include "Pointers.h"
#include "UC.h"
#include "QuickSort.h"

//! @brief Creates different criteria to order the students.
enum StudentOrderCriteria{STUDENT_CODE, STUDENT_NAME};

//! @brief Creates different criteria to order the ucs.
enum UCOrderCriteria{UC_CODE, UC_OCCUPATION};

//! @brief Creates different criteria to order the classes.
enum ClassOrderCriteria{CLASS_CODE, CLASS_OCCUPATION};

using namespace std;

/** @brief Class to sort different elements.
 *
 * By default, sorts everything by code and in ascending order.
 *
 */
class Sorter {

    //! @brief It is true if the sort is meant to use the ascending order, False if otherwise.
    static bool ascendingOrder;

    //! @brief Holds the criteria specified to order the students.
    static StudentOrderCriteria studentCriteria;

    //! @brief Holds the criteria specified to order the ucs.
    static UCOrderCriteria ucCriteria;

    //! @brief Holds the criteria specified to order the classes.
    static ClassOrderCriteria classCriteria;

public:

    //! @brief Does nothing.
    Sorter();
    
    /** @brief Compares UCPTR in order to sort.
     *
     * It has two criteria, UC_CODE and UC_OCCUPATION.
     *
     * Temporal Complexity: O(1).
     *
     * @param comp1 Of type UCPTR.
     * @param comp2 Of type UCPTR.
     * @return True if they are already ordered by the selected criteria, False if otherwise.
     */
    friend bool compare(UCPTR comp1, UCPTR comp2);

    /** @brief Compares ClassPTR in order to sort.
     *
     * It has two criteria, CLASS_CODE and CLASS_OCCUPATION.
     *
     * Temporal Complexity: O(1).
     *
     * @param comp1 Of type ClassPTR.
     * @param comp2 Of type ClassPTR.
     * @return True if they are already ordered by the selected criteria, False if otherwise.
     */
    friend bool compare(ClassPTR comp1, ClassPTR comp2);

    /** @brief Compares StudentPTR in order to sort.
     *
     * It has two criteria, STUDENT_CODE and STUDENT_NAME.
     *
     * Temporal Complexity: O(1).
     *
     * @param comp1 Of type StudentPTR.
     * @param comp2 Of type StudentPTR.
     * @return True if they are already ordered by the selected criteria, False if otherwise.
     */
    friend bool compare(StudentPTR comp1, StudentPTR comp2);

    /** @brief Sort the students invoking the quickSort.
     *
     * Temporal Complexity: O(n log(n)),
     * in which n is the number of elements in the given vector.
     *
     * @tparam PTR Intended to be either a UCPTR, ClassPTR or StudentPTR.
     * @param v Of type vector<PTR>, by reference.
     * @return Void.
     */
    template <class PTR>
    void sort(vector<PTR> &v){
        if(v.size() == 0) return;
        quickSort(v, 0, v.size() - 1);
    }

    /** @brief Makes ascendingOrder false.
     *
     * @return Void.
     */
    static void setDescendingOrder();

    /** @brief Makes ascendingOrder true.
     *
     * @return Void.
     */
    static void setAscendingOrder();

    /** @brief Sets the studentCriteria to the given argument.
     *
     * @param studentCriteria Of type StudentOrderCriteria.
     * @return Void.
     */
    static void setStudentCriteria(StudentOrderCriteria studentCriteria);

    /** @brief Sets the ucCriteria to the given argument.
     *
     * @param ucCriteria Of type UCOrderCriteria.
     * @return Void.
     */
    static void setUcCriteria(UCOrderCriteria ucCriteria);

    /** @brief  Sets the classCriteria to the given argument.
     *
     * @param classCriteria Of type ClassOrderCriteria.
     * @return Void.
     */
    static void setClassCriteria(ClassOrderCriteria classCriteria);

    /** @brief Gets the current ascendingOrder boolean value.
     *
     * @return True if sorter is set to ascending order, false if otherwise.
     */
    bool getAscendingOrder();

    /** @brief Gets the current studentCriteria value.
     *
     * @return studentCriteria of type StudentOrderCriteria.
     */
    static StudentOrderCriteria getStudentCriteria();

    /** @brief Gets the current ucCriteria value.
     *
     * @return ucCriteria of type UCOrderCriteria.
     */
    static UCOrderCriteria getUCCriteria();

    /** @brief Gets the current classCriteria value.
     *
     * @return classCriteria of type StudentClassCriteria.
     */
    static ClassOrderCriteria getClassCriteria();

};

#endif //AED_FEUP_PROJ_22_23_SORTER_CPP
