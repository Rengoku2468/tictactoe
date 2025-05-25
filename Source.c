#define SDL_MAIN_HANDLED  // Prevents SDL from redefining the main function
#include <SDL2/SDL.h>
#include <stdio.h>

int main(void) {
    SDL_Window* window;
    SDL_Cursor* cursor;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "my window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600, 600,
        0
    );
    renderer = SDL_CreateRenderer(window,
        -1, SDL_RENDERER_ACCELERATED);
    int done = 0;
    SDL_Event event;
    while (!done)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_WINDOWEVENT_CLOSE: {
                if (window)
                {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
                break;
            }
                                      break;
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 1;
                    break;
                }
            }
                            break;
            case SDL_QUIT: {
                done = 1;
                break;
            }
            }
        }

        SDL_SetRenderDrawColor(renderer,
            255, 255, 255,
            255);//set renderer color to white
        SDL_RenderClear(renderer);//make the window background (white)
        SDL_SetRenderDrawColor(renderer,
            0, 0, 0,
            255);//renderer color for the grid of the tictactoe (black)
        SDL_RenderDrawLine(renderer,
            200, 0, 200, 600);
        SDL_RenderDrawLine(renderer,
            400, 0, 400, 600);
        SDL_RenderDrawLine(renderer,
            0, 200, 600, 200);
        SDL_RenderDrawLine(renderer,
            0, 400, 600, 400);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}