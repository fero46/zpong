/*
Burning Books v. 0.0.1 Source code is Copyright by Ferhat Ziba

This Source is under GPL


*/
/* Binde Headerfiles ein*/

/*Binde Enginefunktionen ein*/
#include "engine/bitmaps.h"
#include "engine/font.h"

/*Lade SDL bibliothek*/
#include <SDL/SDL.h>




SDL_Surface *Pong_1,*Pong_2,*Ball,*tmp_Pong1,*tmp_Pong2,*tmp_Ball;
SDL_Rect dest_Pong1,dest_Pong2,dest_Ball,tmpBall, tmpPong1,tmpPong2,tmp2Ball;
int sx=640,sy=480,xrichtung=1,yrichtung,winkel,player1=0, player2=0,menustat=1,schritt=8;


int freesurface()
{
        Pong_1=NULL;
        Pong_2=NULL;
        Ball=NULL;
        tmp_Pong1=NULL;
        tmp_Pong2=NULL;
        tmp_Ball=NULL;
        return 0;
}
int update(SDL_Surface *screen)
{
	/* Kopiere die gesicherte Flächen wieder zurück */
	SDL_BlitSurface(tmp_Pong1,NULL,screen,&tmpPong1);
	SDL_BlitSurface(tmp_Pong2,NULL,screen,&tmpPong2);
	SDL_BlitSurface(tmp_Ball,NULL,screen,&tmpBall);
	/* Sicher erst die Flächen */
	SDL_BlitSurface(screen,&dest_Pong1,tmp_Pong1,NULL);
	SDL_BlitSurface(screen,&dest_Pong2,tmp_Pong2,NULL);
	SDL_BlitSurface(screen,&dest_Ball,tmp_Ball,NULL);

	/* Blite jetzt die Surfaces in die screen Surface */
	SDL_BlitSurface(Ball,NULL,screen,&dest_Ball);
	SDL_BlitSurface(Pong_1,NULL,screen,&dest_Pong1);
	SDL_BlitSurface(Pong_2,NULL,screen,&dest_Pong2);
	/* Wechsel bildschirm */
	SDL_Flip(screen);
        tmpBall=dest_Ball;
        tmpPong1=dest_Pong1;
        tmpPong2=dest_Pong2;
}
int MoveBall(int Pong1moving, int Pong2moving)
{

        if(     dest_Ball.x<dest_Pong1.x+dest_Pong1.w

                && dest_Ball.y < dest_Pong1.y+dest_Pong1.h
                && dest_Ball.y+dest_Ball.h>dest_Pong1.y )
        {
                xrichtung=2;
                if(Pong1moving==-1)
                        {
                                if(dest_Ball.y +dest_Ball.w > dest_Pong1.y
                                && dest_Ball.y < dest_Pong1.y+(dest_Pong1.w/3))
                                {
                                        winkel=3;
                                        yrichtung=1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong1.y+(dest_Pong1.w/3)
                                && dest_Ball.y < dest_Pong1.y+((dest_Pong1.w/3)*2));
                                {
                                        winkel=1;
                                        yrichtung=1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong1.y+((dest_Pong1.w/2)*2)
                                && dest_Ball.y < dest_Pong2.y+dest_Pong1.w);
                                {
                                        winkel=2;
                                        yrichtung=1;
                                }
                        }
                if(Pong1moving==1){
                                if(dest_Ball.y +dest_Ball.w > dest_Pong1.y
                                && dest_Ball.y < dest_Pong1.y+(dest_Pong1.w/3))
                                {
                                        winkel=3;
                                        yrichtung=-1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong1.y+(dest_Pong1.w/3)
                                && dest_Ball.y < dest_Pong1.y+((dest_Pong1.w/3)*2));
                                {
                                        winkel=1;
                                        yrichtung=-1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong1.y+((dest_Pong1.w/2)*2)
                                && dest_Ball.y < dest_Pong2.y+dest_Pong1.w);
                                {
                                        winkel=2;
                                        yrichtung=-1;
                                }
                }

        }
        if(dest_Ball.x>dest_Pong2.x-dest_Pong2.w
           && dest_Ball.y < dest_Pong2.y+dest_Pong2.h
           && dest_Ball.y+dest_Ball.h>dest_Pong2.y )
                {
                        xrichtung=1;
                        if(Pong2moving==-1){
                                if(dest_Ball.y +dest_Ball.w > dest_Pong2.y
                                && dest_Ball.y < dest_Pong2.y+(dest_Pong2.w/3))
                                {
                                        winkel=3;
                                        yrichtung=1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong2.y+(dest_Pong2.w/3)
                                && dest_Ball.y < dest_Pong2.y+((dest_Pong2.w/3)*2));
                                {
                                        winkel=1;
                                        yrichtung=1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong2.y+((dest_Pong2.w/2)*2)
                                && dest_Ball.y < dest_Pong2.y+dest_Pong2.w);
                                {
                                        winkel=2;
                                        yrichtung=1;
                                }
                        }
                        if(Pong2moving==1){
                                if(dest_Ball.y +dest_Ball.w > dest_Pong2.y
                                && dest_Ball.y < dest_Pong2.y+(dest_Pong2.w/3))
                                {
                                        winkel=3;
                                        yrichtung=-1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong2.y+(dest_Pong2.w/3)
                                && dest_Ball.y < dest_Pong2.y+((dest_Pong2.w/3)*2));
                                {
                                        winkel=1;
                                        yrichtung=-1;
                                }
                                if(dest_Ball.y+dest_Ball.w > dest_Pong2.y+((dest_Pong2.w/2)*2)
                                && dest_Ball.y < dest_Pong2.y+dest_Pong2.w);
                                {
                                        winkel=2;
                                        yrichtung=-1;
                                }
                        }


                }

        if(xrichtung==1)dest_Ball.x=dest_Ball.x-10;
        if(xrichtung==2)dest_Ball.x=dest_Ball.x+10;
        if(dest_Ball.y<=10)yrichtung=-1;
        if(dest_Ball.y+dest_Ball.w+10>=sy)yrichtung=1;
        if(yrichtung==1)
        {
                if(winkel==1)dest_Ball.y=dest_Ball.y-3;
                if(winkel==2)dest_Ball.y=dest_Ball.y-6;
                if(winkel==3)dest_Ball.y=dest_Ball.y-9;
        }
        if(yrichtung==-1)
        {
                if(winkel==2)dest_Ball.y=dest_Ball.y+6;
                if(winkel==3)dest_Ball.y=dest_Ball.y+9;
                if(winkel==1)dest_Ball.y=dest_Ball.y+3;
        }
        if(dest_Ball.x<dest_Pong1.x)
        {
                player2++;
                xrichtung=2;
                yrichtung=0;
                printf("Player 1:  %d punkte\nPlayer 2:  %d punkte\n", player1, player2);
                return -1;

        }
        if(dest_Ball.x>dest_Pong2.x+dest_Pong2.w)
        {
                player1++;
                xrichtung=1;
                yrichtung=0;
                printf("Player 1:  %d punkte\nPlayer 2:  %d punkte\n", player1, player2);
                return -1;
        }

        return 0;

}

