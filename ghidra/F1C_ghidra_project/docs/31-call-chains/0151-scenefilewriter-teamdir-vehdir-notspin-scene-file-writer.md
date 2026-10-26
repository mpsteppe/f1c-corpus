# Chain: SceneFileWriter — TEAMDIR/VEHDIR/NOTSPIN Scene File Writer

Seed: FUN_004ddf90  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 9

---

## Overview

Triggered from vehgen.scn File Loader (`FUN_004c6c40`). Opens `.gen` scene files and writes vehicle-specific tags including team directory, vehicle directory, dash display modes (DASHLOW/DASHHIGH), and AI spin directives (NOTSPIN). All callees are I/O utility functions — file open/close, string compare, format write, char write, error logging.

## Call Tree

```
FUN_004ddf90 — SceneFileWriter  [trigger: vehgen.scn file load]
  +-- FUN_005887b1 — StringFormatNestedIO  [5 callees — lock/write/format/unlock]
  |     +-- FUN_0058c1b1 — Mutex Lock
  |     +-- FUN_0058e41b — Stream Operation
  |     +-- FUN_0058d04d — Core Format Engine
  |     +-- FUN_0058e4a8 — Cleanup
  |     +-- FUN_0058c203 — Mutex Unlock
  +-- FUN_00589898 — BufferedCharWrite  [3 callees — mutex/flush/unlock]
  |     +-- FUN_0058c1b1 — Mutex Lock
  |     +-- FUN_0058cf35 — Buffer Flush/Write
  |     +-- FUN_0058c203 — Mutex Unlock
  +-- FUN_0058815f — PathSprintf  [2 callees — format + write]
  |     +-- FUN_0058d04d — Core Format Engine
  |     +-- FUN_0058cf35 — Buffered Write
  +-- FUN_004d7a50/004d7aa0 — Error Logging  [2 callees]
  +-- FUN_00534b00 — FileOpen  [1 callee]
  +-- FUN_00587db0 — FileOpenWithPath  [1 callee]
  +-- FUN_00587c20 — TagMatch  [leaf]
  +-- FUN_00588410 — StringCompare  [leaf]
  +-- FUN_005355a0 — CloseFile  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004ddf90 — SceneFileWriter

**Trigger:** Called from FUN_004c6c40 (vehgen.scn File Loader, docs/08)
**Called by:** FUN_004c6c40 — vehgen.scn file loader
**Purpose:** Opens .gen scene file and writes vehicle-specific data including TEAMDIR, VEHDIR, NOTSPIN, DASHLOW/DASHHIGH tags.

**Key actions:**
1. Opens scene file via FUN_00534b00/FUN_00587db0
2. Resolves vehicle struct from DAT_008ac394 (VehicleArray, stride 0x424) at param_2 index
3. Reads DAT_007cf7f4/DAT_007cf818 to determine game mode → difficulty level (1–4)
4. Tokenizes file content looking for `<>` enclosed tag fields:
   - NOTSPIN: writes spin countermeasure data if difficulty != 0
   - DASHLOW/DASHHIGH: writes dash display (rev lights) based on difficulty/vehicle data
   - VEHDIR: writes season directory path
   - TEAMDIR: extracts team directory from vehicle path
   - `<>` (unnamed tag): writes raw filename
5. Writes via FUN_005887b1 (formatted I/O) and FUN_00589898 (char write)
6. Closes file via FUN_005355a0

**Globals:** DAT_008ac394 (VehicleArray), DAT_007c569c (SessionType5), DAT_007cf7f4/DAT_007cf818 (game mode), DAT_005ec428 (SeasonName), DAT_005ec3d8 (SeasonDir), DAT_008ad25c (error buffer)

**Data passed to callees:** File handle, tag strings, vehicle index, difficulty level.

### Level 1: FUN_005887b1 — StringFormatNestedIO

**Trigger:** Called from SceneFileWriter for tag value output
**Purpose:** Formats strings and writes to file with mutex protection. Most complex I/O utility in chain.

**Key actions:**
1. Acquires mutex via FUN_0058c1b1
2. Writes via stream operation FUN_0058e41b
3. Formats via core engine FUN_0058d04d
4. Cleans up via FUN_0058e4a8
5. Releases mutex via FUN_0058c203

### Level 2: FUN_0058d04d — Core Format Engine

**Trigger:** Called from StringFormatNestedIO and PathSprintf
**Purpose:** Core printf-style format engine for string construction.

### Level 2: FUN_0058cf35 — Buffered Write

**Trigger:** Called from StringFormatNestedIO and PathSprintf
**Purpose:** Buffered write to file with overflow handling.

### Level 1: FUN_00589898 — BufferedCharWrite

**Trigger:** Called from SceneFileWriter for raw character output
**Purpose:** Writes individual characters to file with buffer management and mutex.

**Key actions:**
1. Acquires mutex via FUN_0058c1b1
2. Flushes buffer via FUN_0058cf35 when full
3. Releases mutex via FUN_0058c203

### Level 1: FUN_0058815f — PathSprintf

**Trigger:** Called from SceneFileWriter for path construction
**Purpose:** Formats path strings with buffer overflow checking.

### Level 1: FUN_004d7a50/004d7aa0 — Error Logging

**Trigger:** Called on error conditions
**Purpose:** Debug gate and debug log write.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004ddf90 | Vehicle index, scene file | Tag tokenization + write | Updated .gen file |
| FUN_005887b1 | Format string, values | Mutex-protected format + write | Written file content |
| FUN_0058815f | Path components | Sprintf with overflow check | Constructed path |
| FUN_00589898 | Character | Buffered char write | Written character |
| FUN_00534b00 | File path | Open | File handle |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008ad25c | ErrorBuffer | FUN_004ddf90 (writer) | Error message buffer |
| DAT_007c569c | SessionType5 | FUN_004ddf90 (reader) | 5=server mode |

## Notes

- All callees are I/O utility functions — no game logic modification
- Most complex callee: FUN_005887b1 (5 callees, I/O pipeline with mutex)
- FUN_005887b1 and FUN_0058815f share the core format engine FUN_0058d04d and buffered write FUN_0058cf35
- FUN_00589898 also shares FUN_0058c1b1/FUN_0058c203 mutex wrappers with FUN_005887b1
- All sub-callees are CRT-level I/O functions, not game-specific logic
- FUN_00587c20 and FUN_00588410 are stubs with no further call_graph entries

---
