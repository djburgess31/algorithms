#include "sorts.hpp"
#include <iostream>

namespace sorts {
    sortArray::sortArray(int size, int *arr) : size(size), arr(arr){}

    void swap(int *ptr1, int *ptr2) {
        *ptr1 = *ptr1 + *(ptr2);
        *(ptr2) = *ptr1 - *(ptr2);
        *ptr1 = *ptr1 - *(ptr2);
    }

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
                swap(ptr, ptr+1);
            }
            ptr++;
        }
        return bubble(length-1);
    }

    void sortArray::insertion() {
        int *ptr = arr;

        for (int i=0; i<size-1; i++) {
            if(*ptr > *(ptr+1)) {
                swap(ptr, ptr+1);
                for (int j=0; j<i; j++){
                    if (*(ptr-j) < *(ptr-1-j)) {
                        swap(ptr-j, ptr-1-j);
                    }
                    else {
                        break;
                    }
                }
            }
            ptr++;
        }
    }

    void sortArray::selection() {
        int *min = arr;

        for (int i=0; i<size-1; i++) {
            for (int j=1; j<size-i; j++) {
                if (*(arr+i + j) < *min) {
                    min = arr+i+j;
                }
            }
            if (arr+i != min) {
                swap(arr+i, min);
            }
            min = arr+i+1;
        }
    }
}

