## sub_4CDC80_004cdc80 — PlayerFileSave

**Summary:** Saves player data to a `.PLR` file using a temp-file-then-rename strategy: serializes the player struct to a temp file, removes any stale backup, and renames the temp to the final filename, with optional debug logging.

**Called by:** sub_475350 (00475350), unknown_libname_40 (00482100), sub_482370 (00482370), sub_49C1D0 (0049c1d0), sub_4B9790 (004b9790), sub_4CDED0 (004cded0), sub_4CEA30 (004cea30), sub_4CEB40 (004ceb40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x5744)+0x0) | 0x14 | R | — | vtable function pointer: called to serialize player data before save |
| *(this+0x5744) | 0x0 | R | — | pointer to player data object |
| this | 0x5744 | R | — | offset to player data object pointer within the manager struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0060f754 | aRetcodeDForRen | R | debug format string: "Retcode: %d for renaming to %s" |
| 0060f778 | asc_60F778 | R | player file header/comment block (copyright notice text) |
| 0060fa24 | aAttemptingToSa | R | debug format string: "Attempting to save to %s" |
| 0060fa40 | aDDevNascar2004_13 | R | source file path string: "D:\\dev\\NASCAR_2004\\Source\\plrfile.cpp" |
| 0060fa68 | aTmp | R | ".TMP" string literal for temp file extension |
| 00629120 | byte_629120 | R | current working/save directory path |
| 0075cba8 | dword_75CBA8 | R | mode/state flag: value 1 or 5 gates debug logging |
| 0075e8f0 | dword_75E8F0 | R | object passed to sub_435E80 for cleanup/post-save processing |
| 00764d70 | dword_764D70 | R | player data validity handle checked by sub_4634F0 |
| 007d7920 | dword_7D7920 | R | debug log object handle for conditional trace output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e80 | sub_435E80 | post-save cleanup/update on the player object |
| 004634f0 | sub_4634F0 | checks whether player data is valid/ready to save |
| 004bc450 | sub_4BC450 | writes the player file header/comment block to the temp file |
| 004cd760 | sub_4CD760 | serializes the player struct data to the output file |
| 004e5c50 | CareerSectionReader [structural] | reads/writes career-related section of the player file |
| 00500f90 | sub_500F90 | checks whether debug/trace logging is enabled for a given verbosity level |
| 00500fe0 | sub_500FE0 | emits a formatted debug/trace log message |
| 00578560 | sub_578560 | appends a string to the current path buffer |
| 00578600 | StringCopyWithBufferRealloc [structural] | copies/sets a string with buffer management |
| 0057a080 | ZeroInitSmallStruct [exact] | zero-initializes a small local struct (file handle wrapper) |
| 0057a0a0 | sub_57A0A0 | closes/cleans up the small struct |
| 0057a110 | sub_57A110 | opens/creates a file for writing (params: path, mode=0, flags=1, 1) |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | conditionally closes the file handle |
| 0057b040 | sub_57B040 | constructs a filesystem path |
| 005be8ae | sub_5BE8AE | frees/deallocates memory |
| 005bf13d | _rename | renames the temp file to the final filename |
| 005bf20f | _remove | removes the old backup/temp file |
| 005c2372 | ToggleFileReadOnlyAttributeViaWin32API [structural] | sets file attributes (removes read-only) via _chmod |

**Guard conditions:** `!sub_4634F0(dword_764D70) || dword_75CBA8 == 1` — save is BLOCKED (early return) when player data is valid AND the mode flag is not 1. Save PROCEEDS when player data is invalid (check fails) OR when mode flag equals 1. This means save is allowed when data is force-flushed (mode=1) or when validity check indicates no existing valid data to overwrite.

**String literals referenced (deterministic):**

- `Retcode: %d for renaming to %s`
- `//*****************************************************************
//*                                                               *
//*  Player File                                                  *
//*                                                               *
//*  Edit at your own risk!                                       *
//*                                                               *
//*  Copyright (c) 1999-2002 Image Space Incorporated             *
//*  All rights reserved.                                         *
//*                                                               *
//*****************************************************************
`
- `Attempting to save to %s`
- `D:\dev\NASCAR_2004\Source\plrfile.cpp`
- `D:\dev\NASCAR_2004\Source\plrfile.cpp`
- `.TMP`
