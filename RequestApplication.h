/** @file RequestApplication.h
 *  @brief Contains the RequestApplication class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_REQUESTAPPLICATION_H
#define AED_FEUP_PROJ_22_23_REQUESTAPPLICATION_H

#include "Student.h"
#include "Class.h"
#include "UC.h"
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include "../Classes/Student.h"
#include "../Classes/Class.h"
#include "../Classes/UC.h"
#include "..\Classes\DataBase.h"
#include "Request.h"
#include "Searcher.h"

using namespace std;

/** @brief RequestApplication class to deal with all the requests.
 *
 *  Intended to be instanced once.
 *  It is used to store and process requests
 *  The requests can be: add type, remove type, switch type and
 *  multiple switch type
 *  The requests need to satisfy some conditions in order to take place
 *  and then they are added to a list of satisfied requests.
 *  Otherwise they are rejected and stored in a different list.
 */
class RequestApplication {

    //! @brief Pointer that refers to the object Searcher in the Application.
    SearcherPTR searcherPtr;

    //! @brief Holds all the requests that have been requested.
    queue<Request> waiting;

    //! @brief Holds all the requests that did not satisfies the conditions.
    list<Request> rejected;

    //! @brief Holds all the requests that satisfied the conditions.
    list<Request> satisfied;

    //! @brief Number that represent the maximum capacity of each class.
    static const int CAP = 30;

public:


    /** @brief Create a new RequestApplication with only searcherPtr.
     *
     * @param searcherPtr Of type SearcherPTR.
     */
    RequestApplication(SearcherPTR searcherPtr);

    /** @brief Removes the student from one class.
     *
     *  It will remove the student from the exit class.
     *  It will remove the class and uc from the Student Class.
     *
     *  @param request Of the type Request.
     *  @return True if all conditions are satisfied and remove granted, False if otherwise.
     */
    void removeStudent(Request request);

    /** @brief Adds the student to one class.
     *
     *  It will invoke maintainsBalance and scheduleCompatible methods
     *  to ensure that their correspondent criteria are met.
     *  If so, it will add the student to the entry class,
     *  and add the uc and class to the student.
     *
     *  @param request Of the type Request.
     *  @return True if all conditions are satisfied and request granted, False if otherwise.
     */
    bool addStudent(Request request);


    /** @brief Checks if a student can switch between classes.
     *
     *  Checks if the entry class is above the cap.
     *  Checks if the UC for the switch maintains balance, by invoking maintainsBalance.
     *  Checks if the student schedule would be compatible, by invoking scheduleCompatible.
     *
     *  @param request
     *  @return
     */
    bool canSwitchStudent(Request request);

    /** @brief Switch the student from one class to another.
     *
     *  It will invoke canSwitchStudent to ensure that its correspondent criteria are met.
     *
     *  If so, it will add the student to the entry class,
     *  and add the uc and class to the student.
     *
     *  It will then invoke the remove method to effectively
     *  remove the student from the supposed class.
     *
     *  @param request Of the type Request.
     *  @return True if all conditions are satisfied and request granted, False if otherwise.
     */
    bool switchStudent(Request request);

    /** @brief Switch the student from two or more classes to other classes.
     *
     *  It will first check if all the switches are possible,
     *  by invoking canSwitchStudent for every single one.
     *
     *  If so, it will invoke the switch method.
     *  This method will do the switch multiple
     *  times until there are no more changes to process.
     *
     *  @param request Of the type Request.
     *  @return True if all conditions are satisfied for every switch and the request granted, False if otherwise.
     */
    bool multiSwitchStudent(Request request);

    /** @brief Processes all requests.
     *
     * It will process all requests until
     * there are no more in the waiting queue.
     * If the request is not satisfied, it will be added to the rejected queue,
     * otherwise it will be added to the satisfied queue.
     *
     *  @return Void.
     */
    void processRequests();

    /** @brief Add a request to the waiting queue in order to be processed later.
     *
     *  @return Void.
     */
    void addRequest(Request request);

    /** @brief List all rejected requests.
     *
     *  @return Void.
     */
    void listRejectedRequests();

    /** @brief List all satisfied requests.
     *
     *  @return Void.
     */
    void listSatisfiedRequests();

};

/** @brief Check if a lesson overlaps with another.
 *
 *  If one of the two classes type is equal to "T",it will never
 *  overlap, but if it is equal to "TP" or "PL", it can overlap,
 *  based on their day, start hour and duration.
 *
 *  Time Complexity: O(1)
 *
 *  @param l1 Of Lesson type.
 *  @param l2 Of Lesson type.
 *  @return True if the two lessons overlap, False if otherwise.
 */
bool lessonsOverlap(Lesson l1, Lesson l2);


/** @brief Check if the schedule of all the student current classes is compatible with the entry class.
 *
 *  Iterates through all the Student lessons and checks if they overlap,
 *  by calling the lessonsOverlap method.
 *
 *  Time Complexity: O(nmp), in which
 *  n is the number of current classes the student is in,
 *  m is the number of lessons within each of those classes and
 *  p is the number of lessons within the entry class.
 *
 *  @param actualClasses Of type vector<ClassPTR>, represents the classes that belongs to the student before the request.
 *  @param entryClass Of type ClassPTR, holds the class that the student wishes to enter.
 *  @param rejection Of type shared_ptr<string>.
 *  @param exitClassCode Of type string, "null" by default, but if given, represents the code of the class the student will exit.
 *  @return True if the two schedules are compatible, False otherwise.
 */
bool scheduleCompatible(vector<ClassPTR> actualClasses,
                        ClassPTR entryClass, shared_ptr<string> rejection, string exitClassCode = "NULL");


/** @brief Find out what is the maximum balance in each UC.
 *
 *  Finds the maximum and minimum numbers of students in
 *  the classes of the UC given as parameter.
 *  Then determines the maximum imbalance by making the difference
 *  between the maximum and the minimum.
 *
 *  Time Complexity: O(n), in which n is the number of classes within the UC.
 *
 *  @param uc Of type UCPTR.
 *  @return An integer that represents the maximum balance within the UC.
 */
int maxUCinbalance(UCPTR uc);

/** @brief Checks if the balance of UC is held.
 *
 *  Iterates through all the classes of the intended UC and checks, if
 *  all the requests were to take place, the UC would preserve/maintain
 *  its balance, by checking if there is any class along with
 *  the one the student will enter, whose difference
 *  would further unbalance the UC.
 *
 *  Time Complexity: O(n), in which n is the number of classes within the UC.
 *
 *  @param request Of type Request.
 *  @return True if the balance is preserved, False if otherwise.
 */
bool maintainsBalance(Request request);

#endif //AED_FEUP_PROJ_22_23_REQUESTAPPLICATION_H
