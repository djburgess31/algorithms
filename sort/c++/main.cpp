#include "sorts.hpp"

#include <iostream>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    sorts::sortArray sort(n, arr);
    int *pnarr = sort.bubble();
    std::cout << n << std::endl;
    for (int i=0; i < n; i++) {
        std::cout << pnarr[i] << "  ";
    }
    return 0;
}


