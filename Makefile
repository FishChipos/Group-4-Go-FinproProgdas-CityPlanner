CC = gcc
CFLAGS = -Isrc -Wall -Wextra
LDFLAGS = -lncurses -lncursesw -DNCURSES_STATIC
DEBUGFLAGS = -g

SOURCES = \
	main.c \
	pages/start.c

OBJECTS = $(foreach OBJECT,$(SOURCES:.c=.o),build/$(OBJECT))
BUILDDIRECTORIES = $(foreach DIRECTORY,$(sort $(dir $(SOURCES))),build/$(DIRECTORY))

TARGET = main.exe

all: info build/$(TARGET)
	
info:
	@echo "Compiling with:"
	@$(CC) --version

build/$(TARGET): build $(BUILDDIRECTORIES) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(DEBUGFLAGS)

build:
	mkdir -p build

$(BUILDDIRECTORIES):
	mkdir -p $@

$(OBJECTS): build/%.o: src/%.c
	$(CC) $< -o $@ -c $(CFLAGS) $(DEBUGFLAGS)

run: info build/$(TARGET)
	@build/$(TARGET)

clean:
	rm -r build

.PHONY=all info