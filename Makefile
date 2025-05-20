<<<<<<< HEAD
CC = C:\\msys64\\mingw64\\bin\\gcc.exe
CFLAGS = -Isrc -Wall -Wextra
=======
CC = gcc
CFLAGS = -Isrc -Wall -Wextra -foptimize-sibling-calls
>>>>>>> bc36b09969645645485c26a660a159dc0092dd23
LDFLAGS = -lncurses -lncursesw -DNCURSES_STATIC
DEBUGFLAGS = -g

SOURCES = \
	main.c \
	pages.c \
	window.c

OBJECTS = $(foreach OBJECT,$(SOURCES:.c=.o),build/$(OBJECT))

TARGET = main.exe

all: build/$(TARGET)

build/$(TARGET): build $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(DEBUGFLAGS)

build:
	mkdir -p build

$(OBJECTS): build/%.o: src/%.c
	$(CC) $< -o $@ -c $(CFLAGS) $(DEBUGFLAGS)

run: build/$(TARGET)
	$<

clean:
	rm -r build

.PHONY=all