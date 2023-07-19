/** @file DataBase.cpp
 *  @brief Contains the DataBase Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "DataBase.h"
#include "Sorter.h"
#include <sstream>
#include <algorithm>
#include <fstream>

DataBase::DataBase() {}

vector<UCPTR>& DataBase::getUCs() {
    return ucs;
}

set<StudentPTR>& DataBase::getStudents() {
    return students;
}

void DataBase::readStudents(){

    ifstream students_file("../InputFiles/students_classes.csv");

    string line;

    getline(students_file, line);

    string studentCode, studentName, ucCode,
            classCode;
    StudentPTR studentPtr;

    do {
        getline(students_file, studentCode, ',');
        if (studentCode == "") break;
        getline(students_file, studentName, ',');
        getline(students_file, ucCode, ',');
        getline(students_file, classCode);

        unsigned studentCodeUnsigned = stoul(studentCode);

        auto studentUC = find_if(ucs.begin(), ucs.end(),
                                 [&ucCode](UCPTR u) { return u->getCode() == ucCode; });

        auto studentClass = find_if((*studentUC)->getClasses().begin(), (*studentUC)->getClasses().end(),
                                    [&classCode](ClassPTR c) { return c->getCode() == classCode; });

        auto studentIt = find_if(students.begin(), students.end(),
                                 [studentCodeUnsigned](StudentPTR s) {
                                     return studentCodeUnsigned == s->getCode();
                                 });
        if (studentIt == students.end()) {
            studentPtr = StudentPTR(new Student(studentCodeUnsigned, studentName));
            students.insert(studentPtr);
        }
        studentPtr->addClass(*studentClass);
        studentPtr->addUC(*studentUC);
        (*studentClass)->addStudent(studentPtr);

    } while (true);
}


void DataBase::readLessons(){

    ifstream classes_file("../InputFiles/classes.csv");

    string line;

    getline(classes_file, line);

    string classCode, ucCode, lessonDay,
            lessonHour, lessonDuration, lessonType;
    int ucIndex = 0;

    do {
        getline(classes_file, classCode, ',');
        if (classCode == "") break;
        getline(classes_file, ucCode, ',');
        getline(classes_file, lessonDay, ',');
        getline(classes_file, lessonHour, ',');
        getline(classes_file, lessonDuration, ',');
        getline(classes_file, lessonType);

        float lessonHourFloat = std::stof(lessonHour);
        float lessonDurationFloat = std::stof(lessonDuration);

        if (ucCode != ucs[ucIndex]->getCode()) ucIndex++;

        auto classIt = std::find_if(ucs[ucIndex]->getClasses().begin(), ucs[ucIndex]->getClasses().end(),
                                    [&classCode](ClassPTR c) { return c->getCode() == classCode; });

        (*classIt)->addLesson(Lesson(lessonDay, lessonHourFloat, lessonDurationFloat, lessonType));
    } while (true);
}

void DataBase::readUCsAndClasses(){
    ifstream ucs_file("../InputFiles/classes_per_uc.csv");

    string line;

    getline(ucs_file, line);

    string ucCode, classCode;
    vector<Class> ucClasses;
    ucClasses.reserve(20);

    do {
        getline(ucs_file, ucCode, ',');
        if (ucCode == "") break;
        getline(ucs_file, classCode);

        if (ucCode == "UP001" && classCode == "1LEIC11")
            int x = 1;

        if (ucs.size() == 0)
            ucs.push_back(UCPTR(new UC(ucCode)));
        else if (ucCode != (*--ucs.end())->getCode())
            ucs.push_back(UCPTR(new UC(ucCode)));

        (*--ucs.end())->addClass(ClassPTR(new Class(classCode)));

    } while (true);

}

void DataBase::sort(){
    Sorter tempSorter;
    tempSorter.sort(ucs);
    for (UCPTR uc: ucs){
        tempSorter.sort(uc->getClasses());
        for(ClassPTR classe: uc->getClasses()) {
            tempSorter.sort(classe->getStudents());
        }
    }
    for (StudentPTR student: students) {
        tempSorter.sort(student->getClasses());
        tempSorter.sort(student->getUCs());
    }
}

void DataBase::read() {

    readUCsAndClasses();
    readLessons();
    readStudents();
    sort();
}

void DataBase::createStudentClasses_CSV() {
    ofstream file("../OutputFiles/students_classes.csv");
    file << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for(StudentPTR student: students) {
        auto uc = student->getUCs().begin();
        auto classe = student->getClasses().begin();
        while(uc != student->getUCs().end() && classe != student->getClasses().end())
            file << student->getCode() << ',' << student->getName() << ',' <<
            (*uc++)->getCode() << ',' << (*classe++)->getCode() << endl;
    }
}

void DataBase::createClasse_CSV() {
    ofstream file("../OutputFiles/classes.csv");
    file << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << endl;
    for(UCPTR uc: ucs)
        for (ClassPTR classe: uc->getClasses())
            for (Lesson lesson: classe->getLessons())
                file << classe->getCode() << ',' << uc->getCode() << ',' << lesson.getDay() << ','
                << lesson.getStartHour() << ',' << lesson.getDuration() << ',' << lesson.getType() << endl;
}

void DataBase::createClassePerUC_CSV(){
    ofstream file("../OutputFiles/classes_per_uc.csv");
    file << "UcCode,ClassCode" << endl;
    for(UCPTR uc: ucs)
        for (ClassPTR classe: uc->getClasses())
            file << uc->getCode() << ',' << classe->getCode() << endl;
}

void DataBase::store() {
    createClassePerUC_CSV();
    createStudentClasses_CSV();
    createClasse_CSV();
}

bool DataBase::addStudent(string code, string name) {

    auto it = lowerBound(code);
    if (it != students.end())
        if ((*it)->getCode() == stoi(code))
            return false;

    students.emplace(StudentPTR(new Student(stoi(code), name)));
    return true;
}

set<StudentPTR>::iterator DataBase::lowerBound(string code){
    return students.lower_bound(StudentPTR(new Student(stoi(code), "Temporary Student")));
}

bool DataBase::removeStudent(string code){
    auto it = lowerBound(code);
    if (it != students.end())
        if ((*it)->getCode() != stoi(code))
            return false;

    for(auto classe: (*it)->getClasses()){
        classe->removeStudents(*it);
    }
    students.erase(it);
    return true;
}
bool DataBase::changeStudentName(string code, string newName){
    auto it = lowerBound(code);
    if (it != students.end())
        if ((*it)->getCode() != stoi(code))
            return false;

    (*it)->setName(newName);
    return true;
}
bool DataBase::changeStudentCode(string oldCode, string newCode){
    auto it = lowerBound(oldCode);
    if (it != students.end())
        if ((*it)->getCode() != stoi(oldCode))
            return false;

    StudentPTR studentWithNewCode(new Student(**it));

    for(auto classe: (*it)->getClasses()){
        classe->removeStudents(*it);
    }
    students.erase(it);

    studentWithNewCode->setCode(newCode);
    students.insert(studentWithNewCode);
    for(auto classe: studentWithNewCode->getClasses()){
        classe->addStudent(studentWithNewCode);
    }
    return true;
}