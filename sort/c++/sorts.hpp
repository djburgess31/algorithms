#pragma once

namespace sorts {
    class sortArray {
    public:
        sortArray(int size, int *arr);
        void bubble();
        void bubble(int length);
        void insertion();

    private:
        int size;
        int *arr;
    };
}
