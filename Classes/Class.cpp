/** @file Class.cpp
 *  @brief Contains the Class class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <algorithm>
#include "Class.h"

Class::Class(string code): code(code){}

const string Class::getCode(){
    return code;
}

vector<StudentPTR>& Class::getStudents(){
    return students;
}

void Class::addStudent(StudentPTR student){
    auto pos = lower_bound(students.begin(), students.end(), student,
                           [](StudentPTR s1, StudentPTR s2){return s1->getCode() <= s2->getCode();});
    students.insert(pos, student);
}

vector<Lesson>& Class::getLessons(){
    return lessons;
}

void Class::addLesson(Lesson lesson){
    lessons.push_back(lesson);
}

bool Class::removeStudents(StudentPTR student){
    auto it = find_if(students.begin(), students.end(),
                      [student](StudentPTR s){return s->getCode() == student->getCode();});
    if (it == students.end()) return false;
    students.erase(it);
    return true;
}