# City Planner

Group 4's final project submission for Pemrograman Dasar.

#### Group Members

1. Alwahib Raffi Raihan
2. Carlsson Khovis
3. Muhammad Dhiya'ulhaq
4. Sakabudi Muhammad

## Building the Project

### Project Dependencies

This project requires make (to build the project).

It is recommended to use the MSYS2 MinGW-w64 installation for the gcc compiler.

#### Make

If you installed the MinGW-w64 toolchain, you should already have make.

Otherwise, install make by typing the following in an MSYS terminal:

```bash
pacman -S make
```

Make sure that `make.exe` is added to the PATH environment variable so that it can be accessed by other terminals. Usually it will be under `MSYS2InstallationPath\usr\bin`.

### Compiling and Running the Project

Either copy the project files, or do:

```bash
git clone https://github.com/FishChipos/Group-4-Go-FinproProgdas-CityPlanner.git
```

Navigate into the new directory and type:

```bash
make
```

to compile and:

```bash
make run
```

to compile (if not already compiled) and run the project.

If there are issues with compilation, make sure that you are using the correct version of gcc with the necessary headers and libraries.