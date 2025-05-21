# C compiler.
CC = gcc

# Flags.
CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = -lncurses -lncursesw -DNCURSES_STATIC
DEBUGFLAGS = -g

# List of source files.
SOURCES = \
	main.c \
	cities.c \
	pages/prompts.c \
	pages/start.c \
	pages/cities.c \
	pages/city.c \

# Parse corresponding object files.
OBJECTS = $(foreach OBJECT,$(SOURCES:.c=.o),build/$(OBJECT))

# Parse build directories.
# Sort is to remove duplicate directories and ensure they are created in the correct order.
BUILDDIRECTORIES = $(foreach DIRECTORY,$(sort $(dir $(SOURCES))),build/$(DIRECTORY))

# Target file in build.
TARGET = main.exe

# Default command is to print info.
all:
	@echo -e "\033[1mCOMMANDS\033[0m"
	@echo -e "\033[1mmake compile\033[0m: compile the project"
	@echo -e "\033[1mmake run\033[0m: compile and run the project"
	@echo -e "\033[1mmake clean\033[0m: delete build results"
	@echo
	@echo -e "\033[1mCOMPILER\033[0m"
	@$(CC) --version

# Verbose info.
verbose: all
	@echo -e "\033[1mCOMPILER SPECS\033[0m"
	@$(CC) -v

# Compile command.
compile: build/$(TARGET)

# Compile objects to main executable.
build/$(TARGET): build $(BUILDDIRECTORIES) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(DEBUGFLAGS)

# Make build directory.
build:
	mkdir -p build

# Make child directories.
$(BUILDDIRECTORIES):
	mkdir -p $@

# Compile sources to objects.
$(OBJECTS): build/%.o: src/%.c
	$(CC) $< -o $@ -c $(CFLAGS) $(DEBUGFLAGS)

# Run command.
run: build/$(TARGET)
	@build/$(TARGET)

# Clean command.
clean:
	rm -r build

.PHONY=all run clean compile verbose