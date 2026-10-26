# Safety Car Plugin v3 — build targets

# MinGW cross-compile (from WSL or MSYS2)
mingw:
	i686-w64-mingw32-gcc -shared -Os -s -o oph.dll oph.c -static-libgcc

# MSVC (from VS command prompt)
msvc:
	cl /LD /O2 /GS- oph.c

# Install to game directory (adjust path)
GAME_DIR = "C:\Program Files (x86)\EA SPORTS\F1 Challenge 99-02"

install: oph.dll
	copy /Y oph.dll $(GAME_DIR)\oph.dll

clean:
	del /Q oph.dll oph.obj oph.exp oph.lib 2>NUL

.PHONY: mingw msvc install clean
