/** @file Pointers.h
 *  @brief Contains the Pointers class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_POINTERS_H
#define AED_FEUP_PROJ_22_23_POINTERS_H

#include <memory>

using namespace std;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class UC;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Class;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Student;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class DataBase;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Sorter;

//! @brief Short declaration of incomplete type to avoid the "circular dependencies" problem.
class Searcher;

//! @brief Redefinition of shared pointers of UCs for ease of use.
typedef shared_ptr<UC> UCPTR;

//! @brief Redefinition of shared pointers of Classes for ease of use.
typedef shared_ptr<Class> ClassPTR;

//! @brief Redefinition of shared pointers of Students for ease of use.
typedef shared_ptr<Student> StudentPTR;

//! @brief Redefinition of shared pointers of DataBase for ease of use.
typedef shared_ptr<DataBase> DataBasePTR;

//! @brief Redefinition of shared pointers of Sorter for ease of use.
typedef shared_ptr<Sorter> SorterPTR;

//! @brief Redefinition of shared pointers of Searcher for ease of use.
typedef shared_ptr<Searcher> SearcherPTR;

/** @brief Compares students through their PTRs.
 *
 * Created for the sake of implementing an ordered set
 * of studentPTRs.
 * Sorts by student code.
 *
 * @param first Of type const StudentPTR.
 * @param second Of type const StudentPTR.
 * @return True if the code of first is less than the second´s.
 */
bool operator<(const StudentPTR first, const StudentPTR second);

#endif //AED_FEUP_PROJ_22_23_POINTERS_H
