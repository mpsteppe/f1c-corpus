# BF-01: Rich Header Analysis

**Status:** DONE (2026-07-16)

## Raw Results

Rich header at offset 0x120, XOR key 0x563fd3e0, DanS at 0x80.

| Comp ID | Build | Count | Description |
|---------|-------|-------|-------------|
| 12 | 7291 | 16 | C compiler (2) |
| 11 | 8047 | 20 | Assembler |
| 14 | 7299 | 40 | Linker (2) |
| 10 | 8047 | 172 | Assembler (MASM) |
| 42 | 8803 | 5 | Unknown (0x2A) |
| 11 | 8799 | 6 | Assembler |
| 18 | 8112 | 1 | Unknown (0x12) |
| 28 | 9178 | 2 | Unknown (0x1C) |
| 0 | 0 | 8 | Total imports |
| 18 | 8444 | 1 | Unknown (0x12) |
| 25 | 9210 | 4 | Unknown (0x19) |
| 29 | 9178 | 68 | Unknown (0x1D) |
| 4 | 8447 | 52 | **C compiler (MSVC 6.0 SP6)** |
| 19 | 8034 | 15 | Unknown (0x13) |
| 1 | 0 | 231 | Import (1) |
| 48 | 9044 | 22 | Unknown (0x30) |
| 49 | 9044 | 139 | Unknown (0x31) |
| 6 | 1735 | 1 | C++ compiler |

## Key Findings

- **Compiler: MSVC 6.0 SP6** (build 8447) — confirmed by C compiler comp ID 4
- **C compilation units: 68** (comp ID 4=52 + comp ID 12=16)
- **C++ compilation units: 1** (comp ID 6, build 1735 — oddly low build number, likely a library)
- **Total compilation units: 69**
- **We found 31 .cpp files from strings** — missing ~38 compilation units
- **172 MASM assembler objects** — likely CRT + math library hand-optimized routines
- **231 import objects** — static library linkage

## Interpretation

The 69 compilation units vs 31 known .cpp files means ~38 unknown source files exist.
These are likely:
- Additional engine source files without assert/trace strings
- Third-party libraries compiled from C source (audio, networking, MPEG)
- CRT object files compiled with the C compiler

The build 1735 C++ compiler entry (only 1 unit) is suspicious — may be from a different
MSVC version (7.0 era?) or a single library source file compiled separately.