Initgame(SDL_Surface *screen)
{
        InitBMP_Surface("data/Pong",&Pong_1,0,0);
	InitBMP_Surface("data/Pong",&Pong_2,0,0);
	InitBMP_Surface("data/ball",&Ball,1,0x29f600);

	/* Erstelle Temporäre Copien für den zwischen speicher */
	CopySurfaceSize(Pong_1,&tmp_Pong1);
	CopySurfaceSize(Pong_2,&tmp_Pong2);
	CopySurfaceSize(Ball,&tmp_Ball);

	/* setze die Positionen für die Objekte
		(2 mal Pongschläger und ein Ball) */
	dest_Pong1.x=10;
	dest_Pong1.y=(sy-Pong_1->h)/2;
	dest_Pong1.w=Pong_1->w;
	dest_Pong1.h=Pong_1->h;

	dest_Pong2.x=(sx-Pong_2->w)-10;
	dest_Pong2.y=(sy-Pong_2->h)/2;
	dest_Pong2.w=Pong_2->w;
	dest_Pong2.h=Pong_2->h;

	dest_Ball.x=(sx-Ball->w)/2;
	dest_Ball.y=(sy-Ball->h)/2;
	dest_Ball.w=Ball->w;
	dest_Ball.h=Ball->h;

        tmpBall=dest_Ball;
        tmpPong1=dest_Pong1;
        tmpPong2=dest_Pong2;
	SDL_BlitSurface(screen,&tmpPong1,tmp_Pong1,NULL);
	SDL_BlitSurface(screen,&tmpPong2,tmp_Pong2,NULL);
	SDL_BlitSurface(screen,&tmpBall,tmp_Ball,NULL);

}

