/** @file Pointers.cpp
 *  @brief Contains the Pointers class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Pointers.h"
#include "Student.h"

bool operator<(const StudentPTR first, const StudentPTR second) {
    return (first->getCode() < second->getCode());
}