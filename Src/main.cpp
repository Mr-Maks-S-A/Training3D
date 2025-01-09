#define SDL_MAIN_USE_CALLBACKS /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
// #include <SDL3_image/SDL_image.h>

#include <config.hpp>
#include <iostream>
#include <string_view>

#define SDL_WINDOW_WIDTH 1024
#define SDL_WINDOW_HEIGHT 700

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
} AppState;


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  switch (event->type) {
    case SDL_EVENT_QUIT:
      return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
      // return handle_key_event_(ctx, event->key.scancode);
      break;
  };
  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
  AppState *as = (AppState *) appstate;
  const Uint64 now = SDL_GetTicks();
  SDL_FRect r;
  r.h = 300;
  r.w = 300;
  r.x = 0;
  r.y = 0;


  SDL_SetRenderDrawColor(as->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(as->renderer);

  SDL_SetRenderDrawColor(as->renderer, 255, 255, 0, SDL_ALPHA_OPAQUE); /*head*/
  SDL_RenderFillRect(as->renderer, &r);
  SDL_RenderPresent(as->renderer);
  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
  if (!SDL_SetAppMetadata(std::string(extended_metadata[0].m_value).c_str(),
                          std::string(extended_metadata[1].m_value).c_str(),
                          std::string(extended_metadata[2].m_value).c_str())) {
    return SDL_APP_FAILURE;
  }

  for (size_t i = 0; i < SDL_arraysize(extended_metadata); ++i) {
    if (!SDL_SetAppMetadataProperty(std::string(extended_metadata[i].m_key).c_str(),
                                    std::string(extended_metadata[i].m_value).c_str())) {
      return SDL_APP_FAILURE;
    }
  }

  AppState *as = new AppState;
  if (!as) {
    return SDL_APP_FAILURE;
  } else {
    *appstate = as;
  }

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer(std::string(extended_metadata[0].m_value).c_str(), SDL_WINDOW_WIDTH,
                                   SDL_WINDOW_HEIGHT, 0, &as->window, &as->renderer)) {
    return SDL_APP_FAILURE;
  }

  SDL_SetRenderVSync(as->renderer, false);
  // SDL_SetWindowResizable(as->window, SDL_WINDOW_RESIZABLE);
  // SDL_SetWindowRelativeMouseMode(as->window, true);
  // SDL_SetHintWithPriority(SDL_HINT_WINDOWS_RAW_KEYBOARD, "1", SDL_HINT_OVERRIDE);
  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  if (appstate != NULL) {
    AppState *as = (AppState *) appstate;
    SDL_DestroyRenderer(as->renderer);
    SDL_DestroyWindow(as->window);
    SDL_free(as);
  }
}