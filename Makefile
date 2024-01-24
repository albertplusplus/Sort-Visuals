.PHONY: all clean

# OUTPUT determines the name of the executable
OUTPUT = insertionsort

# Local path to Raylib header-only file
# Ensure "raylib.h" is in the directory you list below
INCLUDE_PATH = /usr/local/lib/

# Local Path to Raylib static compiled library
# Ensure "libraylib.a" is in the directory you list below
LIBRARY_PATH = lib/

# Source file(s)
# For a single file or unity build, rename source to your entry point (often main.c)
# To include all C files, use the wildcard below:
# SOURCE = $( wildcard *.c **/*.c )
SOURCE = insertionsort.cpp

# Compiler Flags
CFLAGS += -O1 -Wall -std=c++11 -Wno-missing-braces 
# Compiler flags for reference
#  -O1                  defines optimization level
#  -g                   include debug information on compilation
#  -Wall                turns on most, but not all, compiler warnings
#  -std=c99             defines C language mode (standard C from 1999 revision)
#  -Wno-missing-braces  ignore invalid warning (GCC bug 53119)

# Library Flags
LFLAGS = -lraylib -lm # -lopengl32 -lgdi32 -lwinmm
# Library Flags for Reference:
# ---- Required ----
# -lraylib     Raylib static compiled library, must be in LIBRARY_PATH
# -lopengl32   OpenGL - comes with MinGW
# -lgdi32      Graphics library - comes with MinGW
# -lwinmm      Import library for windows system file winmm.dll - comes with MinGW
# ---- Options ----
# -Wl,-subsystem,windows <--- Add these to hide the cmd console when launching game window

# Compiler (gcc == MinGW)
COMPILER = g++

all:
	$(COMPILER) $(SOURCE) -o $(OUTPUT) $(CFLAGS) -I $(INCLUDE_PATH) -L $(LIBRARY_PATH) $(LFLAGS)

clean:
	del *.o *.exe /s
	@echo Cleaning done
