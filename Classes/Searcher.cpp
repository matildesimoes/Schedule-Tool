/** @file Searcher.cpp
 *  @brief Contains the Searcher class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Searcher.h"
#include "Sorter.h"

Searcher::Searcher(DataBasePTR dataBasePtr): dataBasePtr(dataBasePtr){}

UCPTR Searcher::findUC(string ucCode){

    auto low = dataBasePtr->getUCs().begin();
    auto high = dataBasePtr->getUCs().end();

    while(low <= high){
        auto mid = low + (high - low) / 2;
        if (mid == dataBasePtr->getUCs().end()) return nullptr;
        if((*mid)->getCode() == ucCode)
            return *mid;
        else if ((*mid)->getCode() > ucCode)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nullptr;
}

ClassPTR Searcher::findClass(string classCode, string ucCode){

    UCPTR uc = findUC(ucCode);
    if (uc == nullptr) return nullptr;
    auto low = uc->getClasses().begin();
    auto high = uc->getClasses().end();

    while(low <= high){
        auto mid = low + (high - low) / 2;
        if (mid == uc->getClasses().end()) return nullptr;
        if((*mid)->getCode() == classCode)
            return *mid;
        else if ((*mid)->getCode() > classCode)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nullptr;
}

StudentPTR Searcher::findStudentInClass(string studentCode, ClassPTR classe) {

    auto low = classe->getStudents().begin();
    auto high = classe->getStudents().end();

    while(low <= high){
        auto mid = low + (high - low) / 2;
        if (mid == classe->getStudents().end()) return nullptr;
        if((*mid)->getCode() == stoi(studentCode))
            return *mid;
        else if ((*mid)->getCode() > stoi(studentCode))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nullptr;

}

StudentPTR Searcher::findStudent(string studentCode) {
    auto StudentIT = dataBasePtr->lowerBound(studentCode);
    return StudentIT != dataBasePtr->getStudents().end() && (*StudentIT)->getCode() == stoi(studentCode)
            ? *StudentIT : nullptr;
}