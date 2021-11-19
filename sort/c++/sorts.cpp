#include "sorts.hpp"

namespace sorts {
    sortArray::sortArray(int size, int *arr) : size(size), arr(arr){}

    void sortArray::bubble() {
        bubble(size);
    }

    void sortArray::bubble(int length) {
        int *ptr = arr;
        for (int i=0; i<size; i++) {
            if(*ptr > *(ptr+1)) {
                *ptr = *ptr + *(ptr+1);
                *(ptr+1) = *ptr - *(ptr+1);
                *ptr = *ptr - *(ptr+1);
            }
            ptr++;
        }
        if (length < 2) {
            return;
        }
        return bubble(length-1);
    }

    int *sortArray::insertion() {

        return arr;
    }
}

