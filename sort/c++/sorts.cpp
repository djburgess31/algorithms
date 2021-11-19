#include "sorts.hpp"

namespace sorts {
    sortArray::sortArray(int size, int *arr) : size(size), arr(arr){}

    void sortArray::bubble() {
        bubble(size);
    }

    void sortArray::bubble(int length) {
        if (length < 2) {
            return;
        }
        int *ptr = arr;
        for (int i=0; i<size-1; i++) {
            if(*ptr > *(ptr+1)) {
                *ptr = *ptr + *(ptr+1);
                *(ptr+1) = *ptr - *(ptr+1);
                *ptr = *ptr - *(ptr+1);
            }
            ptr++;
        }
        return bubble(length-1);
    }

    void sortArray::insertion() {
        int *ptr = arr;

        for (int i=0; i<size; i++) {
            if(*ptr > *(ptr+1)) {
                *ptr = *ptr + *(ptr+1);
                *(ptr+1) = *ptr - *(ptr+1);
                *ptr = *ptr - *(ptr+1);
            }
            ptr++;
        }
    }
}

