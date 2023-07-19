/** @file ListingApplication.cpp
 *  @brief Contains the ListingApplication class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "ListingApplication.h"
#include "Class.h"
#include "Schedule.h"
#include "Sorter.h"
#include "Searcher.h"
#include <iostream>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

ListingApplication::ListingApplication(DataBasePTR dataBasePtr, SorterPTR sorterPtr, SearcherPTR searcherPtr) :
    dataBasePtr(dataBasePtr), sorterPtr(sorterPtr), searcherPtr(searcherPtr) {}


void ListingApplication::showOccupationByClass(string classCode, string ucCode) {
    ClassPTR classe = searcherPtr->findClass(classCode,ucCode);
    if(classe == nullptr){
        cout << "UC code and/or Class code provided are invalid";
        return;
    }
    cout << "There are " << classe->getStudents().size() << " students in the class " << classe->getCode()
        << " of the UC " << ucCode << endl;
}

void ListingApplication::showOccupationByYear(char year) {
    int occupation = 0, flag;
    for (StudentPTR studentPtr: dataBasePtr->getStudents()) {
        flag = 0;
        for (auto aClass: studentPtr->getClasses()) {
            if ((aClass->getCode())[0] == year && !flag) {
                occupation++;
                flag = 1;
            }
        }
    }
    cout << "There are " << occupation << " students in the " << year << " year" << endl;
}

void ListingApplication::showOccupationByUC(string ucCode) {
    UCPTR uc = searcherPtr->findUC(ucCode);
    if(uc == nullptr){
        cout << "\nUC code and/or Class code provided are invalid";
        return;
    }
    cout << "There are " << uc->getOccupation() << " students in the UC with the code " << uc->getCode() << endl;
}

void ListingApplication::listStudentsByClass(string classCode, string ucCode) {

    ClassPTR classe = searcherPtr->findClass(classCode,ucCode);
    if(classe == nullptr){
        cout << "\nUC code and/or Class code provided are invalid";
        return;
    }
    vector<StudentPTR> studentsClass;
    for(StudentPTR student: classe->getStudents()){
        studentsClass.push_back(student);
    }
    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getStudentCriteria() == STUDENT_CODE ? "Code" : "Name";

    cout << left << endl;
    cout << "======================================================================\n";
    cout << "| All Students in Class " << ucCode << ", sorted in "
         << setw(24) << order + " Order by " + criteria << " |" << endl;
    cout << "======================================================================\n";
    cout << "|  " << std::setw(26) << "Code" << "| " << setw(38) << "Name" << "|\n";
    cout << "----------------------------------------------------------------------\n";

    sorterPtr->sort(studentsClass);
    for (StudentPTR student: studentsClass)
        cout << "|  " << std::setw(26) << student->getCode() << "| " << setw(38) << student->getName() << "|\n";
    cout << "----------------------------------------------------------------------\n";

}

void ListingApplication::listStudentsByUC(string ucCode) {
    UCPTR uc = searcherPtr->findUC(ucCode);
    if(uc == nullptr){
        cout << "\nUC code is invalid";
        return;
    }
    vector<StudentPTR> studentsUC;
    for(ClassPTR classes: uc->getClasses()){
        for(StudentPTR student: classes->getStudents()){
            studentsUC.push_back(student);
        }
    }

    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getStudentCriteria() == STUDENT_CODE ? "Code" : "Name";

    cout << left << endl;
    cout << "===================================================================\n";
    cout << "| All Students in UC " << ucCode << ", sorted in " <<
            setw(24) << order + " Order by " + criteria << " |" << endl;
    cout << "===================================================================\n";
    cout << "|  " << std::setw(23) << "Code" << "| " << setw(38) << "Name" << "|\n";
    cout << "-------------------------------------------------------------------\n";

    sorterPtr->sort(studentsUC);
    for (StudentPTR student: studentsUC)
        cout << "|  " << std::setw(23) << student->getCode() << "| " << setw(38) << student->getName() << "|\n";
    cout << "-------------------------------------------------------------------\n";
}

void ListingApplication::listStudentsByYear(char year) {

    set<unsigned> studentCodes;
    vector<StudentPTR> students;

    for (StudentPTR student: dataBasePtr->getStudents())
        for (auto aClass: student->getClasses())
            if ((aClass->getCode()[0] == year) &&
                !(studentCodes.find(student->getCode()) != studentCodes.end())) {
                students.push_back(student);
                studentCodes.insert(student->getCode());
            }
    if (studentCodes.empty()) {
        cout << "No students present in the year provided"; return;
    }

    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getStudentCriteria() == STUDENT_CODE ? "Code" : "Name";

    cout << left << endl;
    cout << "==============================================================\n";
    cout << "| All Students in year " << year << ", sorted in "
    << setw(24) << order + " Order by " + criteria << " |" << endl;
    cout << "==============================================================\n";
    cout  << "|  " << std::setw(20) << "Code" << "| " << setw(36) << "Name" << "|\n";
    cout << "--------------------------------------------------------------\n";

    sorterPtr->sort(students);
    for(StudentPTR student: students)
        cout << "|  " << std::setw(20) << student->getCode() << "| " << setw(36) << student->getName() << "|\n";
    cout << "--------------------------------------------------------------\n";
}

void ListingApplication::listUCs(){

    vector<UCPTR> ucs = dataBasePtr->getUCs();

    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getUCCriteria() == UC_CODE ? "Code" : "Occupation";

    cout << left << endl;
    cout << "====================================================\n";
    cout << "| All UCs sorted in " << setw(30) << order + " Order by " + criteria << " |" << endl;
    cout << "====================================================\n";
    cout  << "|  " << std::setw(20) << "Code" << "| " << setw(26) << "Occupation" << "|\n";
    cout << "----------------------------------------------------\n";

    sorterPtr->sort(ucs);
    for (UCPTR uc: ucs)
        cout << "|  " << std::setw(20) << uc->getCode() << "| " << setw(26) << uc->getOccupation() << "|\n";
    cout << "----------------------------------------------------\n";
}

void ListingApplication::listClassesByUC(string ucCode){
    UCPTR uc = searcherPtr->findUC(ucCode);
    if(uc == nullptr){
        cout << "\nUC code is invalid";
        return;
    }

    vector<ClassPTR> classes = uc->getClasses();

    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getClassCriteria() == CLASS_CODE ? "Code" : "Occupation";

    cout << left << endl;
    cout << "=======================================================================\n";
    cout << "| All Classes in UC " << ucCode << " sorted in " << setw(30) << order + " Order by " + criteria << " |" << endl;
    cout << "=======================================================================\n";
    cout  << "|  " << std::setw(27) << "Code" << "| " << setw(38) << "Occupation" << "|\n";
    cout << "-----------------------------------------------------------------------\n";

    sorterPtr->sort(classes);
    for (ClassPTR classe: classes)
        cout << "|  " << std::setw(27) << classe->getCode() << "| " << setw(38) << classe->getStudents().size() << "|\n";
    cout << "-----------------------------------------------------------------------\n";
}

void ListingApplication::listAllStudents(){
    vector<StudentPTR> students;
    for(StudentPTR student: dataBasePtr->getStudents()){
        students.push_back(student);
    }

    string order = sorterPtr->getAscendingOrder() ? "Ascending" : "Descending";
    string criteria = sorterPtr->getStudentCriteria() == STUDENT_CODE ? "Code" : "Name";

    cout << left << endl;
    cout << "===================================================\n";
    cout << "| All Students sorted in " << setw(24) << order + " Order by " + criteria << " |" << endl;
    cout << "===================================================\n";
    cout  << "|  " << std::setw(17) << "Code" << "| " << setw(28) << "Name" << "|\n";
    cout << "----------------------------------------------------\n";

    sorterPtr->sort(students);
    for(StudentPTR student: students)
        cout << "|  " << std::setw(17) << student->getCode() << "| " << setw(28) << student->getName() << "|\n";

    cout << "---------------------------------------------------\n";

}