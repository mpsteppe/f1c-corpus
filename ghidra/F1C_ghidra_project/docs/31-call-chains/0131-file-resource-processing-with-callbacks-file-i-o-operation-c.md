# Chain: File Resource Processing with Callbacks — File I/O Operation Chain

Seed: FUN_00409770  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 8

---

## Overview

File resource processing function that opens a file for read, processes it, and optionally writes output. Toggles file attributes, handles I/O via callback functions, and manages file handle lifecycle. Used for resource file loading with post-processing.

## Call Tree

```
FUN_00409770 — File Resource Processing with Callbacks  [trigger: resource file load]
  +-- FUN_0058ba36 — Toggle File Read-Only Attribute via Win32 API  [removes read-only flag]
  |     +-- FUN_00587b3e — Boolean-to-Int Conversion
  +-- FUN_005668b0 — Zero-Init Small Struct  [initializes file I/O struct]
  +-- FUN_00566a70 — Open File for Read  [opens source file, returns handle]
  +-- FUN_00566940 — Open File for Write  [opens output file, returns handle]
  +-- FUN_00566b90 — Conditional File Handle Close with Flag Dispatch  [closes file handle]
  |     +-- FUN_00587bcf — Free Wrapper
  |     +-- FUN_005668d0 — Sub-Call with Conditional Field Free
  +-- FUN_005668d0 — Sub-Call with Conditional Field Free  [conditional resource cleanup]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
```

## Key Actions

1. Toggles source file read-only attribute (FUN_0058ba36) via SetFileAttributesA
2. Allocates and zero-initializes file I/O struct (FUN_005668b0)
3. Opens source file for read (FUN_00566a70)
4. Opens output file for write (FUN_00566940)
5. Processes data through read/write callbacks
6. Conditionally closes handles and frees resources (FUN_00566b90, FUN_005668d0)

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Source file path | Open for read | File handle |
| Output file path | Open for write | File handle |
| File data | Callback processing | Processed output |
| File handles | Conditional close | Handle released |

## Notes

- 6 direct callees, 2 with sub-callees (depth 2)
- File I/O wrappers in docs/06-session-race-logic.md range (FUN_00566a70, FUN_00566940)
- Uses Win32 file attribute API (SetFileAttributesA via FUN_0058ba36)
- No ## FUN_ entry exists in docs — this function is only in functions.json as "File Resource Processing with Callbacks"

---
