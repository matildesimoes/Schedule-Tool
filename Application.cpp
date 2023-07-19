/** @file Application.cpp
 *  @brief Contains the Application class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Application.h"
#include <stdexcept>      // std::invalid_argument


Application::Application() {}


void Application::startApplication() {
    dataBasePtr->read();
    dataBasePtr->store();
    startMenu();
}

void Application::startMenu() {
    menu.startMenu();
    menu.breakLine();
    displayMenu();
}

void Application::safeInput(string &option, int &safeOption) {
    try {
        cin >> option;
        safeOption = stoi(option);
    }
    catch (const invalid_argument &ia) {
        menu.breakLine();
        menu.getInvalidMessage();
        menu.breakLine();
        safeOption = 0;
    }
}

void Application::menuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayMenu();
        safeInput(option, safeOption);
    }
}

void Application::listMenuSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayListsMenu();
        safeInput(option, safeOption);
    }
}


void Application::occupationSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayOccupationMenu();
        safeInput(option, safeOption);
    }
}

void Application::requestSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayRequestMenu();
        safeInput(option, safeOption);
    }
}

void Application::createRequestSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayCreateRequestMenu();
        safeInput(option, safeOption);
    }
}

void Application::sortSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displaySorterMenu(sorterPtr);
        safeInput(option, safeOption);
    }
}

void Application::sortCriteriaSafety(std::string &option, int &safeOption) {
    while (!safeOption) {
        menu.displaySorterCriteriaMenu(sorterPtr);
        safeInput(option, safeOption);
    }
}

void Application::studentsSafety(string &option, int &safeOption) {
    while (!safeOption) {
        menu.displayStudentManagementMenu();
        safeInput(option, safeOption);
    }
}

void Application::occupationMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    occupationSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case STUD_BY_CLASS: {
                string ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                string classCode;
                cout << "Type class code to list:";
                cin >> classCode;
                scheduleApp.showOccupationByClass(classCode, ucCode);
                break;
            }
            case STUD_BY_UC: {
                string ucCode;
                cout << "Type the UC code to check:";
                cin >> ucCode;
                scheduleApp.showOccupationByUC(ucCode);
                break;
            }
            case STUD_BY_YEAR:
                char year;
                cout << "Type the year to check (1, 2 or 3):";
                cin >> year;
                scheduleApp.showOccupationByYear(year);
                break;

            default: {
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
            }
        }
        menu.breakLine();
        safeOption = 0;
        occupationSafety(option, safeOption);
    }
    safeOption = 0;
}

void Application::listsMenu(int &oldOption) {
    string option;
    menu.displayListsMenu();
    int safeOption;
    safeInput(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case STUD_BY_CLASS: {
                string ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                string classCode;
                cout << "Type class code to list:";
                cin >> classCode;
                scheduleApp.listStudentsByClass(classCode, ucCode);
                break;
            }
            case STUD_BY_UC: {
                string ucCode;
                cout << "Type UC code to list:";
                cin >> ucCode;
                scheduleApp.listStudentsByUC(ucCode);
                break;
            }
            case STUD_BY_YEAR: {
                char year;
                cout << "Type year number (1, 2 or 3) to list:";
                cin >> year;
                scheduleApp.listStudentsByYear(year);
                break;
            }
            case ALL_STUD: {
                scheduleApp.listAllStudents();
                break;
            }
            case CLASS_BY_UC: {
                string ucCode;
                cout << "Type UC code to list:";
                cin >> ucCode;
                scheduleApp.listClassesByUC(ucCode);
                break;
            }
            case ALL_UCS: {
                scheduleApp.listUCs();
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
            }
        }
        menu.breakLine();
        safeOption = 0;
        listMenuSafety(option, safeOption);
    }
    oldOption = 0;
    cout << menu.QUIT_MESSAGE << endl;
}

void Application::sortMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    sortSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case ASCENDING: {
                sorterPtr->setAscendingOrder();
                cout << "Changed to ascending order successfully!" << endl;
                break;
            }
            case DESCENDING: {
                sorterPtr->setDescendingOrder();
                cout << "Changed to descending order successfully!" << endl;
                break;
            }
            case CRITERIA: {
                sortCriteriaMenu(oldOption);
                cout << "Changed criteria successfully!" << endl;
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
        }
        safeOption = 0;
        menu.breakLine();
        sortSafety(option, safeOption);
    }
    oldOption = 0;
}

void Application::sortCriteriaMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    sortCriteriaSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case SORT_UC: {
                menu.displayUcSortOptions(sorterPtr);
                int newOption;
                while (true) {
                    cin >> newOption;
                    if (newOption == 1) {
                        sorterPtr->setUcCriteria(UC_CODE);
                        break;
                    } else if (newOption == 2) {
                        sorterPtr->setUcCriteria(UC_OCCUPATION);
                        break;
                    } else if (newOption == 9) {
                        safeOption = 9;
                        break;
                    } else
                        cout << "Invalid input. Type again > ";
                }
                break;
            }
            case SORT_CLASS: {
                menu.displayClassSortOptions(sorterPtr);
                int newOption;
                while (true) {
                    cin >> newOption;
                    if (newOption == 1) {
                        sorterPtr->setClassCriteria(CLASS_CODE);
                        break;
                    } else if (newOption == 2) {
                        sorterPtr->setClassCriteria(CLASS_OCCUPATION);
                        break;
                    } else if (newOption == 9) {
                        safeOption = 9;
                        break;
                    } else
                        cout << "Invalid input. Type again > ";
                }
                break;
            }
            case SORT_STUDENT: {
                menu.displayStudentSortOptions(sorterPtr);
                int newOption;
                while (true) {
                    cin >> newOption;
                    if (newOption == 1) {
                        sorterPtr->setStudentCriteria(STUDENT_CODE);
                        break;
                    } else if (newOption == 2) {
                        sorterPtr->setStudentCriteria(STUDENT_NAME);
                        break;
                    } else if (newOption == 9) {
                        safeOption = 9;
                        break;
                    } else
                        cout << "Invalid input. Type again > ";
                }
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
        }
        menu.breakLine();
        sortCriteriaSafety(option, safeOption);
    }
    oldOption = 9;
}

void Application::requestMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    requestSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case CREATE_REQUEST: {
                createRequestMenu(safeOption);
                break;
            }
            case PROCESS_REQUESTS: {
                requestApp.processRequests();
                break;
            }
            case REJECTED_REQUESTS: {
                requestApp.listRejectedRequests();
                break;
            }
            case SATISFIED_REQUESTS: {
                requestApp.listSatisfiedRequests();
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
        }
        safeOption = 0;
        menu.breakLine();
        requestSafety(option, safeOption);
    }
    oldOption = 0;
}

void Application::createRequestMenu(int &oldOption) {
    string studentCode;
    string option;
    int safeOption = 0;
    createRequestSafety(option, safeOption);
    while (safeOption != QUIT) {
        cout << "Insert student number > ";
        studentCode = validStudentCode();
        switch (safeOption) {
            case TO_REMOVE: {
                Request request(REMOVE, searcherPtr->findStudent(studentCode), studentCode);
                string exitClassCode, ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                cout << "Type the class code to leave:";
                cin >> exitClassCode;
                UCPTR uc = searcherPtr->findUC(ucCode);
                ClassPTR exitClass = searcherPtr->findClass(exitClassCode, ucCode);
                request.addExitClass(exitClass, uc);
                cout << "Request successfully added to waiting queue" << endl;
                requestApp.addRequest(request);
                break;
            }
            case TO_ADD: {
                Request request(ADD, searcherPtr->findStudent(studentCode), studentCode);
                string entryClassCode, ucCode;
                cout << "Type the UC code relative to the class:";
                cin >> ucCode;
                cout << "Type the class code to enter:";
                cin >> entryClassCode;
                UCPTR uc = searcherPtr->findUC(ucCode);
                ClassPTR entryClass = searcherPtr->findClass(entryClassCode, ucCode);
                request.addEntryClass(entryClass, uc);
                cout << "\nRequest successfully added to waiting queue" << endl;
                requestApp.addRequest(request);
                break;
            }
            case TO_SWITCH: {
                Request request(SWITCH, searcherPtr->findStudent(studentCode), studentCode);
                cout << "Type the UC code relative to the classes:";
                string exitClassCode, entryClassCode, ucCode;
                cin >> ucCode;
                cout << "Type the class code to leave:";
                cin >> exitClassCode;
                cout << "Type the class code to enter:";
                cin >> entryClassCode;
                UCPTR uc = searcherPtr->findUC(ucCode);
                ClassPTR exitClass = searcherPtr->findClass(exitClassCode, ucCode);
                ClassPTR entryClass = searcherPtr->findClass(entryClassCode, ucCode);
                request.addSwitchClasses(entryClass, exitClass, uc);
                cout << "Request successfully added to waiting queue" << endl;
                requestApp.addRequest(request);
                break;
            }

            case TO_MULTIPLE_SWITCH: {
                Request request(MULTI_SWITCH, searcherPtr->findStudent(studentCode), studentCode);
                while (true) {
                    cout << "Type the UC code relative to the classes:";
                    string exitClassCode, entryClassCode, ucCode;
                    cin >> ucCode;
                    cout << "Type the class code to leave:";
                    cin >> exitClassCode;
                    cout << "Type the class code to enter:";
                    cin >> entryClassCode;
                    UCPTR uc = searcherPtr->findUC(ucCode);
                    ClassPTR exitClass = searcherPtr->findClass(exitClassCode, ucCode);
                    ClassPTR entryClass = searcherPtr->findClass(entryClassCode, ucCode);
                    request.addSwitchClasses(entryClass, exitClass, uc);
                    cout << "Request added with success!" << endl;
                    cout << "1 - Continue adding classes to switch" << endl;
                    cout << "2 - Finish request" << endl;
                    cout << "Insert option number > ";
                    safeInput(option, safeOption);
                    while (safeOption != 2 && safeOption != 1) {
                        cout << "Invalid input, type again > ";
                        safeInput(option, safeOption);
                    }
                    if (safeOption == 2) break;
                }
                cout << "Request successfully added to waiting queue" << endl;
                requestApp.addRequest(request);
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                break;
        }
        safeOption = 0;
        menu.breakLine();
        createRequestSafety(option, safeOption);
    }
    oldOption = 0;
}


void Application::optionFilter(int &option) {
    while (option != QUIT) {
        switch (option) {
            case LISTS: {
                listsMenu(option);
                break;
            }
            case OCCUPATION: {
                occupationMenu(option);
                break;
            }
            case SORT: {
                sortMenu(option);
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                break;
            }
        }
        menu.breakLine();
        menu.displaySearchInfoMenu();
        cin >> option;
    }
    option = 0;
}

void Application::studentsMenu(int &oldOption) {
    string option;
    int safeOption = 0;
    studentsSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case ADD_STU: {
                string code, name;
                cout << "Type the new student code > ";
                code = validStudentCode();
                cout << "Type the new student name > ";
                cin.ignore();
                getline(cin, name);
                if(dataBasePtr->addStudent(code, name))
                    cout << "\nThe student was added with success!" << endl;
                else
                    cout << "\nFAILURE. There is already a student with the code provided!" << endl;
                break;
            }
            case CHANGE_CODE: {
                string oldCode, newCode;
                cout << "Type the student code > ";
                oldCode = validStudentCode();
                cout << "Type the new student code > ";
                newCode = validStudentCode();
                if (dataBasePtr->changeStudentCode(oldCode, newCode))
                    cout << "\nThe student code was changed with success!" << endl;
                else
                    cout << "\nFAILURE. No student found with the code provided!" << endl;
                break;
            }
            case CHANGE_NAME: {
                string code, newName;
                cout << "Type the student code > ";
                code = validStudentCode();
                cout << "Type the new student name > ";
                cin.ignore();
                getline(cin, newName);
                if(dataBasePtr->changeStudentName(code, newName))
                    cout << "\nThe student name was changed with success!" << endl;
                else
                    cout << "\nFAILURE. No student found with the code provided!" << endl;
                break;
            }
            case DELETE_STU: {
                string code;
                cout << "Type the student code > ";
                code = validStudentCode();
                if (dataBasePtr->removeStudent(code))
                    cout << "\nThe student was deleted with success!" << endl;
                else
                    cout << "\nFAILURE. No student found with the code provided!" << endl;
                break;
            }
            default: {
                menu.breakLine();
                menu.getWrongMessage();
                break;
            }
        }
        safeOption = 0;
        menu.breakLine();
        studentsSafety(option, safeOption);
    }
    oldOption = 0;
}


void Application::displayMenu() {
    string option;
    int safeOption = 0;

    menuSafety(option, safeOption);
    while (safeOption != QUIT) {
        switch (safeOption) {
            case LISTS: {
                string option;
                menu.displaySearchInfoMenu();
                safeInput(option, safeOption);
                optionFilter(safeOption);
                break;
            }
            case CHANGES: {
                requestMenu(safeOption);
                break;
            }
            case MANAGE_STUDENTS: {
                studentsMenu(safeOption);
                break;
            }
            case SHOWCASE_SCHEDULE: {
                cout << "Type student code to check schedule > ";
                string studentCode;
                studentCode = validStudentCode();
                Schedule schedule(searcherPtr->findStudent(studentCode));
                schedule.showSchedule();
                safeOption = 0;
                break;
            }
            case EXPORT_ALTERATIONS: {
                dataBasePtr->store();
                cout << endl;
                cout << "===========================================================" << endl;
                cout << "Alterations are now saved within \"OutputFiles\" directory" << endl;
                cout << "===========================================================" << endl;
                cout << "9 - Go Back" << endl;
                cout << "Insert option number > ";
                safeInput(option, safeOption);
                while (safeOption != QUIT) {
                    cout << "\nInvalid input. Type again > ";
                    cin >> option;
                }
                safeOption = 0;
                break;
            }
            default:
                menu.breakLine();
                menu.getWrongMessage();
                safeOption = 0;
                break;
        }
        menu.breakLine();
        menuSafety(option, safeOption);
    }
    cout << menu.QUIT_MESSAGE << endl;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string validStudentCode() {
    string studentCode;
    cin >> studentCode;
    while (!is_number(studentCode)) {
        cout << "Type a valid numeric value for the student code > ";
        cin >> studentCode;
    }
    return studentCode;
}