int MoveComputer()
{
        int returnvalue;
                if(tmp2Ball.y==dest_Ball.y)returnvalue=0;
                if(tmp2Ball.y!=dest_Ball.y)
                {
                        if(tmp2Ball.y<dest_Ball.y)
                        {
                                if((dest_Pong2.h+dest_Pong2.y)<(sy-schritt))dest_Pong2.y=dest_Pong2.y+schritt;
                                returnvalue=1;
                        }
                        if(tmp2Ball.y>dest_Ball.y)
                        {
        			if(dest_Pong2.y>schritt)dest_Pong2.y=dest_Pong2.y-schritt;
                                returnvalue=-1;
                        }
                        tmp2Ball.y=dest_Ball.y;
                }
                return returnvalue;

}
int init1playergame(SDL_Surface *screen)
{

	SDL_Event event;
	int Update=0, MovePong1=0,MovePong2=0,done=0,player1press=0,player2press=0;

	/* Fülle die Surfaces */
        Initgame(screen);


	update(screen);

        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
	while(!done)
        {
             SDL_Delay(20);
             while ( SDL_PollEvent(&event) )
             {
             switch(event.key.keysym.sym)
       	       		{
       	               	case SDLK_SPACE:
       	 	                {

		                }
      		        break;
			case SDLK_DOWN:
				{
					if(player1press==0)
                                        {
                                                MovePong1=1;
					        Update= 1;
                                                player2press=1;
                                        }

                                }
                        break;
			case SDLK_UP:
				{
                                        if(player1press==0)
                                        {
					        MovePong1=-1;
					        Update= 1;
                                                player2press=1;
                                        }

				}
			break;
			case SDLK_LEFT:
				{
                                        if(player1press==0)
                                        {
                                                MovePong1=0;
                                                Update=1;
                                                player2press=1;
                                        }

				}
			break;
                        case SDLK_ESCAPE:
		                {
                                        yrichtung=0;
                                        freesurface();
                                        return 0;
        	                }
			break;
		}
                }

		if(MovePong1==-1)
		{
			if(dest_Pong1.y>schritt)dest_Pong1.y=dest_Pong1.y-schritt;
		}
		if(MovePong1==1)
		{
 			if((dest_Pong1.h+dest_Pong1.y)<(sy-schritt))dest_Pong1.y=dest_Pong1.y+schritt;
		}
                if(dest_Pong1.h+dest_Pong1.y>=sy-schritt||dest_Pong1.y<=schritt)MovePong1=0;
                MovePong2=MoveComputer();
                if(MoveBall(MovePong1,MovePong2)==-1)return 1;
		update(screen);
                player1press=0;
                player2press=0;

        }


	return 0;
}


