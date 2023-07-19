/** @file Request.cpp
 *  @brief Contains the Request class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include "Request.h"
#include "Class.h"
#include <iostream>
#include <iomanip>

int Request::count = 0;

Request::Request(requestType type, StudentPTR studentPtr, string providedCode):
    type(type), studentPtr(studentPtr), providedCode(providedCode){
    count++;
    id = count;
}

int Request::getID(){
    return id;
}

bool Request::addSwitchClasses(ClassPTR entryClass, ClassPTR exitClass, UCPTR uc) {

    if (type != MULTI_SWITCH && type != SWITCH) return false;
    entryClasses.push_back(entryClass);
    exitClasses.push_back(exitClass);
    ucs.push_back(uc);
    return true;

}

bool Request::addExitClass(ClassPTR exitClass, UCPTR uc){

    if (type != REMOVE || exitClasses.size() >= 1) return false;
    exitClasses.push_back(exitClass);
    ucs.push_back(uc);
    return true;
}

bool Request::addEntryClass(ClassPTR entryClass, UCPTR uc){

    if (type != ADD || entryClasses.size() >= 1) return false;
    entryClasses.push_back(entryClass);
    ucs.push_back(uc);
    return true;
}

StudentPTR Request::getStudent() {
    return studentPtr;
}

list<UCPTR>& Request::getUCs(){
    return ucs;
}

list<ClassPTR>& Request::getExitClasses(){
    return exitClasses;
}

list<ClassPTR>& Request::getEntryClasses(){
    return entryClasses;
}

requestType Request::getType(){
    return type;
}

void Request::popFront(){
    entryClasses.pop_front();
    exitClasses.pop_front();
    ucs.pop_front();
}

bool Request::rejected(){
    return rejectionState;
}

void Request::setToRejected() {
    rejectionState = true;
}

string Request::getReason() {
    return *rejectionReason;
}

shared_ptr<string>& Request::getReasonPTR() {
    return rejectionReason;
}

void Request::setReason(string reason) {
    *rejectionReason = reason;
}

string Request::getProvidedCode(){
    return providedCode;
}

bool Request::dataChecksUp(SearcherPTR searcher){
    auto entry = entryClasses.begin();
    auto exit = exitClasses.begin();
    auto uc = ucs.begin();

    if (studentPtr == nullptr) {
        setReason("Student code provided invalid");
        rejectionState = true; return false;
    }

    while(true) {
        if(uc == ucs.end()) break;
        if (*uc == nullptr) {
            setReason("UC code provided invalid");
            rejectionState = true; return false;
        }

        if (type != ADD && exit != exitClasses.end()) {
            if (*exit == nullptr) {
                setReason("Exit class code provided invalid");
                rejectionState = true; return false;
            }
            if (searcher->findStudentInClass(to_string(studentPtr->getCode()), *exit) == nullptr) {

                setReason("Student is not in exit class");

                rejectionState = true; return false;
            }

        }
        if (type != REMOVE && entry != entryClasses.end()) {
            if (*entry == nullptr) {
                setReason("Entry class code provided invalid");
                rejectionState = true;
                return false;
            }
            if (searcher->findStudentInClass(to_string(studentPtr->getCode()), *entry) != nullptr) {
                setReason("Students already in entry class");
                rejectionState = true;
                return false;
            }
        }
        uc++; entry++; exit++;
    }

    if (type == MULTI_SWITCH) {
        auto uc = ucs.begin();
        while (uc != ucs.end()) {
            auto uc_trash = uc;
            for(auto uc2 = ++uc_trash; uc2 != ucs.end(); uc2++) {
                if ((*uc)->getCode() == (*uc2)->getCode()) {
                    setReason("Multiple switches given for the same UC");
                    rejectionState = true;
                    return false;
                }
            }
            uc++;
        }
    }
    return true;
}

ostream& operator<<(ostream&os, Request request){
    auto exit = request.getExitClasses().begin();
    auto entry = request.getEntryClasses().begin();
    auto uc = request.getUCs().begin();
    if (request.rejected()) {
        os << "| " << request.getID() << " |  " << setw(11) << request.getProvidedCode();
        os << "|" << setw(80) << request.getReason() << '|' << endl;
        return os;
    }
    switch (request.getType()){
        case ADD:
            os << "| " << request.getID() << " |  " << setw(11) << request.getProvidedCode();
            os << "| " << setw(17) << "       ---";
            os << "| " << setw(17) << (*uc)->getCode() + "," + (*entry)->getCode() << "|\n";
            break;
        case REMOVE:
            os << "| " << request.getID() << " |  " << setw(11) << request.getProvidedCode();
            os << "| " << setw(17) << (*uc)->getCode() + "," + (*exit)->getCode();
            os << "| " << setw(18) << "       ---" << '|' << endl;
            break;
        case SWITCH:
            os << "| " << request.getID() << " |  " << setw(11) << request.getProvidedCode();
            os << "| " << setw(17) << (*uc)->getCode() + "," + (*exit)->getCode();
            os << "| " << setw(17) << (*uc)->getCode() + "," + (*entry)->getCode() << "|\n";
            break;

        case MULTI_SWITCH:
            while(uc != request.getUCs().end()){
                os << "| " << (uc == request.getUCs().begin() ? to_string(request.getID()) : "\\") << " |  "
                   << setw(11) << request.getProvidedCode();
                os << "| " << setw(17) << (*uc)->getCode() + "," + (*exit)->getCode();
                os << "| " << setw(17) << (*uc)->getCode() + "," + (*entry)->getCode() << "|\n";
                entry++; exit++; uc++;
            }
            break;
    }
    return os;
}

