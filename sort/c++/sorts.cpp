#include "sorts.hpp"
#include <SDL2/SDL.h>

namespace sorts {
    sort::sort(int size, int *arr, int width, int height) : size(size), arr(arr), width(width), height(height) {
        if (SDL_Init(SDL_INIT_VIDEO)) return;
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        barWidth = (float) width / (float) size;
        auto maxI = (float) arr[0];
        for (int i = 1; i<size; i++) {
            if ((float) arr[i] > maxI) {
                maxI = (float) arr[i];
            }
        }
        barHeight = (float) height / maxI;

        update();
        //bubble();
        insertion();
        //selection();

        SDL_Event event;
        while (event.type != SDL_QUIT) {
            SDL_Delay(10);
            SDL_PollEvent(&event);
        }
    }

    sort::~sort() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void sort::update() {
        SDL_Delay(10);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        SDL_Rect rect;
        for (int i = 0; i<size; i++) {
            float x = barWidth*i;
            float y = (float) height-barHeight*(float)arr[i];
            float w = round(barWidth);
            float h = barHeight*(float)arr[i];
            rect = {static_cast<int>(round(x)), static_cast<int>(round(y)), static_cast<int>(round(w)), static_cast<int>(round(h))};
            SDL_RenderFillRect(renderer, &rect);
        }
        SDL_RenderPresent(renderer);
    }


    void sort::swap(int *ptr1, int *ptr2) {
        *ptr1 = *ptr1 + *(ptr2);
        *(ptr2) = *ptr1 - *(ptr2);
        *ptr1 = *ptr1 - *(ptr2);
        update();
    }

    void sort::bubble() {
        bubble(size);
    }

    void sort::bubble(int length) {
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
        update();
        return bubble(length-1);
    }

    void sort::insertion() {
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

    void sort::selection() {
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