int init2playergame(SDL_Surface *screen)
{

	SDL_Event event;
	int Update=0, MovePong1=0,MovePong2=0,done=0,player1press=0,player2press=0;;

	/* Fülle die Surfaces */
        Initgame(screen);
	update(screen);

        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
	while(!done)
        {
            SDL_Delay(20);
             while ( SDL_PollEvent(&event) )
             {
             switch(event.key.keysym.sym)
       	       		{
       	               	case SDLK_SPACE:
       	 	                {

		                }
      		        break;
			case SDLK_DOWN:
				{
					if(player2press==0)
                                        {
                                                MovePong2=1;
					        Update= 1;
                                                player2press=1;
                                        }

                                }
                        break;
			case SDLK_UP:
				{
                                        if(player2press==0)
                                        {
					        MovePong2=-1;
					        Update= 1;
                                                player2press=1;
                                        }

				}
			break;
			case SDLK_RIGHT:
				{
                                        if(player2press==0)
                                        {
                                                MovePong2=0;
                                                Update=1;
                                                player2press=1;
                                        }

				}
			break;

			case SDLK_x:
				{
                                        if(player1press==0)
                                        {
					        MovePong1=1;
					        Update= 1;
                                                player1press=1;
                                        }

				}
			break;
			case SDLK_s:
				{
                                        if(player1press==0)
                                        {
                                                MovePong1=-1;
					        Update= 1;
                                                player1press=1;
                                        }

				}
			break;
			case SDLK_a:
				{       if(player1press==0)
                                        {
                                        	MovePong1=0;
					        Update=1;
                                                player1press=1;
                                        }

				}
			break;
                        case SDLK_ESCAPE:
		                {
                                        yrichtung=0;
                                        freesurface();
                                        return 0;
        	                }
			break;
		}
                }

		if(MovePong2==-1)
		{
			if(dest_Pong2.y>schritt)dest_Pong2.y=dest_Pong2.y-schritt;
		}
		if(MovePong2==1)
		{
 			if((dest_Pong2.h+dest_Pong2.y)<(sy-schritt))dest_Pong2.y=dest_Pong2.y+schritt;
		}
                if(dest_Pong2.h+dest_Pong2.y>=sy-schritt||dest_Pong2.y<=schritt)MovePong2=0;
		if(MovePong1==-1)
		{
			if(dest_Pong1.y>schritt)dest_Pong1.y=dest_Pong1.y-schritt;
		}
		if(MovePong1==1)
		{
 			if((dest_Pong1.h+dest_Pong1.y)<(sy-schritt))dest_Pong1.y=dest_Pong1.y+schritt;
		}
                if(dest_Pong1.h+dest_Pong1.y>=sy-schritt||dest_Pong1.y<=schritt)MovePong1=0;
                if(MoveBall(MovePong1,MovePong2)==-1)return 1;
		update(screen);
                player1press=0;
                player2press=0;

        }


	return 0;
}
int Initwindow(char *text,SDL_Surface *screen)
{
        SDL_Surface *Headline;
        SDL_Rect position;
        CreatRectangle(&screen,0);
        Headline=MakeSurface(360,40,16,SDL_HWSURFACE);
        loadtext(text,Headline);
        position.w=Headline->w;
        position.h=Headline->h;
        position.x=(sx-position.w)/2;
        position.y=100;
        SDL_BlitSurface(Headline,NULL,screen,&position);
        position.w=400;
        position.h=100;
        position.x=(sx-position.w)/2;
        position.y=(sy-position.h)/2;
        SDL_FillRect(screen,&position,0x0000ff);
        position.w=350;
        position.h=50;
        position.x=(sx-position.w)/2;
        position.y=(sy-position.h)/2;
        SDL_FillRect(screen,&position,0x0);
        SDL_Flip(screen);
        SDL_FreeSurface(Headline);
        return 0;
}
int changeskin(SDL_Surface *screen)
{
        Initwindow("Geht noch nicht",screen);
        SDL_Delay(2000);
}
int Network(SDL_Surface *screen)
{
        Initwindow("Geht noch nicht",screen);
        SDL_Delay(2000);
}



