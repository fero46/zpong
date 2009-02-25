#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



int ShowBMP(char *file,int x ,int y, SDL_Surface *window,int flag, Uint32 key )
{
	SDL_Surface *bitmap;
        SDL_Rect dest;

	/* Lade Bild */
	bitmap=IMG_Load(file);
	if(bitmap==NULL)
	{
	 fprintf(stderr, "Error: %s\n",SDL_GetError());
         return -1 ;
	}
        if(flag==1)SDL_SetColorKey(bitmap,SDL_SRCCOLORKEY,key);
/*      So wird das Bild schneller geblittet*/
        bitmap=SDL_DisplayFormat(bitmap);
        if(bitmap==NULL)
           {
              fprintf(stderr, "Error: %s\n",SDL_GetError());
              return -1;
           }
	/* Setze erst die Position  und Information vom Bild fest */
	dest.x=x;
	dest.y=y;
	dest.w=bitmap->w;
	dest.h=bitmap->h;
        /* Blitte jetzt */
        SDL_BlitSurface(bitmap, NULL , window, &dest);
	/* Mache ein Update damit man das Bild sehen kann */
	SDL_Flip(window);
        SDL_FreeSurface(bitmap);
        return 0;
}

int InitBMP_Surface(char *file, SDL_Surface **image,int flag, Uint32 key)
{
        SDL_Surface *bitmap;

        /* Lade Bitmap */
        bitmap=IMG_Load(file);
        if(bitmap==NULL)
        {
                fprintf(stderr,"Error: %s\n", SDL_GetError());
                return -1;
        }
        if(flag==1)SDL_SetColorKey(bitmap,SDL_SRCCOLORKEY,key);
        /* So wird das Bild schneller Geblittet */
        if((*image=SDL_DisplayFormat(bitmap))==NULL)
        {
                fprintf(stderr,"Error: %s\n", SDL_GetError());
                SDL_FreeSurface(bitmap);
                return -1;
        }
        SDL_FreeSurface(bitmap);
        return 0;
}

int CopySurfaceSize(SDL_Surface *Quelle, SDL_Surface **ziel)
{
        if((*ziel=SDL_AllocSurface(Quelle->flags, Quelle->w, 
Quelle->h,Quelle->format->BitsPerPixel, 
Quelle->format->Rmask,Quelle->format->Gmask, Quelle->format->Bmask, 0))==NULL)
        {
                fprintf(stderr,"Error: %S\n",SDL_GetError());
                return -1;
        }
        return 0;
}

int CreatRectangle(SDL_Surface **rect, Uint32 color)
{
        if((SDL_FillRect(*rect,NULL,color))<0)
        {
                printf("Konnte Surface nicht Erstellen");
                exit(1);
        }
        return 0;

}

extern SDL_Surface *MakeSurface(int weight,int height, int depht,Uint32 flags)
{
        return SDL_CreateRGBSurface(flags,weight,height,depht,0,0,0,0);
}


