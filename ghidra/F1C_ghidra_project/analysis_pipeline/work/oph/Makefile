# Makefile — Safety Car Plugin for F1 Challenge 99-02
#
# Targets:
#   make mingw    — cross-compile with i686-w64-mingw32-gcc
#   make msvc     — compile with MSVC (requires cl.exe in PATH)
#   make clean    — remove build artifacts

CC_MINGW := i686-w64-mingw32-gcc
CFLAGS_MINGW := -shared -Os -s -static-libgcc -Wall -Wextra

CC_MSVC := cl
CFLAGS_MSVC := /LD /O2 /GS- /nologo /W3

TARGET := oph.dll
SRC := oph.c

.PHONY: all mingw msvc clean

all: mingw

mingw:
	$(CC_MINGW) $(CFLAGS_MINGW) -o $(TARGET) $(SRC)
	@echo "=== Built $(TARGET) with MinGW ==="
	@echo "Place oph.dll next to F1 Challenge Online.exe"

msvc:
	$(CC_MSVC) $(CFLAGS_MSVC) $(SRC)
	@echo "=== Built $(TARGET) with MSVC ==="
	@echo "Place oph.dll next to F1 Challenge Online.exe"

clean:
	rm -f $(TARGET) *.obj *.lib *.exp
