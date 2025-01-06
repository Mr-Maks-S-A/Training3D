#ifndef _CONFIG_GPP_
#define _CONFIG_GPP_

#include <SDL3/SDL_init.h>

// #define PLATFORM_ID ""

#define PROGECT_LANG_CPP_STANDART (23)
// #define CXX_COMPILER_ID ""
// #define CXX_COMPILER_VERSION ()

#define PROGECT_LANG_C_STANDART (17)
// #define C_COMPILER_ID ""
// #define C_COMPILER_VERSION ()

#define PROGECT_VERSION_MAJOR (0)
#define PROGECT_VERSION_MINOR (1)
#define PROGECT_VERSION_PATCH (1)
#define PROGECT_VERSION "0.1.1"

static const struct {
  const char* m_key;
  const char* m_value;
} extended_metadata[] = {{SDL_PROP_APP_METADATA_NAME_STRING, "3D_base"},
                         {SDL_PROP_APP_METADATA_VERSION_STRING, PROGECT_VERSION},
                         {SDL_PROP_APP_METADATA_IDENTIFIER_STRING, " SDL3 Render Project"},
                         {SDL_PROP_APP_METADATA_CREATOR_STRING, "Jarco (ak Mr-Maks-S-A)"},
                         {SDL_PROP_APP_METADATA_COPYRIGHT_STRING, "None"},
                         {SDL_PROP_APP_METADATA_URL_STRING, "https://github.com/Mr-Maks-S-A/Training3D.git"},
                         {SDL_PROP_APP_METADATA_TYPE_STRING, "Game"}};


#endif //_CONFIG_GPP_
