# Chain: PITANIMS.MAS Animation File Loader — Pit Crew Anim Load

Seed: FUN_004a3220  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 9

---

## Overview

Opens and loads the `PITANIMS.MAS` archive containing pit crew animations. Resolves the directory path, pushes search path, opens the MAS archive, delegates to the pit crew animation loader (FUN_004a2a90), then closes the archive and restores the search path. Called during pit system initialization.

## Call Tree

```
FUN_004a3220 — PITANIMS.MAS Animation File Loader  [pit system init]
  +-- FUN_004a29a0 — Array/Resource Cleanup
  +-- FUN_00566650 — String Copy with Buffer Realloc (name set)
  +-- FUN_0053c800 — String Registry (Dedup List) [path push]
  +-- FUN_0053cbc0 — MAS Open [undocumented]
  +-- FUN_004a2a90 — Pit Crew Animation Loader
  +-- FUN_0053ce40 — Physics Object Linked List Removal [MAS close]
  |     +-- FUN_0055fe30 — list remove
  |     +-- FUN_00557470 — node free
  |     +-- FUN_00587bcf — free
  |           +-- FUN_0058aa6f — free
  +-- FUN_0053c900 — String Match with Flag Set [path pop]
  |     +-- FUN_00589901 — string match
  |     +-- FUN_0053ca00 — flag set
  +-- FUN_00587bcf — Free Wrapper
        +-- FUN_0058aa6f — free
```

## Step-by-Step Trace

### Level 0: FUN_004a3220 — PITANIMS.MAS Animation File Loader

**Trigger:** Called during pit system initialization.
**Called by:** No callers in knowledge graph (likely called from pit initialization dispatch).
**Purpose:** Opens PITANIMS.MAS, loads pit crew animations, closes archive.

**Key actions:**
1. Resolves directory path from param_1, truncates to parent directory
2. Calls FUN_0053c800 to push search path
3. Calls FUN_0053cbc0 to open PITANIMS.MAS
4. Calls FUN_004a2a90 (pit crew anim loader)
5. Calls FUN_0053ce40 to close MAS archive
6. Calls FUN_0053c900 to restore search path
7. Calls FUN_00587bcf for cleanup

### Level 1: FUN_0053cbc0 — MAS Open [undocumented]

**Trigger:** Opens MAS archive file.
**Purpose:** Opens the `PITANIMS.MAS` file archive for reading animation data.

### Level 1: FUN_004a2a90 — Pit Crew Animation Loader

**Trigger:** Called after MAS archive is opened.
**Purpose:** Parses and loads pit crew animation data from the MAS archive.

### Level 1: FUN_0053ce40 — MAS Close / Linked List Removal

**Trigger:** Called to close MAS archive.
**Purpose:** Removes archive from open file list, frees resources.

### Level 1: FUN_0053c900 — Path Pop / String Match

**Trigger:** Called to restore search path.
**Purpose:** Pops the search path that was pushed before opening MAS.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Path resolve | param_1 dir | truncate | parent dir |
| Path push | parent dir | FUN_0053c800 | search path set |
| MAS open | PITANIMS.MAS | FUN_0053cbc0 | archive handle |
| Anim load | archive handle | FUN_004a2a90 | anim data loaded |
| MAS close | archive handle | FUN_0053ce40 | resources freed |
| Path pop | — | FUN_0053c900 | original path restored |

## Notes

- 8 callees, linear pipeline (open → load → close).
- FUN_0053ce40 (MAS close) has 3 sub-callees but they are generic list/alloc ops.
- FUN_0053cbc0 (MAS open) is [undocumented] — likely a simple archive open wrapper.
- Clean, single-purpose chain with no branching.

---
