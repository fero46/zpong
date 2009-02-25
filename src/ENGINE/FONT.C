#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

const int size=16;

SDL_Surface *font_surface;
char result[11];



int initfont(char *file,Uint32 colorkey)
{
	font_surface=IMG_Load(file);
        SDL_SetColorKey(font_surface,SDL_SRCCOLORKEY,colorkey);
        font_surface=SDL_DisplayFormat(font_surface);
	return 0;
}

int loadtext(char *text, SDL_Surface *surface)
{
	SDL_Rect charsize,charposition;
	int position=0;
	charsize.x=0;
	charsize.y=0;
	charsize.w=font_surface->w / size;
	charsize.h=font_surface->h / size;
	charposition.x=0;
	charposition.y=0;
	charposition.w=font_surface->w / size;
	charposition.h=font_surface->h  / size;
	while(text[position]!=0)
	{
		charposition.x=(text[position] % size)* charposition.w;
		charposition.y=(text[position] / size)*charposition.h;
		SDL_BlitSurface(font_surface,&charposition,surface,&charsize);
		position++;
		charsize.x=charsize.x+(size/2)+((size/4)+(size/8)+(size/16))*2;
	}
}

int putchar_Surface(char ch,SDL_Surface *surface,int x,int y)
{
	SDL_Rect charsize,charposition;
        /*Lege die Größen und koordinaten  fest */
        charsize.x=x;
	charsize.y=y;
	charsize.w=font_surface->w / size;
	charsize.h=font_surface->h / size;

	charposition.w=font_surface->w / size;
	charposition.h=font_surface->h  / size;
        /* Suche mir die Koordinaten für das Char zeichen */
        charposition.x=(ch % size)* charposition.w;
	charposition.y=(ch / size)*charposition.h;
	SDL_BlitSurface(font_surface,&charposition,surface,&charsize);
}




int int2string(unsigned int zahl)
{
        sprintf(result,"%u",zahl);
        return 0;
}



