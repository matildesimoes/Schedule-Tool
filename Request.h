/** @file Request.h
 *  @brief Contains the Request class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_REQUEST_H
#define AED_FEUP_PROJ_22_23_REQUEST_H

#include "Student.h"
#include <list>
#include "UC.h"
#include "Searcher.h"

//! @brief Creates different types for the requests.
enum requestType {REMOVE, ADD, SWITCH, MULTI_SWITCH};

/** @brief It represents a request.
 *
 */
class Request {

    //! @brief Holds the count of the number of requests made.
    static int count;

    //! @brief Represent the request id.
    int id;

    //! @brief Type of request (REMOVE, ADD, SWITCH OR MULTI_SWITCH).
    requestType type;

    //! @brief Pointer to student target of the request.
    StudentPTR studentPtr;

    //! @brief Retrieves the original code from the user input.
    string providedCode;

    //! @brief Classes the student wants to leave(may only take 1 argument for REMOVE/SWITCH type).
    list<ClassPTR> exitClasses;

    //! @brief Classes the student wants to join(may only take 1 argument for ADD/SWITCH type).
    list<ClassPTR> entryClasses;

    //! @brief UCs the student wants to join(may only take 1 argument for ADD/SWITCH type).
    list<UCPTR> ucs;

    //! @brief Makes rejectionState default by false.
    bool rejectionState = false;

    //! @brief  Initializes an allocated empty string and sets it to this shared pointer.
    shared_ptr<string> rejectionReason = make_shared<string>("");

public:

    /** @brief Creates a request for a student and of certain type.
     *
     * Classes should be added along with the corresponding methods.
     *
     * @param type Of type requestType.
     * @param studentPtr Of type StudentPTR.
     */
    Request(requestType type, StudentPTR studentPtr, string providedCode);

    /** @brief Returns the id of the request.
     *
     * @return number of the id.
     */
    int getID();

    /** @brief Adds to both lists the corresponding classes the student pretends to switch.
     *
     * Only works for requests of type SWITCH (can only be used once)
     * or MULTI_SWITCH (may be used multiple times).
     *
     * @param entryClass Of type ClassPTR.
     * @param exitClass Of type ClassPTR.
     * @param uc Of type UCPTR.
     * @return False if any of these constraints are disrespected, True if otherwise.
     */
     bool addSwitchClasses(ClassPTR entryClass, ClassPTR exitClass, UCPTR uc);

    /** @brief Adds to the exit list the class the student pretends to leave.
     *
     * @param exitClass Of type ClassPTR.
     * @param uc Of type UCPTR.
     * @return False if any of these constraints are disrespected, True if otherwise.
     */
    bool addExitClass(ClassPTR exitClass, UCPTR uc);

    /** @brief Adds to the entry list the class the student pretends to join.
     *
     * This method may only be used once and for requests of type ADD.
     *
     * @param entryClass Of type ClassPTR.
     * @param uc Of type UCPTR.
     * @return False if any of these constraints are disrespected, True if otherwise.
     */
    bool addEntryClass(ClassPTR entryClass, UCPTR uc);

    /** @brief Returns the StudentPTR.
     *
     * @return StudentPtr.
     */
    StudentPTR getStudent();

    /** @brief Returns the list of UCs.
     *
     * @return ucs of type list<UCPTR>, by reference.
     */
    list<UCPTR>& getUCs();

    /** @brief Returns the list of exit classes.
     *
     * @return classes of type list<ClassPTR>, by reference.
     */
    list<ClassPTR>& getExitClasses();

    /** @brief Returns the list of entry classes.
     *
     * @return classes of type list<ClassPTR>, by reference.
     */
    list<ClassPTR>& getEntryClasses();

    /** @brief Returns the request type.
     *
     * @return requestType.
     */
    requestType getType();

    /** @brief Erase the first element of exit classes, entry classes and ucs list.
     *
     * @return Void.
     */
    void popFront();

    /** @brief Shows if request is rejected or not.
     *
     * @return rejectedState.
     */
    bool rejected();

    /** @brief Makes rejectedState equals to true.
     *
     * @return Void.
     */
    void setToRejected();

    /** @brief Returns the reason why the request was rejected.
     *
     * If the request was not rejected, the reason is an empty string.
     *
     * @return rejectionReason string.
     */
    string getReason();

    /** @brief Returns the pointer to the rejectionReason string.
     *
     * @return rejectionReason of type shared_ptr<string>, by reference.
     */
    shared_ptr<string>& getReasonPTR();

    /** @brief Makes rejectionReason equals to reason.
     *
     * @param reason Of type string.
     * @return Void.
     */
    void setReason(string reason);

    /** @brief Returns providedCode.
     *
     * @return providedCode string.
     */
    string getProvidedCode();

    /** @brief Verifies if all the given codes are valid and determines the early rejection of the request.
     *
     * @param searcher Of type SearcherPTR.
     * @return True if all information is valid, False if otherwise.
     */
    bool dataChecksUp(SearcherPTR searcher);
};

/** @brief Defines how to std::cout a request.
 *
 * @param os Of type ostream, by reference.
 * @param request Of type Request.
 * @return ostream, by reference.
 */
ostream& operator<<(ostream& os, Request request);

#endif //AED_FEUP_PROJ_22_23_REQUEST_H
