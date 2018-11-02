#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H


#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::is_sorted;

/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort {
protected:
    
    /** @brief The index of the first element to use */
    int firstElement;
    
    /** @brief The index of the second element to use */
    int secondElement;
    
    /** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
    bool swapThem;
    
public:
    
    /** @brief Default constructor.
     * 
     * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
     * to have an index -1.
     */
    HowToSort() 
      : firstElement(-1),
        secondElement(-1),
        swapThem(false) {
    }
    
    /** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
     * 
     * @param firstElementIn   The first element to use
     * @param secondElementIn  The second element to use
     * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
     */
    HowToSort(const int firstElementIn, const int secondElementIn,
              const bool swapThemIn)
      : firstElement(firstElementIn),
        secondElement(secondElementIn),
        swapThem(swapThemIn) {
    }
    
    /** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
    bool canBeMadeSorted() const {
        return (firstElement != -1);
    }
    
    /** @brief Accessor function -- get the first element to use */
    int getFirstElement() const {
        return firstElement;
    }

    /** @brief Accessor function -- get the second element to use */
    int getSecondElement() const {
        return secondElement;
    }

    /** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
    bool isASwap() const {
        return swapThem;
    }
    
};


HowToSort nearlySorted(vector<int> sortVector) {
    int firstE = 0;
    int secondE = 0;

    if (is_sorted(sortVector.begin(),sortVector.end())){
        return HowToSort(0,0,true);
    }

    //find the first element
    for (int index = 0; index < sortVector.size() - 1; index++){
        if (sortVector[index] > sortVector[index+1]){
            firstE = index;
            break;
        }
    }

    //find the second element
    for (int index = sortVector.size() - 1; index > 1; index--){
        if (sortVector[index] < sortVector[index-1]){
            secondE = index;
            break;
        }
    }

    //try and swap elements
    std::swap(sortVector[firstE], sortVector[secondE]);

    //check if that sorted the vector
    if (is_sorted(sortVector.begin(),sortVector.end())){
        return HowToSort(firstE, secondE, true);
    }
    else {
        // swap elements back
        std::swap(sortVector[firstE], sortVector[secondE]);
    }


    //try and reverse elements
    std::reverse(sortVector.begin() + firstE, sortVector.end() - ((sortVector.size() - 1) - secondE));

    //check if that sorted the vector
    if (is_sorted(sortVector.begin(),sortVector.end())){
        return HowToSort(firstE, secondE, false);
    }
    else {
        // in this case trying to swap or reverse did not work so the vector is not nearly sorted
        return HowToSort();
    }

}



// Don't write any code below this line

#endif
