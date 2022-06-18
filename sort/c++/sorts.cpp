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
        //insertion();
        //shell();
        selection();

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
        SDL_Delay(25);

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
        int nn, i, n = size;
        while (n > 1) {
            nn = 0;
            for (i = 1; i <= n-1; i++) {
                if (arr[i-1] > arr[i]) {
                    swap(&arr[i-1], &arr[i]);
                    nn = i;
                }
            }
            n = nn;
        }
    }

    void sort::insertion() {
        int j, x;
        for (int i=1; i<size; i++) {
            x = arr[i];
            for (j=i-1; j>=0 && arr[j] > x; j--) {
                arr[j+1] = arr[j];
                update();
            }
            arr[j+1] = x;
            update();
        }
    }

    void sort::shell() {
        int gaps[] = {50, 25, 12, 6, 3, 1};

        for (int gap : gaps) {
            for (int j=gap; j<size; j++) {
                int tmp = arr[j];

                int k;
                for (k=j; k >= gap && arr[k-gap] > tmp; k-=gap) {
                    arr[k] = arr[k-gap];
                    update();
                }
                arr[k] = tmp;

            }
        }
    }

    void sort::selection() {
        int *min = &arr[0];

        for (int i=0; i<size-1; i++) {
            for (int j=1; j<size-i; j++) {
                if (arr[i + j] < *min) {
                    min = &arr[i+j];
                }
            }
            if (arr[i] != *min) {
                swap(&arr[i], min);
            }
            min = &arr[i+1];
        }
    }
}

