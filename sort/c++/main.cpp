#include "sorts.hpp"

#include <iostream>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    sorts::sortArray sort(n, arr);
    sort.bubble();
    for (int i=0; i < n; i++) {
        std::cout << arr[i] << "  ";
    }
    return 0;
}


