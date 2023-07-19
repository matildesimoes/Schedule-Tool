/** @file DataBase.h
 *  @brief Contains the DataBase class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_DATABASE_H
#define AED_FEUP_PROJ_22_23_DATABASE_H

#include "UC.h"
#include <set>
#include <algorithm>

/** @brief Database class to read all input files and store all information.
 *
 *  Intended to be instanced once and creates a database
 *  for use within the app.
 *  Holds prototype functions to read the following input files:
 *  "classes.csv", "classes_per_uc.csv" and "student_classes.csv".
 *  And stores their data accordingly.
 */
class DataBase {

private:

    //! @brief Holds all UC objects.
    vector<UCPTR> ucs;

    //! @brief Holds all students within the database through StudentPTRs.
    set<StudentPTR> students;

    /** @brief Reads student input files and stores them accordingly.
     *
     *  Reads the "student_classes.csv" file
     *  and for each line it reads the student
     *  name and code, class code and UC code.
     *  If code is new to the database, a new
     *  Student object will be created within
     *  a StudentPTR object. The StudentPTR will
     *  then be added to the set of students.
     *  However, if there's already a student stored
     *  in the database with the same code, it will
     *  add the read class and UC to the corresponding student.
     *
     *  @return Void.
     */
    void readStudents();

    /** @brief Reads lessons input file and stores them accordingly.
     *
     *  Reads the classes_per_uc.csv file
     *  and for each line it reads class code, UC code
     *  and it's lesson info(day, start hour and duration).
     *  The corresponding class is found within the
     *  corresponding UC and a Lesson object is then
     *  created and added to it.
     *
     *  @return Void.
     */
    void readLessons();

    /** @brief Reads UCs and classes input file and stores them accordingly.
     *
     *  Reads the file "classes_per_uc.csv" and for each line
     *  it read a UC code and a class code.
     *  If the UC code corresponds to a new UC, it creates
     *  a new UC object and adds it to the vector of UCs.
     *  With each class code read, a new class is added to the
     *  vector of classes with the UC mentioned in the same line.
     *
     *  @return Void.
     */
    void readUCsAndClasses();

    /** @brief Sorts the entire database.
     *
     * Sorts the ucs, classes in each ucs and the students and lessons in each class.
     *
     * @return Void.
     */
    void sort();

    /** @brief Creates the "student_classes.csv" file in a similar fashion of the input one.
     *
     * Per line, it writes the StudentCode, StudentName, UcCode and ClassCode.
     *
     * @return Void.
     */
    void createStudentClasses_CSV();

    /** @brief Creates the "classes.csv" file in a similar fashion of the input one.
     *
     * Per line, it writes the ClassCode, UcCode, Weekday, StartHour, Duration and Type.
     *
     * @return Void.
     */
    void createClasse_CSV();

    /** @brief Creates the "classes_per_uc.csv" file in a similar fashion of the input one.
     *
     * Per line, it writes the UcCode and the ClassCode.
     *
     * @return Void.
     */
    void createClassePerUC_CSV();

public:

    /** @brief Does nothing.
     *
     */
    DataBase();

    /** @brief Returns the vector of UCs.
     *
     * @return vector<UC> ucs, by reference.
     */
    vector<UCPTR>& getUCs();

    /** @brief Returns the set of StudentPTR.
     *
     * @return set<StudentPTR> students, by reference.
     */
    set<StudentPTR>& getStudents();

    /** @brief Stores all the information of the database.
     *
     * It invoke readUCsAndClasses, readLessons, readStudents methods to store the data.
     * It then invoke the sort method to sort the ucs,
     * classes in each ucs and the students in each class.
     *
     * @return Void.
     */
    void read();

    /** @brief Creates all the files to store the most recent database.
     *
     * It invoke createClassePerUC_CSV, createStudentClasses_CSV, createClasse_CSV methods.
     * Saves all the files in the "OutputFiles" directory.
     *
     * @return Void.
     */
    void store();

    /** @brief Adds the student to the set of students.
     *
     * @param code Of type string.
     * @param name Of type string.
     * @return True if it was able to add the new student, false if otehrwise.
     */
    bool addStudent(string code, string name);

    /** @brief Finds the lower bound of a StudentPTR.
     *
     * @param code Of type string.
     * @return
     */
    set<StudentPTR>::iterator lowerBound(string code);

    /** @brief Delete students from the database.
     *
     * If a students is not found, it is not deleted.
     *
     * @param code Of type string.
     * @return True if a student is found with the code provided, false if otherwise.
     */
    bool removeStudent(string code);

    /** @brief Changes the name of a student.
     *
     * If a students is not found, the name is not changed.
     *
     * @param code Of type string, used to find the student.
     * @param newName Of type string.
     * @return True if a student is found with the code provided, false if otherwise.
     */
    bool changeStudentName(string code, string newName);

    /** @brief Changes the code of the student using the newCode.
     *
     * If a students is not found, the code is not changed.
     * This method works by "copying" and then deleting the student found.
     * The copy is equal to the previous student but is created with the new name.
     * The copy is then inserted into the set of students.
     *
     * @param code Of type string, used to find the student.
     * @param newCode Of type string.
     * @return True if a student is found with the code provided, false if otherwise.
     */
    bool changeStudentCode(string code, string newCode);
};

#endif //AED_FEUP_PROJ_22_23_DATABASE_H
