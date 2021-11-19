#include "sorts.hpp"

namespace sorts {
    sortArray::sortArray(int size, int *arr) : size(size), arr(arr){}

    int *sortArray::bubble() {
        bubble(size);
    }

    int *sortArray::bubble(int length) {
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
            return arr;
        }
        return bubble(length-1);
    }
}

