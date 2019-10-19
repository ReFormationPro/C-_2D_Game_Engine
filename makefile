CC=g++
CFLAGS=-Wall -pedantic-errors -std=gnu++11#-ansi
LDFLAGS=-lSDL2 -lSDL2_image -lm
SOURCES=test.cpp main.cpp cJSON/cJSON.c Entity.cpp AssetLoader.cpp Components/*.cpp

engine: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o engine.exe

clean: 
	rm -f engine.exe

