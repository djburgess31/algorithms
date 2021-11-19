#pragma once

namespace sorts {
    class sortArray {
    public:
        sortArray(int size, int *arr);
        int * bubble();
        int * bubble(int length);

    private:
        int size;
        int *arr;
    };
}
