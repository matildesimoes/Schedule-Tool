/** @file Menu.cpp
 *  @brief Contains the Menu class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Menu.h"
#include <iostream>
#include "Sorter.h"

using namespace std;

const string Menu::SCHEDULE_LISTS = "Listings and related options";
const string Menu::SCHEDULE_CHANGES = "Manage schedule alteration requests";
const string Menu::MANAGE_STUDENTS = "Manage Students";
const string Menu::STUDENT_SCHEDULE = "Showcase a student current schedule ";
const string Menu::EXPORT_ALTERATIONS = "Export alterations to files";
const string Menu::QUIT_APPLICATION = "Quit the application";
const string Menu::GO_BACK = "Go Back";
const string Menu::QUIT_MESSAGE = "Thanks for using LEIC Student Schedules application!";
const string Menu::INVALID_INPUT = "Invalid input! Read options and try 0, 1, 2, 3 (...)";
const string Menu::WRONG_INPUT = "That option does not exist! Read options and try 0, 1, 2, 3 (...)";


const string Menu::BY_OCCUPATION = "Students occupations";
const string Menu::BY_LISTS = "Lists";
const string Menu::SORT_OPTIONS = "Change Sorting Options";

const string Menu::OCCUPATION_BY_CLASS = "Show students occupation by Class";
const string Menu::OCCUPATION_BY_UC = "Show students occupation by UC";
const string Menu::OCCUPATION_BY_YEAR = "Show students occupation by Year";

const string Menu::STUD_BY_CLASS = "List students by class";
const string Menu::STUD_BY_UC = "List students by UC";
const string Menu::STUD_BY_YEAR = "List students by Year";
const string Menu::ALL_STUD = "List all students";
const string Menu::CLASS_BY_UC = "List classes by UC";
const string Menu::ALL_UC = "List all UCs";

const string Menu::CREATE_REQUEST = "Create a new request";
const string Menu::PROCESS_REQUESTS = "Process all pending requests";
const string Menu::REJECTED_REQUESTS = "List all rejected requests";
const string Menu::SATISFIED_REQUESTS = "List all satisfied requests";

const string Menu::LEAVE_CLASS = "Leave a current class";
const string Menu::ENTRY_CLASS = "Enter a new class";
const string Menu::SWITCH_CLASS = "Switch a current class for other within the UC";
const string Menu::MULTI_SWITCH_CLASS = "Switch multiple current classes for others within the UC";

const string Menu::ASCENDING = "Change to ascending order";
const string Menu::DESCENDING = "Change to descending order";
const string Menu::SORT_CRITERIA = "Change object(UC, Class, Student) criteria\n    by which it should be ordered";

const string Menu::ADD_STU = "Add new student";
const string Menu::CHANGE_STU_NAME = "Change student name";
const string Menu::CHANGE_STU_CODE = "Change student code";
const string Menu::DELETE_STU = "Delete student";

Menu::Menu() {}

void Menu::getWrongMessage() {
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << WRONG_INPUT
         << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}

void Menu::getInvalidMessage() {
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << INVALID_INPUT
         << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}


void Menu::startMenu() {
    cout << "=============================================" << endl;
    cout << "Welcome to the Student Scheduling application!" << endl;
    cout << "=============================================" << endl;
    cout << "Click ENTER for the options MENU";
    cin.ignore();
}

void Menu::displayMenu() {

    cout << "=============================================" << endl;
    cout << "           Student Scheduling MENU" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << SCHEDULE_LISTS << endl;
    cout << "2 - " << SCHEDULE_CHANGES << endl;
    cout << "3 - " << MANAGE_STUDENTS << endl;
    cout << "4 - " << STUDENT_SCHEDULE << endl;
    cout << "5 - " << EXPORT_ALTERATIONS << endl;
    cout << "9 - " << QUIT_APPLICATION << endl;
    cout << "Insert option number > ";
}

void Menu::displaySearchInfoMenu() {

    cout << endl;
    cout << "=============================================" << endl;
    cout << "              Listings Menu" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << BY_LISTS << endl;
    cout << "2 - " << BY_OCCUPATION << endl;
    cout << "3 - " << SORT_OPTIONS << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}


void Menu::breakLine() {
    cout << "\n" << endl;
}

void Menu::displayOccupationMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << " Check course occupation (number of students)" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << OCCUPATION_BY_CLASS << endl;
    cout << "2 - " << OCCUPATION_BY_UC << endl;
    cout << "3 - " << OCCUPATION_BY_YEAR << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}


void Menu::displayListsMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "          Student listing options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << STUD_BY_CLASS << endl;
    cout << "2 - " << STUD_BY_UC << endl;
    cout << "3 - " << STUD_BY_YEAR << endl;
    cout << "4 - " << ALL_STUD << endl;
    cout << "5 - " << CLASS_BY_UC << endl;
    cout << "6 - " << ALL_UC << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayRequestMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "   Student change schedule request options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << CREATE_REQUEST << endl;
    cout << "2 - " << PROCESS_REQUESTS << endl;
    cout << "3 - " << REJECTED_REQUESTS << endl;
    cout << "4 - " << SATISFIED_REQUESTS << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayCreateRequestMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "   Student change schedule request options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << LEAVE_CLASS << endl;
    cout << "2 - " << ENTRY_CLASS << endl;
    cout << "3 - " << SWITCH_CLASS << endl;
    cout << "4 - " << MULTI_SWITCH_CLASS << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}


void Menu::displaySorterMenu(SorterPTR sorterPtr) {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "              Sorting options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << ASCENDING << (sorterPtr->getAscendingOrder() ? "   *SELECTED*" : "") << endl;
    cout << "2 - " << DESCENDING << (sorterPtr->getAscendingOrder() ? "" : "  *SELECTED*") << endl;
    cout << "3 - " << SORT_CRITERIA << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displaySorterCriteriaMenu(SorterPTR sorterPtr) {
    cout << endl;
    cout << "===================================================================" << endl;
    cout << "Select the object for which you wish to change the sorting criteria" << endl;
    cout << "===================================================================" << endl;
    cout << "1 - UC       " << "| Currently set to: " << (sorterPtr->getUCCriteria() == UC_CODE ? "Code":"Occupation") << endl;
    cout << "2 - Class    " << "| Currently set to: " << (sorterPtr->getClassCriteria() == CLASS_CODE ? "Code":"Occupation") << endl;
    cout << "3 - Student  " << "| Currently set to: " << (sorterPtr->getStudentCriteria() == STUDENT_CODE ? "Code":"Name") << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayUcSortOptions(SorterPTR sorterPtr) {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "       UC ordering criteria options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - Code" << (sorterPtr->getUCCriteria() == UC_CODE ? "  *SELECTED*" : "") << endl;
    cout << "2 - Occupation" << (sorterPtr->getUCCriteria() == UC_OCCUPATION ? "  *SELECTED*" : "") << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayClassSortOptions(SorterPTR sorterPtr) {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "      Class ordering criteria options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - Code" << (sorterPtr->getClassCriteria() == CLASS_CODE ? "  *SELECTED*" : "") << endl;
    cout << "2 - Occupation" << (sorterPtr->getClassCriteria() == CLASS_OCCUPATION ? "  *SELECTED*" : "") << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayStudentSortOptions(SorterPTR sorterPtr) {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "     Student ordering criteria options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - Code" << (sorterPtr->getStudentCriteria() == STUDENT_CODE ? "  *SELECTED*" : "") << endl;
    cout << "2 - Name" << (sorterPtr->getStudentCriteria() == STUDENT_NAME ? "  *SELECTED*" : "") << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}

void Menu::displayStudentManagementMenu(){
    cout << endl;
    cout << "=============================================" << endl;
    cout << "      Student Management options" << endl;
    cout << "=============================================" << endl;
    cout << "1 - " << ADD_STU << endl;
    cout << "2 - " << CHANGE_STU_CODE << endl;
    cout << "3 - " << CHANGE_STU_NAME << endl;
    cout << "4 - " << DELETE_STU << endl;
    cout << "9 - " << GO_BACK << endl;
    cout << "Insert option number > ";
}




