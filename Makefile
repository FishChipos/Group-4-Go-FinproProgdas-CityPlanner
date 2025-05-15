CC = gcc
CFLAGS = -std=c99 -Isrc -Wall -Wextra
LDFLAGS = -lncurses

SOURCES = main.c

OBJECTS = $(foreach OBJECT,$(SOURCES:.c=.o),build/$(OBJECT))

TARGET = main.exe

all: build/$(TARGET)

build/$(TARGET): build $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

build:
	mkdir -p build

$(OBJECTS): build/%.o: src/%.c
	$(CC) $< -o $@ -c $(CFLAGS)

run: build/$(TARGET)
	$<

clean:
	rm -r build

.PHONY=all