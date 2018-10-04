#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {

private:
    SimpleVector<char> cBuffer;
    int counter;
    int addPosition;
    int removePosition;


public:

    CircularBuffer(int size)
        : cBuffer(size), addPosition(0), removePosition(0), counter(0)
    {}

    int count(){
        return counter;
    }

    bool full(){
        if (counter == cBuffer.size()){
            return true;
        }
        else {
            return false;
        }
    }

    void add(char element){
        if (addPosition == cBuffer.size()){
            addPosition = 0;
        }

        cBuffer[addPosition] = element;

        counter++;
        addPosition++;
    }

    char remove(){
        if (removePosition == cBuffer.size()){
            removePosition = 0;
        }


        char removed = cBuffer[removePosition];

        counter--;
        removePosition++;
        return removed;
        
    }

};


// don't write any code below this line

#endif
