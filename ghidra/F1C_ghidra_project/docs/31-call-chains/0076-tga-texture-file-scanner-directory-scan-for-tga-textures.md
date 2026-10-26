# Chain: TGA Texture File Scanner — Directory scan for TGA textures

Seed: FUN_004c3a00  |  System: docs/08-file-formats.md  |  Depth: 2  |  Functions: 14

---

## Overview

Scans a directory for `*.tga` files matching a specific scene/track directory structure. Part of the texture loading pipeline. Builds "*.tga" filter, iterates found files, strips extensions, compares directory depth against scene path, and creates linked list node for each matching file. Returns output list in param_2.

## Call Tree

```
FUN_004c3a00 — TGA Texture File Scanner  [trigger: texture loading pipeline]
  +-- FUN_00565dc0 — FileSearchInit  [initialize file search]
  +-- FUN_00565eb0 — SearchPathSet  [set search path]
  +-- FUN_00565f80 — FilterSet  [set *.tga filter]
  +-- FUN_00566380 — SearchFlag  [set search flags]
  +-- FUN_00565f50 — SearchStart  [begin search]
  +-- FUN_005662d0 — SearchIterate  [iterate results]
  +-- FUN_00565ef0 — FilePathGet  [get file path]
  +-- FUN_00565f20 — SearchNext  [next result]
  +-- FUN_00565e20 — SearchEnd  [end search]
  +-- FUN_00588410 — StringCompare  [string compare]
  +-- FUN_00566650 — PathRegistry  [register path — docs/09]
  +-- FUN_00566810 — FileRead  [read file content]
  +-- FUN_00587bcf — Free  [free memory]
```

## Step-by-Step Trace

### Level 0: FUN_004c3a00 — TGA Texture File Scanner

**Trigger:** Called from texture/scene file loading pipeline
**Called by:** Part of texture asset loading
**Purpose:** Scans directory for `*.tga` files matching scene directory structure.

**Key actions:**
1. Directory path from param_1 (string pointer), output linked list stored in param_2
2. Builds "*.tga" filter via FUN_00565dc0/FUN_00565eb0/FUN_00565f80/FUN_00565f50
3. For each found file: strips extension, extracts directory path, checks depth (counts `\` separators)
4. Extracts 2nd-level directory name and compares against scene path
5. If directory matches: checks file content starts with scene path via FUN_00566810
6. Creates linked list node with file info, appends to param_2
7. Falls through to FUN_00565e20 to close search

**Data passed to callees:** param_1 (directory path string), param_2 (output list pointer)

### Level 1: All 13 callees

All callees are file I/O, string, or path utility functions. All are leaf functions with no further documented callees.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004c3a00 | param_1 (directory path) | Init file search with *.tga filter | Search handle |
| FUN_004c3a00 | Found files | Strip extension, compare scene path | Matching file list |
| FUN_004c3a00 | param_2 | Append matching files as linked list nodes | Output list |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005d3074 | "*.tga" filter string | (read by FUN_004c3a00) | TGA file filter constant |

## Notes

- All callees are file system utility functions — no game logic
- FUN_00566650 (PathRegistry) is cross-system to docs/09-track-system.md
- String comparison via FUN_00588410 for directory matching

---