int StartMenu(SDL_Surface *screen)
{

        SDL_Rect position;
        SDL_Surface *Menu, *Player1,*Player2,*Playnet,*Skin,*Exit,*tmporaer,*ball;
        SDL_Event event;
        int menucounter=1;
        position.x=sx/8;
        position.y=sy/8;
        position.w=sx-(2*(sx/8));
        position.h=sy-(2*(sy/8));
        CreatRectangle(&screen,0);
        SDL_FillRect(screen,&position,0x0000ff);
        Menu=MakeSurface(100,40,16,SDL_HWSURFACE);
        Player1=MakeSurface(280,40,16,SDL_HWSURFACE);
        Player2=MakeSurface(280,40,16,SDL_HWSURFACE);
        Playnet=MakeSurface(260,40,16,SDL_HWSURFACE);
        Skin=MakeSurface(260,40,16,SDL_HWSURFACE);
        Exit=MakeSurface(100,40,16,SDL_HWSURFACE);
        InitBMP_Surface("data/ball",&ball,1,0x29f600);
        SDL_SetColorKey(Menu,SDL_SRCCOLORKEY,0);
        SDL_SetColorKey(Player1,SDL_SRCCOLORKEY,0);
        SDL_SetColorKey(Player2,SDL_SRCCOLORKEY,0);
        SDL_SetColorKey(Playnet,SDL_SRCCOLORKEY,0);
        SDL_SetColorKey(Skin,SDL_SRCCOLORKEY,0);
        SDL_SetColorKey(Exit,SDL_SRCCOLORKEY,0);
        loadtext("Menu",Menu);
        loadtext("Ein  Spieler",Player1);
        loadtext("Zwei Spieler",Player2);
        loadtext("Netzwerk",Playnet);
        loadtext("Skin laden",Skin);
        loadtext("Exit",Exit);
        position.x=(sx-Menu->w)/2;
        position.y=20;
        position.w=Menu->w;
        position.h=Menu->h;
        SDL_BlitSurface(Menu,NULL,screen,&position);
        position.x=sx/5;
        position.y=sy/5;
        position.w=Player1->w;
        position.h=Player1->h;
        SDL_BlitSurface(Player1,NULL,screen,&position);
        position.y=position.y+50;
        position.w=Player2->w;
        position.h=Player2->h;
        SDL_BlitSurface(Player2,NULL,screen,&position);
        position.y=position.y+50;
        position.w=Playnet->w;
        position.h=Playnet->h;
        SDL_BlitSurface(Playnet,NULL,screen,&position);
        position.y=position.y+50;
        position.w=Skin->w;
        position.h=Skin->h;
        SDL_BlitSurface(Skin,NULL,screen,&position);
        position.y=position.y+50;
        position.w=Exit->w;
        position.h=Exit->h;
        SDL_BlitSurface(Exit,NULL,screen,&position);
        CopySurfaceSize(ball,&tmporaer);
        position.y=sy/5;
        position.x=position.x-40;
        position.w=ball->w;
        position.h=ball->h;
        SDL_BlitSurface(screen,&position,tmporaer,NULL);
        SDL_BlitSurface(ball,NULL,screen,&position);
        SDL_Flip(screen);
        SDL_BlitSurface(tmporaer,NULL,screen,&position);
        while(SDL_WaitEvent(&event) >= 0)
        {
                switch(event.type)
                {
                        case SDL_KEYDOWN:
                        {
                                switch(event.key.keysym.sym)
                                {
                                  case SDLK_SPACE:
                                        {
                                                if(menucounter==5)
                                                {
                                                        free(screen);
                                                        exit(0);
                                                }
                                                if(menucounter==1)menustat=1;
                                                if(menucounter==2)menustat=2;
                                                if(menucounter==3)menustat=3;
                                                if(menucounter==4)menustat=4;
                                                        SDL_FreeSurface(Menu);
                                                        SDL_FreeSurface(Player1);
                                                        SDL_FreeSurface(Player2);
                                                        SDL_FreeSurface(Playnet);
                                                        SDL_FreeSurface(Exit);
                                                        SDL_FreeSurface(ball);
                                                if(menucounter==5)
                                                {
                                                        free(screen);
                                                        exit(0);
                                                }
                                                        return menustat;
                                        }
                                  break;
                                  case SDLK_ESCAPE:
                                  {
                                        free(screen);
                                        exit(0);
                                  }
                                  break;
                                  case SDLK_DOWN:
                                  {
                                        if(menucounter!=5)
                                        {
                                                SDL_BlitSurface(tmporaer,NULL,screen,&position);
                                                menucounter++;
                                                position.y=position.y+50;
                                                SDL_BlitSurface(screen,&position,tmporaer,NULL);
                                                SDL_BlitSurface(ball,NULL,screen,&position);
                                                SDL_Flip(screen);
                                        }

                                  }
                                  break;
                                  case SDLK_UP:
                                  {
                                        if(menucounter!=1)
                                        {
                                                SDL_BlitSurface(tmporaer,NULL,screen,&position);
                                                menucounter--;
                                                position.y=position.y-50;
                                                SDL_BlitSurface(screen,&position,tmporaer,NULL);
                                                SDL_BlitSurface(ball,NULL,screen,&position);
                                                SDL_Flip(screen);
                                        }
                                  }
                                }
                        }
                        break;
                        case SDL_QUIT:
                        {
                                /*gebe screen wieder frei und beende*/
                                free(screen);
                                exit(0);
                        }
                        break;
                }
        }


}

