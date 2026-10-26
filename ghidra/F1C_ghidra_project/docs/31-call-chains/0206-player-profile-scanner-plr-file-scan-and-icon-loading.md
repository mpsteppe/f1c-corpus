# Chain: Player Profile Scanner — *.PLR file scan and icon loading

Seed: FUN_00468ee0  |  System: docs/08-file-formats.md  |  Depth: 4  |  Functions: ~18

---

## Overview

Player Profile Scanner (FUN_00468ee0) scans the player directory for `*.PLR` player profile files and loads associated profile icons for the player selection screen. It clears the existing profile list, iterates directory entries matching `*.PLR`, extracts player name, loads "ProfileIcon.bmp" (with fallback to "ProfileIcon_DFT.bmp"), registers the icon bitmap, and builds a linked list of profile entries. Called from FUN_004692a0 (Short Computation).

## Call Tree

```
FUN_00468ee0 — Player Profile Scanner  [trigger: player selection screen init]
  +-- FUN_0048d230 — Linked List Destruction  [clear existing profile list]
  +-- FUN_00404f70 — Conditional Free with Bit 0 Flag  [flag set]
  +-- FUN_00587bcf — Free Wrapper  [heap dealloc]
  +-- FUN_00565f80 — File Search Init  [start *.PLR search]
  +-- FUN_00566380 — Search Flag  [set search state]
  +-- FUN_005662d0 — Directory Entry Iterator  [iterate matches]
  +-- FUN_00565f20 — Linked List Node Peek  [next match]
  +-- FUN_00565eb0 — Search End  [cleanup search]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [path build]
  +-- FUN_00497ad0 — Bitmap Load  [load ProfileIcon.bmp]
  +-- FUN_0048d2b0 — Icon Register  [register bitmap + linked list]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry]
  +-- FUN_00469630 — Setup File Load and Finalize  [finalize list display]
  +-- FUN_00423a00 — Binary Search in String Table  [string copy]
```

## Step-by-Step Trace

### Level 0: FUN_00468ee0 — Player Profile Scanner

**Trigger:** Player selection screen initialization — called from FUN_004692a0
**Called by:** FUN_004692a0 (Short Computation)
**Purpose:** Scan for *.PLR files and load profile icons

**Key actions:**
1. Clear existing profile linked list at param_1+0x444 via FUN_0048d230
2. Init file search for `*.PLR` in DAT_005ec440 (profile directory)
3. For each match: strip extension, build path, load ProfileIcon.bmp (fallback: ProfileIcon_DFT.bmp)
4. Register icon via FUN_0048d2b0, append to linked list
5. Set list head to current entry (or null if empty), finalize via FUN_00469630

**Data passed to callees:** param_1 = profile manager struct with linked list at +0x444, count at +0x450

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Search | *.PLR pattern | Init file search | search handle |
| Iterate | directory stream | Read next match | filename string |
| Load | filename | Load ProfileIcon.bmp | bitmap data |
| Register | bitmap + name | Append to linked list | linked list entry |
| Finalize | list head | Set current entry | display-ready list |

## Notes

- All callees are leaf or near-leaf utility functions — no deep subtrees
- Directory search functions (FUN_00565f80/FUN_005662d0/FUN_00565f20) are platform file I/O wrappers
- Two bitmap load attempts: primary "ProfileIcon.bmp" then fallback "ProfileIcon_DFT.bmp"
- Globals used: DAT_005ec440 (profile dir), DAT_005c6960 (*.PLR), DAT_005c6950 (ProfileIcon.bmp)

---
