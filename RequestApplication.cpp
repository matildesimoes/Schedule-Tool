/** @file RequestApplication.cpp
 *  @brief Contains the RequestApplication class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <iostream>
#include <iomanip>
#include "RequestApplication.h"

RequestApplication::RequestApplication(SearcherPTR searcherPtr): searcherPtr(searcherPtr) {}



void RequestApplication::removeStudent(Request request) {

    (*request.getExitClasses().begin())->removeStudents(request.getStudent());

    request.getStudent()->removeClass(*(request.getExitClasses().begin()));

    request.getStudent()->removeUC(*(request.getUCs().begin()));
}

bool RequestApplication::addStudent(Request request) {

    if ((*(request.getEntryClasses().begin()))->getStudents().size() + 1 > CAP) {
        request.setReason((*(request.getExitClasses().begin()))->getCode() +
                          " has maximum number of students");
        return false;
    }

    if (!maintainsBalance(request)) return false;

    if (!scheduleCompatible(request.getStudent()->getClasses(),
                            *(request.getEntryClasses().begin()), request.getReasonPTR()))
        return false;

    (*(request.getEntryClasses().begin()))->addStudent(request.getStudent());
    request.getStudent()->addUC(*request.getUCs().begin());
    request.getStudent()->addClass(*request.getEntryClasses().begin());

    return true;
}

bool RequestApplication::canSwitchStudent(Request request){
    if ((*request.getEntryClasses().begin())->getStudents().size() + 1 > CAP) return false;

    if (!maintainsBalance(request)) return false;

    if (!scheduleCompatible(request.getStudent()->getClasses(), *(request.getEntryClasses().begin()),
                            request.getReasonPTR(),
                            (*request.getExitClasses().begin())->getCode())) {
        request.setReason((*request.getUCs().begin())->getCode() + ": " + request.getReason());
        return false;
    }

    return true;
}

bool RequestApplication::switchStudent(Request request) {

    if (!canSwitchStudent(request)) return false;

    (*request.getEntryClasses().begin())->addStudent(request.getStudent());
    request.getStudent()->addUC(*request.getUCs().begin());
    request.getStudent()->addClass(*request.getEntryClasses().begin());
    removeStudent(request);
    return true;
}

bool RequestApplication::multiSwitchStudent(Request request){

    Request copy = request;
    while(copy.getEntryClasses().size() > 0){
        if (!canSwitchStudent(request)) return false;
        copy.popFront();
    }
    while(request.getEntryClasses().size() > 0){
        (*request.getEntryClasses().begin())->addStudent(request.getStudent());
        request.getStudent()->addUC(*request.getUCs().begin());
        request.getStudent()->addClass(*request.getEntryClasses().begin());
        removeStudent(request);
        request.popFront();
    }
    return true;
}

void RequestApplication::processRequests() {
    if (waiting.empty()) cout << "There is no waiting requests to process!" << endl;
    else {
        while (!waiting.empty()) {
            Request request = waiting.front();
            if(request.dataChecksUp(searcherPtr))
                switch (request.getType()) {
                    case REMOVE:
                        removeStudent(request);
                        satisfied.push_back(request);
                        break;
                    case ADD:
                        if (addStudent(request))
                            satisfied.push_back(request);
                        else {
                            request.setToRejected();
                            rejected.push_back(request);
                        }
                        break;
                    case SWITCH:
                        if (switchStudent(request))
                            satisfied.push_back(request);
                        else {
                            request.setToRejected();
                            rejected.push_back(request);
                        }
                        break;

                    case MULTI_SWITCH:
                        if (multiSwitchStudent(request))
                            satisfied.push_back(request);
                        else {
                            request.setToRejected();
                            rejected.push_back(request);
                        }
                        break;
                }
            else
                rejected.push_back(request);

            waiting.pop();
        }
        cout << "=============================================" << endl;
        cout << "\nAll waiting requests processed with success!" << endl;
        cout << "=============================================" << endl;
    }
}

void RequestApplication::addRequest(Request request) {
    waiting.push(request);
}

void RequestApplication::listRejectedRequests() {
    cout << endl;
    if (rejected.empty()) {
        cout << "There are no rejected requests to list!" << endl;
        return;
    }
    else {
        cout << "====================================================================================================" << endl;
        cout << "|                                        Rejected Requests                                         |" << endl;
        cout << "====================================================================================================" << endl;
        cout << left << "| N |" << setw(13) << " studentcode" << '|';
        cout << setw(80) << "                                            Reason" << "|\n";
        for (Request request: rejected) {
            cout << "----------------------------------------------------------------------------------------------------" << endl << left;
            cout << request;
        }
        cout << "----------------------------------------------------------------------------------------------------" << endl;
    }
}

void RequestApplication::listSatisfiedRequests() {
    cout << endl;
    if (satisfied.empty()) {
        cout << "There are no satisfied requests to list!" << endl;
        return;
    }
    else {
        cout << "=========================================================" << endl;
        cout << "|                   Satisfied Requests                  |" << endl;
        cout << "=========================================================" << endl;
        cout << left << "| N |" << setw(13) << " studentcode" << '|';
        cout << setw(18) << "     To Leave" << '|' << setw(18) << "    To Enter" << "|\n";
        for (Request request: satisfied) {
            cout << request;
        }
        cout << "---------------------------------------------------------" << endl;
    }
}

bool lessonsOverlap(Lesson l1, Lesson l2) {
    if (l1.getDay() != l2.getDay()) return false;
    else {
        if (l1.getType() == "T" || l2.getType() == "T") return false;
        else {
            if (l1.getStartHour() + l1.getDuration() <= l2.getStartHour()) return false;
            else if (l2.getStartHour() + l2.getDuration() <= l1.getStartHour()) return false;
            else return true;
        }
    }
}

bool scheduleCompatible(vector<ClassPTR> actualClasses,
                        ClassPTR entryClass, shared_ptr<string> rejection, string exitClassCode) {

    for (auto actualClasse: actualClasses) {
        if (actualClasse->getCode() == exitClassCode) continue;
        for (auto entryLesson: entryClass->getLessons()) {
            for (auto actualLesson: actualClasse->getLessons()) {
                if (lessonsOverlap(actualLesson, entryLesson)) {
                    *rejection = actualClasse->getCode() + " & " + entryClass->getCode() + " lessons overlap on " +
                                 entryLesson.getDay();
                    return false;
                }
            }
        }
    }
    return true;
}

int maxUCinbalance(UCPTR uc) {
    int max = (*uc->getClasses().begin())->getStudents().size();
    int min = (*uc->getClasses().begin())->getStudents().size();
    for (ClassPTR classe: uc->getClasses()) {
        if (max < classe->getStudents().size()) max = classe->getStudents().size();
        if (min > classe->getStudents().size()) min = classe->getStudents().size();
    }
    return max - min;
}

bool maintainsBalance(Request request){

    int diff;
    int maxImbalance = maxUCinbalance(*request.getUCs().begin());
    int entryClassSize = ((*request.getEntryClasses().begin())->getStudents().size() + 1);
    int aClassSize;

    for (ClassPTR classe: (*(request.getUCs().begin()))->getClasses()) {

        if (request.getType() == SWITCH || request.getType() == MULTI_SWITCH) {
            if (classe->getCode() == ((*(request.getExitClasses().begin()))->getCode()))
                aClassSize = classe->getStudents().size();
            else
                aClassSize = classe->getStudents().size();
        } else {
            aClassSize = classe->getStudents().size();
        }
        diff = aClassSize - entryClassSize;

        if (maxImbalance < 4 && abs(diff) >= 4) {
            request.setReason((*(request.getUCs().begin()))->getCode() + ": " +
                              (*(request.getEntryClasses().begin()))->getCode() +
                              " & " + classe->getCode() + " would create an imbalance >= 4");
            return false;
        }
        if (maxImbalance >= 4 && abs(diff) > maxImbalance) {
            request.setReason((*(request.getUCs().begin()))->getCode() + ": " +
                              (*(request.getEntryClasses().begin()))->getCode() +
                              " & " + classe->getCode() + " would create an imbalance > the existing one of "
                              + to_string(maxImbalance));
            return false;
        }
    }
    return true;
}