/** @file Student.cpp
 *  @brief Contains the Student class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <algorithm>
#include "Student.h"
#include "UC.h"

using namespace std;

Student::Student(const unsigned code, const string name) :
        code(code), name(name) {}

Student::Student(Student const &student):
    code(student.code), name(student.name), ucs(student.ucs), classes(student.classes){}

const unsigned Student::getCode() {
    return code;
}

void Student::setCode(string code) {
    this->code = stoi(code);
}

const string Student::getName() {
    return name;
}

void Student::setName(string name){
    this->name = name;
}

vector<UCPTR>& Student::getUCs() {
    return ucs;
}

void Student::addUC(UCPTR uc) {
    ucs.push_back(uc);
}

bool Student::removeUC(UCPTR uc) {
    auto ucIT = find_if(ucs.begin(), ucs.end(),
            [&uc](UCPTR x) { return x->getCode() == uc->getCode(); });
    if (ucIT == ucs.end())
        return false;
    ucs.erase(ucIT);
    return true;
}

void Student::addClass(ClassPTR aClass) {
    classes.push_back(aClass);
}

bool Student::removeClass(ClassPTR classe) {
    auto classIT = find_if(classes.begin(), classes.end(),
                      [&classe](ClassPTR c) { return c->getCode() == classe->getCode(); });
    if (classIT == classes.end())
        return false;

    classes.erase(classIT);
    return true;
}

vector<ClassPTR>& Student::getClasses() {
    return classes;
}


