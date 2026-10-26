# Paused replacement-engine archive

> Preserved in place; do not delete. Engine recreation is outside the current
> mod-SDK objective. Use `python tools/f1c_mod.py route replacement_engine`
> before reading this historical bootstrap, and do not execute its build
> commands as part of SDK work.

# F1 Challenge replacement engine (historical)

This is an isolated, independently compilable replacement executable. It does
not modify or link against production mods and does not claim to reproduce the
original source organization.

The current bootstrap:

- resolves an existing game installation root;
- parses command-line options;
- reads `Config.ini` when present;
- inventories existing installation content;
- writes `F1ChallengeReplacement.log` in the selected installation directory;
- exits cleanly without attempting simulation or rendering.

Build a 32-bit Windows executable with the configured MinGW toolchain:

```powershell
cmake -S replacement_engine -B replacement_engine/build -G "MinGW Makefiles" `
  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=C:/msys64/mingw32/bin/g++.exe
cmake --build replacement_engine/build --parallel
ctest --test-dir replacement_engine/build --output-on-failure
```

Run an installation inventory without deploying over the original executable:

```powershell
replacement_engine/build/F1ChallengeReplacement.exe --inventory --root C:\Path\To\F1Challenge
```

The next bootstrap layers are MAS/archive indexing, legacy path precedence,
content registration, and session lifecycle construction.
