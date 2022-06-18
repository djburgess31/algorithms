#pragma once
#include <SDL2/SDL.h>

namespace sorts {
    class sort {
    public:
        sort(int size, int *arr, int width, int height);
        ~sort();
        void init(int size, int *arr);
        void update();
        void swap(int *ptr1, int *ptr2);
        void bubble();
        void bubble(int length);
        void insertion();
        void shell();
        void selection();
        void quicksort();
        void quicksort(int lo, int hi);
        int hoarePartition(int lo, int hi);

    private:
        int size;
        int *arr;
        int height;
        int width;
        SDL_Renderer *renderer{};
        SDL_Window *window{};
        float barWidth;
        float barHeight;
    };
}
