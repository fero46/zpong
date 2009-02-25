#ifndef RAFE_BITMAP
#define RAGE_BITMAP
#endif

#ifndef _SDL_H
#include <SDL/SDL.h>
#endif


int ShowBMP (char *file, int x ,int y, SDL_Surface *window,int flag, Uint32 key );

int InitBMP_Surface(char *file, SDL_Surface **image, int flag, Uint32 key);

int CopySurfaceSize(SDL_Surface *Quelle, SDL_Surface **Ziel);

int CreatRectangle(SDL_Surface **rect, Uint32 color);

extern SDL_Surface *MakeSurface(int weight,int height, int depht,Uint32 flags);


