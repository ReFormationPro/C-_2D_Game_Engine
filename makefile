CC=g++
CFLAGS=-Wall -ansi -pedantic-errors
LDFLAGS=-lSDL2 -lSDL2_image -lm
SOURCES=main.cpp cJSON/cJSON.c Entity.cpp AssetLoader.cpp

engine: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o engine.exe

clean: 
	rm -f engine.exe

