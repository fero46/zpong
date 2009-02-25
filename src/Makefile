CC=gcc
LDFLAGS=-lSDL -lpthread -lSDL_net -lSDL_image
WLDFLAGS=-lmingw32 -lSDLmain -lSDL -mwindows -lSDL_net -lSDL_image
OBJ =obj/bitmaps.o obj/fonts.o obj/main.o
all: main
main:  	
	$(CC) engine/bitmaps.c -c -g -o obj/bitmaps.o
	$(CC) engine/font.c -c -g -o obj/fonts.o
	$(CC) main.c -c -g -o obj/main.o
	$(CC) $(OBJ) $(LDFLAGS) -o zpong


windows:
	$(CC) engine/bitmaps.c -c -g -o obj/bitmaps.o
	$(CC) engine/font.c -c -g -o obj/fonts.o
	$(CC) main.c -c -g -o obj/main.o
	$(CC) $(OBJ) $(WLDFLAGS) -o zpong



clean:
	rm obj/*.o	
