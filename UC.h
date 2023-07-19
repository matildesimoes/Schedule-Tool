/** @file UC.h
 *  @brief Contains the UC class declaration.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_UC_H
#define AED_FEUP_PROJ_22_23_UC_H

#include "Class.h"

/** @brief Represents all UCs that belong to the database.
 *
 *  Each UC has a code and a vector of classes.
 */
class UC {
private:

    //! @brief Holds the uc code, that is unique and identifies the uc.
    const string ucCode;

    //! @brief Holds all the classes that belong to UC.
    vector<ClassPTR> classes;
public:

    /** @brief Create a new Student with only code and name.
    *
    * @param ucCode Of type const string.
    */
    UC(const string ucCode);

    /** @brief Add a class to a vector of classes.
     *
     *  @param classe Of type ClassPTR.
     *  @return Void.
     */
    void addClass(ClassPTR classe);

    /** @brief Returns the UC code.
     *
     *  @return string code.
     */
    const string getCode();

    /** @brief Returns the classes of the UC.
     *
     *  @return vector<ClassPTR> classes, by reference.
     */
    vector<ClassPTR>& getClasses();

    /** @brief Returns the UC capacity.
     *
     *  @return classes.size().
     */
    int getOccupation();
};

#endif //AED_FEUP_PROJ_22_23_UC_H
