#include "sorts.hpp"

#include <iostream>

int main() {
    int s = 100;
    int arr[s];
    srand(time(nullptr));
    for (int i=0; i<s; i++) {
        arr[i] = rand()%(s*10);
        std::cout<<arr[i]<<" ";
    }

    sorts::sort sort(s, arr, 1600, 900);

    std::cout<<"\n";
    for (int j=0; j<s; j++) {
        std::cout<<arr[j]<<" ";
    }
    return 0;
}


