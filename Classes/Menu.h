/** @file Menu.h
 *  @brief Contains the Menu class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_MENU_H
#define AED_FEUP_PROJ_22_23_MENU_H

#include <string>
#include "ListingApplication.h"

using namespace std;
/** @brief Holds all the displayable menus for the Application.
 *
 * Intended to be instanced once.
 */
class Menu {

public:

    //! @brief Defines the string to output in the menu, as an option, for the schedule lists.
    static const string SCHEDULE_LISTS;

    //! @brief Defines the string to output in the menu, as an option, for the schedule changes.
    static const string SCHEDULE_CHANGES;

    //! @brief Defines the string to output in the menu, as an option, for the student managing.
    static const string MANAGE_STUDENTS;

    //! @brief Defines the string to output in the menu, as an option, to show student schedule.
    static const string STUDENT_SCHEDULE;

    //! @brief Defines the string to output in the menu, as an option, to export the alterations.
    static const string EXPORT_ALTERATIONS;

    //! @brief Defines the string to output in the menu, as an option, to quit the application.
    static const string QUIT_APPLICATION;

    //! @brief Defines the string to output in the menu, as an option, to go back.
    static const string GO_BACK;

    //! @brief Defines the string to output in the menu, as a message, as a quit message.
    static const string QUIT_MESSAGE;

    //! @brief Defines the string to output in the menu, as a message, for invalid inputs.
    static const string INVALID_INPUT;

    //! @brief Defines the string to output in the menu, as a message, for wrong inputs.
    static const string WRONG_INPUT;

    //! @brief Defines the string to output in the menu, as a message, for wrong input usage.
    static const string WRONG_USAGE_INPUT;



    //! @brief Defines the string to output in the menu, as an option, to show the students occupation.
    static const string BY_OCCUPATION;

    //! @brief Defines the string to output in the menu, as an option, to show the students lists.
    static const string BY_LISTS;

    //! @brief Defines the string to output in the menu, as an option, to show the sort options.
    static const string SORT_OPTIONS;



    //! @brief Defines the string to output in the menu, as an option, to show a class occupation.
    static const string OCCUPATION_BY_CLASS;

    //! @brief Defines the string to output in the menu, as an option, to show a UC occupation.
    static const string OCCUPATION_BY_UC;

    //! @brief Defines the string to output in the menu, as an option, to show a year occupation.
    static const string OCCUPATION_BY_YEAR;



    //! @brief Defines the string to output in the menu, as an option, to list students per classes.
    static const string STUD_BY_CLASS;

    //! @brief Defines the string to output in the menu, as an option, to list students per UCs.
    static const string STUD_BY_UC;

    //! @brief Defines the string to output in the menu, as an option, to list students per year.
    static const string STUD_BY_YEAR;

    //! @brief Defines the string to output in the menu, as an option, to list all students.
    static const string ALL_STUD;

    //! @brief Defines the string to output in the menu, as an option, to list classes per uc.
    static const string CLASS_BY_UC;

    //! @brief Defines the string to output in the menu, as an option, to list all ucs.
    static const string ALL_UC;


    //! @brief Defines the string to output in the menu, as an option, to create the request.
    static const string CREATE_REQUEST;

    //! @brief Defines the string to output in the menu, as an option, to process the request.
    static const string PROCESS_REQUESTS;

    //! @brief Defines the string to output in the menu, as an option, to pending the request.
    static const string PENDING_REQUESTS;

    //! @brief Defines the string to output in the menu, as an option, to reject the request.
    static const string REJECTED_REQUESTS;

    //! @brief Defines the string to output in the menu, as an option, to satisfy the request.
    static const string SATISFIED_REQUESTS;



    //! @brief Defines the string to output in the menu, as an option, for student leave the class.
    static const string LEAVE_CLASS;

    //! @brief Defines the string to output in the menu, as an option, for student entry the class.
    static const string ENTRY_CLASS;

    //! @brief Defines the string to output in the menu, as an option, for student switch the class.
    static const string SWITCH_CLASS;

    //! @brief Defines the string to output in the menu, as an option, for student do multiple switches.
    static const string MULTI_SWITCH_CLASS;



    //! @brief Defines the string to output in the menu, as an option, to sort by ascending order.
    static const string ASCENDING;

    //! @brief Defines the string to output in the menu, as an option, to sort by descending order.
    static const string DESCENDING;

    //! @brief Defines the string to output in the menu, as an option, to show the criteria to sort.
    static const string SORT_CRITERIA;

    //! @brief Defines the string to output in the menu, as an option, to add a student.
    static const string ADD_STU;

    //! @brief Defines the string to output in the menu, as an option, to change a student name.
    static const string CHANGE_STU_NAME;

    //! @brief Defines the string to output in the menu, as an option, to change a student code.
    static const string CHANGE_STU_CODE;

    //! @brief Defines the string to output in the menu, as an option, to delete a student.
    static const string DELETE_STU;

    //! @brief Does nothing.
    Menu();

    /** @brief Shows a message when user write a wrong input.
     *
     * @return Void.
     */
    void getWrongMessage();

    /** @brief Shows a message when user write an invalid input.
     *
     * @return Void.
     */
    void getInvalidMessage();

    /** @brief Displays the start menu.
     *
     * @return Void.
     */
    void startMenu();

    /** @brief Displays the main menu.
     *
     * @return Void.
     */
    void displayMenu();

    /** @brief Displays the menu with search information.
     *
     * @return Void.
     */
    void displaySearchInfoMenu();

    /** @brief Make a break line.
     *
     * @return Void.
     */
    void breakLine();

    /** @brief Displays the menu with occupation information.
     *
     * @return Void.
     */
    void displayOccupationMenu();

    /** @brief Displays the menu with listing information.
     *
     * @return Void.
     */
    void displayListsMenu();

    /** @brief Displays the menu with request information.
     *
     * @return Void.
     */
    void displayRequestMenu();

    /** @brief Displays the menu to create a request.
     *
     * @return Void.
     */
    void displayCreateRequestMenu();

    /** @brief Displays the menu with sorting information.
     *
     * @param sorterPtr, to display the current state of the application Sorter.
     * @return Void.
     */
    void displaySorterMenu(SorterPTR sorterPtr);

    /** @brief Displays the menu to choose the sorting criteria.
     *
     * @param sorterPtr, to display the current state of the application Sorter.
     * @return Void.
     */
    void displaySorterCriteriaMenu(SorterPTR sorterPtr);

    /** @brief Displays the menu to choose the UC sorting criteria.
     *
     * @param sorterPtr, to display the current state of the application Sorter.
     * @return Void.
     */
    void displayUcSortOptions(SorterPTR sorterPtr);

    /** @brief Displays the menu to choose the class sorting criteria.
     *
     * @param sorterPtr, to display the current state of the application Sorter.
     * @return Void.
     */
    void displayClassSortOptions(SorterPTR sorterPtr);

    /** @brief Displays the menu to choose the student sorting criteria.
     *
     * @param sorterPtr, to display the current state of the application Sorter.
     * @return Void.
     */
    void displayStudentSortOptions(SorterPTR sorterPtr);

    /** @brief Displays the menu with student managing options.
     *
     * @return Void.
     */
    void displayStudentManagementMenu();
};


#endif //AED_FEUP_PROJ_22_23_MENU_H
