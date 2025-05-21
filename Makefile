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

all:
	@echo "Commands:"
	@echo "make compile: compile the project"
	@echo "make run: compile and run the project"
	@echo "make clean: delete build results"
	@echo
	@echo "Compiling with:"
	@$(CC) --version

compile: build/$(TARGET)

build/$(TARGET): build $(BUILDDIRECTORIES) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(DEBUGFLAGS)

build:
	mkdir -p build

$(BUILDDIRECTORIES):
	mkdir -p $@

$(OBJECTS): build/%.o: src/%.c
	$(CC) $< -o $@ -c $(CFLAGS) $(DEBUGFLAGS)

run: build/$(TARGET)
	@build/$(TARGET)

clean:
	rm -r build

.PHONY=all compile