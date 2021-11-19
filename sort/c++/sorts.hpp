#pragma once

namespace sorts {
    class sortArray {
    public:
        sortArray(int size, int *arr);
        void bubble();
        void bubble(int length);
        int * insertion();

    private:
        int size;
        int *arr;
    };
}
