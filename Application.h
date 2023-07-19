/** @file Application.h
 *  @brief Contains the Application class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_APPLICATION_H
#define AED_FEUP_PROJ_22_23_APPLICATION_H

#include "ListingApplication.h"
#include "Menu.h"
#include "DataBase.h"
#include "RequestApplication.h"
#include "Schedule.h"
#include "Searcher.h"
#include "Sorter.h"
#include <string>
#include <iostream>

/** @brief Initializes and manages all the components of the application.
 *
 * Intended to be instanced once.
 * Manages the interaction between the user and the application.
 */
class Application {
private:

    //! @brief Creates the initial menu options.
    enum {
        LISTS = 1,
        OCCUPATION = 2,
        CHANGES = 2,
        SORT = 3,
        MANAGE_STUDENTS = 3,
        SHOWCASE_SCHEDULE = 4,
        EXPORT_ALTERATIONS = 5,
        QUIT = 9
    };

    //! @brief Creates the occupation and lists menu options.
    enum {
        STUD_BY_CLASS = 1, STUD_BY_UC = 2, STUD_BY_YEAR = 3, ALL_STUD = 4, CLASS_BY_UC = 5, ALL_UCS = 6
    };

    //! @brief Creates the request options.
    enum {
        TO_REMOVE = 1, TO_ADD = 2, TO_SWITCH = 3, TO_MULTIPLE_SWITCH = 4
    };

    //! @brief Creates criteria to manage requests options.
    enum {
        CREATE_REQUEST = 1, PROCESS_REQUESTS = 2, REJECTED_REQUESTS = 3, SATISFIED_REQUESTS = 4
    };

    //! @brief Creates the sort options.
    enum {
        ASCENDING = 1, DESCENDING = 2, CRITERIA = 3
    };

    //! @brief Creates the sort criteria options.
    enum {
        SORT_UC = 1, SORT_CLASS = 2, SORT_STUDENT = 3
    };

    //! @brief Creates the student management options.
    enum {
        ADD_STU = 1, CHANGE_CODE = 2, CHANGE_NAME = 3, DELETE_STU = 4
    };

    //! @brief Pointer to the DataBase and its initialization in memory.
    DataBasePTR dataBasePtr = DataBasePTR(new DataBase());

    //! @brief Initialization of the Searcher.
    SearcherPTR searcherPtr = SearcherPTR(new Searcher(dataBasePtr));

    //! @brief Initialization of the Request Application.
    RequestApplication requestApp = RequestApplication(searcherPtr);

    //! @brief Pointer to the Sorter and its initialization in memory.
    SorterPTR sorterPtr = SorterPTR(new Sorter());

    //! @brief Initialization of the Schedule Application.
    ListingApplication scheduleApp = ListingApplication(dataBasePtr, sorterPtr, searcherPtr);

    //! @brief Initialization of the menu.
    Menu menu;

    /** @brief Starts the menu.
     *
     * @return Void.
     */
    void startMenu();

    /** @brief Covers wrong inputs in the menu.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void safeInput(string &option, int &safeOption);

    /** @brief Display the menu if the menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void menuSafety(string &option, int &safeOption);

    /** @brief Display the listing menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void listMenuSafety(string &option, int &safeOption);

    /** @brief Display the occupation menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void occupationSafety(string &option, int &safeOption);

    /** @brief Display the request menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void requestSafety(string &option, int &safeOption);

    /** @brief Display the create request menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void createRequestSafety(string &option, int &safeOption);

    /** @brief Display the sort menu if the given menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void sortSafety(string &option, int &safeOption);

    /** @brief Display the sort by criteria menu if the menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void sortCriteriaSafety(string &option, int &safeOption);

    /** @brief Display the student management menu if the menu option is correct.
     *
     * Checks if the safeOption argument is correct for that specific menu.
     * Then, safeInput method is used with both arguments to cover wrong inputs.
     *
     * @param option Of type string, by reference.
     * @param safeOption Of type int, by reference.
     * @return Void.
     */
    void studentsSafety(string &option, int &safeOption);

    /** @brief Reads what the user wants to know the occupation of and shows it.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * @param oldOption Of type string, by reference.
     * @return Void.
     */
    void occupationMenu(int &oldOption);

    /** @brief Reads what the user wants to get the listing of and shows it.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void listsMenu(int &oldOption);

    /** @brief Reads the sorting option the user wants to change.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void sortMenu(int &oldOption);

    /** @brief Reads what unit the user wants to change the criteria of and changes it.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void sortCriteriaMenu(int &oldOption);

    /** @brief Reads the request option the user wants to add.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void requestMenu(int &oldOption);

    /** @brief Reads the request creation option the user wants to add.
     *
     * The oldOption argument is used to take control of the menu before the method is called.
     * So it is possible to know where to return and which menu to display.
     *
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void createRequestMenu(int &oldOption);

    /** @brief Filters through multiple menu options based on argument value.
     *
     * @param oldOption Of type int, by reference.
     * @return Void.
     */
    void optionFilter(int &option);

    /** @brief Main menu that will be the root to reach all other menus.
     *
     * Menu responsible for displaying all other menus depending on user interaction,
     * and where it is possible to exit the application successfully.
     * Using a switch with a while, allows the user to interact with a less interactive,
     * and each case of the switch is a new possibility of interaction.
     *
     * @return Void.
     */
    void displayMenu();

    /** @brief Displays the student management menu and allows the user to make changes to students in the database.
     *
     * The user may add or delete a student or change one's name or code
     *
     * @param option Of type int, by reference.
     * @return Void.
     */
    void studentsMenu(int &option);

public:

    //! @brief Does nothing.
    Application();

    /** @brief Starts the application.
     *
     * @return Void.
     */
    void startApplication();
};

/** @brief Checks if a string represents a number.
 *
 * @return True if the string represents a number, false if otherwise.
 */
bool is_number(const std::string& s);


/** @brief Reads user input until it its a valid numeric value.
 *
 * @return User input of string type.
 */
string validStudentCode();


#endif //AED_FEUP_PROJ_22_23_APPLICATION_H