int main(int argc, char *argv[])
{       SDL_Rect dest,posi;
        SDL_Surface *screen,*front;
        SDL_Event event;
        /* es wird überprüft ob die midest auflösung eingehalten wurde */
        if (sx<640 || sy < 480)
        {
                printf("Zu kleiner Bildschirm-Auflösung\n");
                exit(1);
        }
        /*Initialisiere die SDL Bibliothek*/
        if(SDL_Init(SDL_INIT_VIDEO)< 0)
        {

                fprintf(stderr,"Couldn't initialize SDL: %s\n",
        SDL_GetError());
                exit(1);
        }

        atexit(SDL_Quit);
        SDL_WM_SetCaption("Z-Systems Pong Clone","noicon");
        /*Setze Modus in das Surface screen*/

        if((screen=SDL_SetVideoMode(sx,sy,16,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_HWPALETTE))==NULL)
        {
                fprintf(stderr,"Couldn't set Video mode: %s\n",SDL_GetError());
                exit(1);
        }
        InitBMP_Surface("data/intro",&front,1,0);
        posi.x=0;
        posi.y=0;
        posi.w=sx;
        posi.h=sy;
        dest.x=(sx-front->w)/2;
        dest.y=(sy-front->h)/2;
        dest.h=front->h;
        dest.w=front->w;
        SDL_BlitSurface(front,NULL,screen,&dest);
        SDL_Flip(screen);
        /*Starte Eventschleife*/
        initfont("data/font",0);
        while(SDL_WaitEvent(&event) >= 0)
        {
                switch(event.type)
                {
                        case SDL_KEYDOWN:
                        {
                                switch(event.key.keysym.sym)
                                {
                                  case SDLK_SPACE:
                                  case SDLK_RETURN:
                                  {
                                      while(menustat!=0)
                                      {
                                        StartMenu(screen);
                                        SDL_FillRect(screen,&posi,0x000000);
                                        InitBMP_Surface("data/back",&front,1,0);
                                        if(menustat==3)Network(screen);
                                        if(menustat==4)changeskin(screen);
                                        dest.x=(sx-front->w)/2;
                                        dest.y=(sy-front->h)/2;
                                        dest.h=front->h;
                                        dest.w=front->w;
                                        SDL_BlitSurface(front,NULL,screen,&dest);
                                        if(menustat==1)init1playergame(screen);
                                        if(menustat==2)init2playergame(screen);
                                        freesurface();

                                      }

                                  }
                                  break;
                                  case SDLK_ESCAPE:
                                  {
                                        free(screen);
                                        exit(0);
                                  }
                                }
                        }
                        break;
                        case SDL_QUIT:
                        {
                                /*gebe screen wieder frei und beende*/
                                free(screen);
                                exit(0);
                        }
                        break;
                }
        }
        /* "Dies darf eigentlich niemals passieren" so in der Dokumentation */
        printf("SDL_WaitEvent error: %s\n", SDL_GetError());
        exit(1);
}
