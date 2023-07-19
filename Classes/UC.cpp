/** @file UC.cpp
 *  @brief Contains the UC class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "UC.h"
#include <iostream>

UC::UC(const string ucCode) : ucCode(ucCode){}

void UC::addClass(ClassPTR classe){
    classes.push_back(classe);
}

const string UC::getCode() {
    return ucCode;
};

vector<ClassPTR>& UC::getClasses() {
    return classes;
};

int UC::getOccupation(){
    int occupation = 0;
    for (ClassPTR classe: classes)
        occupation+=classe->getStudents().size();

    return occupation;
}
