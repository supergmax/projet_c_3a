#include <SDL.h>
#include <stdio.h>

void drawButton(SDL_Renderer *renderer, int x, int y, int w, int h, const char *text) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    int tx, ty;
    TTF_SizeText(font, text, &tx, &ty);
    SDL_Rect textRect = {x + (w - tx) / 2, y + (h - ty) / 2, tx, ty};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("Helloworld", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    TTF_Font *font = TTF_OpenFont("path/to/font.ttf", 32);
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Hello", {0, 0, 0, 255});
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        int i, j;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                drawButton(renderer, 200 + j * 200, 200 + i * 200, 180, 80, "Button");
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}