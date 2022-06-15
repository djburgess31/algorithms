#include "sorts.hpp"

#include <iostream>

int main() {
    int s = 200;
    int arr[s];
    srand(time(nullptr));
    for (int i=0; i<s; i++) {
        arr[i] = rand()%(s*10);
        std::cout<<arr[i]<<" ";
    }
    //int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sorts::sort sort(n, arr, 1600, 900);
    return 0;
}


