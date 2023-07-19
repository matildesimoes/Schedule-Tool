/** @file QuickSort.h
 *  @brief Contains the QuickSort template implementation.
 *  @author -
 *  @bug No known bugs.
 */

#ifndef AED_FEUP_PROJ_22_23_QUICKSORT_H
#define AED_FEUP_PROJ_22_23_QUICKSORT_H
#include <vector>

using namespace std;


bool compare(UCPTR uc1, UCPTR uc2);
bool compare(ClassPTR class1, ClassPTR class2);
bool compare(StudentPTR student1, StudentPTR student2);

/** @brief Insertion Sort implementation.
 *
 *  Temporal Complexity: O(n^2), in which n is the number of elements in the given vector.
 *
 *  Insert each element in the correct position.
 *  The vector is divided into two sub-vectors (left and right),
 *  the left sub-vector is ordered and the right sub-vector is unordered
 *  and moves one element at a time from the right sub-vector to the left sub-vector,
 *  placing it in the correct position to keep the left sub-vector sorted.
 *
 * @tparam PTR Intended to be either a UCPTR, ClassPTR or StudentPTR.
 * @param v Of type vector<PTR>.
 * @param left Of type int.
 * @param right Of type int.
 */
template <class PTR>
void insertionSort(vector<PTR> &v, int left, int right) {
    for (unsigned p = left + 1; p <= right; p++) {
        PTR tmp = v[p];
        unsigned j;
        for (j = p; j > left && compare(tmp , v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}
/** @brief Choose what element is better to pivot and puts the pivot in the end of the vector.
 *
 * Temporal Complexity: O(1), in which n is the number of elements in the given vector.
 *
 * @tparam PTR Intended to be either a UCPTR, ClassPTR or StudentPTR.
 * @param v Of type vector<PTR>.
 * @param left Of type int.
 * @param right Of type int.
 * @return Element of type PTR.
 */
template <class PTR>
const PTR &median3(vector<PTR> &v, int left, int right){
    int center = (left+right) /2;

    if (compare(v[center], v[left]))
        swap(v[left], v[center]);

    if (compare(v[right], v[left]))
        swap(v[left], v[right]);

    if (compare(v[right], v[center]))
        swap(v[center], v[right]);

    swap(v[center], v[right-1]);
    return v[right-1];
}

/** @brief Quick Sort implementation.
 *
 * Temporal Complexity: O(n log(n)), in which n is the number of elements in the given vector.
 *
 * Partition according to a pivot.
 * If the number of elements is too small, it will invoke insertionSort.
 * It will invoke median3 to choose the pivot.
 * An then, it will break the initial vector into two sub-vectors
 * (left and right), with <= x values in the left sub-vector and
 * >= x values in the right sub-vector. It will sort the left and
 * right sub-vectors using the same method recursively.
 *
 * @tparam PTR Intended to be either a UCPTR, ClassPTR or StudentPTR.
 * @param v Of type vector<PTR>, by reference.
 * @param left Of type int.
 * @param right Of type int.
 */
template <class PTR>
void quickSort(vector<PTR> &v, int left, int right){
    if (right-left <= 10)
        insertionSort(v, left, right);
    else {
        PTR x = median3(v, left, right);
        int i = left; int j = right-1;
        for(; ; ) {
            while (compare(v[++i] , x));
            while (compare(x, v[--j]));
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right - 1]);
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

#endif //AED_FEUP_PROJ_22_23_QUICKSORT_H
