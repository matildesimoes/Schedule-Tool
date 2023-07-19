/** @file Sorter.cpp
 *  @brief Contains the Sorter class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Sorter.h"
#include "UC.h"
#include "Pointers.h"

StudentOrderCriteria Sorter::studentCriteria = STUDENT_CODE;
UCOrderCriteria Sorter::ucCriteria = UC_CODE;
ClassOrderCriteria Sorter::classCriteria = CLASS_CODE;

Sorter::Sorter(){}

bool compare(UCPTR uc1, UCPTR uc2){

    switch(Sorter::ucCriteria){
        case UC_CODE:
            if (Sorter::ascendingOrder)
                return uc1->getCode() < uc2->getCode();
            else
                return uc1->getCode() > uc2->getCode();
        case UC_OCCUPATION:
            if (Sorter::ascendingOrder)
                return uc1->getOccupation() < uc2->getOccupation();
            else
                return uc1->getOccupation() > uc2->getOccupation();
    }
    return false; //never executed, just to avoid compilation warnings
}

bool compare(ClassPTR class1, ClassPTR class2){
    switch(Sorter::classCriteria){
        case CLASS_CODE:
            if (Sorter::ascendingOrder)
                return class1->getCode() < class2->getCode();
            else
                return class1->getCode() > class2->getCode();
        case CLASS_OCCUPATION:
            if (Sorter::ascendingOrder)
                return class1->getStudents().size() < class2->getStudents().size();
            else
                return class1->getStudents().size() > class2->getStudents().size();
    }
    return false; //never executed, just to avoid compilation warnings
}

bool compare(StudentPTR student1, StudentPTR student2){
    switch(Sorter::studentCriteria){
        case STUDENT_CODE:
            if (Sorter::ascendingOrder)
                return student1->getCode() < student2->getCode();
            else
                return student1->getCode() > student2->getCode();
        case UC_OCCUPATION:
            if (Sorter::ascendingOrder)
                return student1->getName() < student2->getName();
            else
                return student1->getName() > student2->getName();
    }
    return false; //never executed, just to avoid compilation warnings
}

bool Sorter::ascendingOrder = true;


void Sorter::setDescendingOrder(){
    ascendingOrder= false;
}

void Sorter::setAscendingOrder(){
    ascendingOrder = true;
}

void Sorter::setStudentCriteria(StudentOrderCriteria studentCriteria){
    Sorter::studentCriteria = studentCriteria;
}

void Sorter::setUcCriteria(UCOrderCriteria ucCriteria){
    Sorter::ucCriteria = ucCriteria;
}

void Sorter::setClassCriteria(ClassOrderCriteria classCriteria){
    Sorter::classCriteria = classCriteria;
}

bool Sorter::getAscendingOrder(){
    return ascendingOrder;
}

StudentOrderCriteria Sorter::getStudentCriteria(){
    return studentCriteria;
}

UCOrderCriteria Sorter::getUCCriteria(){
    return ucCriteria;
}

ClassOrderCriteria Sorter::getClassCriteria(){
    return classCriteria;
}
