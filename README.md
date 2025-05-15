# City Planner

Group 4's final project submission for Pemrograman Dasar.

#### Group Members

1. Alwahib Raffi Raihan
2. Carlsson Khovis
3. Muhammad Dhiya'ulhaq
4. Sakabudi Muhammad

## Running the Project

### Project Dependencies

This project requires ncurses (for the terminal UI) and GNU make (to build the project).

It is recommended to use the MSYS2 MinGW64-w64 installation for the gcc compiler.

#### GNU Make

If you installed the MinGW64-w64 toolchain, you should already have make.

Otherwise, install make by typing the following in an MSYS terminal:

```bash
pacman -S make
```

Make sure that `make.exe` is added to the PATH environment variable so that it can be accessed by other terminals. Usually it will be under `MSYS2InstallationPath\usr\bin`.

#### ncurses

For ncurses, if you are using a MinGW-w64 installation of gcc, type the following in a MinGW64 terminal provided by MSYS2:

```bash
pacman -S mingw-w64-ucrt-x86_64-ncurses
```

For other installations install the appropriate version of ncurses.

### Building the Project

Either copy the project files, or do:

```bash
git clone https://github.com/FishChipos/Group-4-Go-FinproProgdas-CityPlanner.git
```

Navigate into the new directory and type:

```bash
make run
```

to compile and run the project.