# Chain 184: SceneFileFilterBuilder — Scene Selection UI Filter Pipeline

Seed: FUN_004c6330  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 11 direct

---

## Overview

Builds filtered lists of scene files for the track selection UI. Handles category-based filtering (wet/dry/all tracks). If a filter path is provided, reads the filter file tokenizing categories and builds sorted filter lists via merge sort. If no filter path, enumerates all scene files from the SceneArray and builds unfiltered lists.

## Call Tree

```
FUN_004c6330 — SceneFileFilterBuilder  [called during track selection UI init]
  +-- FUN_004c62c0 — Resource List Cleanup  [init/clear output list]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry]
  +-- FUN_005897ca — File Read/Tokenizer  [reads filter file tokens]
  +-- FUN_00588410 — String Compare  [compares token against category names]
  +-- FUN_004c58a0 — Scene Filter Name Read  [reads "Filter Properties" from scene files]
  |     +-- FUN_004c5840 — [resource handle validate]
  |     +-- FUN_005679c0 — [string search]
  |     +-- FUN_00567970 — [string utility]
  +-- FUN_004c5c80 — Filter Match  [creates filter node if scene matches]
  +-- FUN_004c5e50 — Build Filter List 1 (Include)  [4 callees]
  |     +-- FUN_004c4cb0 — Scene Check  [validates scene entry]
  |     +-- FUN_004c58a0 — Field Reader  [reads scene filter field]
  |     +-- FUN_00566810 — Filter Match Check  [string match]
  |     +-- FUN_004c5c80 — Filter Node Creator  [creates linked list node]
  +-- FUN_004c5fd0 — Build Filter List 2 (Exclude)  [delegates to FUN_004c5e50]
  +-- FUN_004c6150 — Build Filter List 3 (Exclude/Negate)  [4 callees]
  |     +-- FUN_004c58a0 — Field Reader  [reads scene filter field]
  |     +-- FUN_00566810 — Filter Check  [string match]
  |     +-- FUN_00414370 — [free helper]
  |     +-- FUN_00587bcf — Memory Free  [deallocation]
  +-- FUN_004c6810 — Merge Sort Split  [recursive merge sort for filter lists]
  |     +-- FUN_004c6810 — (self)  [recursive split]
  |     +-- FUN_004c5d30 — Filter Comparison  [compares two scene entries]
  +-- FUN_004c5d30 — Filter Comparison  [comparator for merge sort ordering]
```

## Step-by-Step Trace

### Level 0: FUN_004c6330 — SceneFileFilterBuilder

**Trigger:** Called during track selection UI initialization to build scene file list for display.

**Called by:** Scene/UI module init — no callers recorded in call_graph.json (entry point from UI code).

**Purpose:** Builds filtered lists of scene files for track selection UI. Handles category-based filtering.

**Key actions:**
1. Calls FUN_004c62c0 to init/clear output list at param_1
2. Checks param_2 (filter path string): if provided and DAT_007d0398=0 or DAT_007d0410=5:
   - Reads filter file via FUN_005897ca (tokenizer)
   - Parses tokens into 3 categories via FUN_00588410 string compare
   - Builds 3 arrays of scene indices in 3 filter lists
   - Calls FUN_004c5e50/5fd0/6150 to build filter property lists per category
3. If no filter path: enumerates all scene files (DAT_008ac488 count, stride 0x18c)
   - Reads filter name via FUN_004c58a0
   - Matches filter via FUN_004c5c80 → linked list node
   - Appends to param_1 scene list
4. Merges sorted filter lists via FUN_004c6810 (recursive merge sort)
5. Stores result in param_1+8 (head), +0xc (tail), +0x10 (head copy), +0x14 (count), +0x18 (reset to 0)

**Data passed to callees:** param_1 (output list struct), param_2 (filter path string), category constants

### Level 1: Key Callees

**FUN_004c5e50 — Build Filter List 1 (Include)**
- 4 callees: validates scene entries, reads filter fields, matches strings, and creates linked list nodes
- Called once per category to build the filtered scene index list

**FUN_004c6810 — Merge Sort Split (recursive)**
- Recursive merge sort: splits linked list at midpoint
- Calls itself recursively (+ FUN_004c5d30 for comparisons)
- Produces sorted filter list by category order

**FUN_004c58a0 — Scene Filter Name Read**
- 3 callees: validates resource handles, searches strings
- Reads the "Filter Properties" field from each scene file entry in the SceneArray

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004c6330 | param_2 filter path | Check if filter provided | Filtered or full enumeration |
| FUN_005897ca | filter file path | Read + tokenize | Token array |
| FUN_00588410 | token, category name | String compare | Category match result |
| FUN_004c5e50 | category index | Build include list | Filtered scene index list |
| FUN_004c6810 | 3 filter lists | Recursive merge sort | Single sorted linked list |
| param_1 store | sorted list | Write to output struct | Head/tail/count at param_1+8/0xc/0x14 |

## Globals Read

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_008ac488 | SceneFileCount | FUN_004c6330 | Scene array size |
| DAT_008ac490 | SceneArray | FUN_004c6330 | Scene file entries |
| DAT_005d31ec | FilterPropertiesString | FUN_004c6330 | "Filter Properties" constant |
| DAT_007d0398 | PhotoFreeCameraFlag | FUN_004c6330 | Gates filter path check |
| DAT_007d0410 | RaceMode | FUN_004c6330 | Gates filter path check |

## Notes

- FUN_004c6810 is recursive (calls itself) — standard linked list merge sort
- The 3 filter list builders handle include/exclude/negate filter categories
- Filter tokens are compared against 3 category name patterns (stored in static data at DAT_005d30d8 etc.)
- The output is a sorted linked list of scene file indices for the track selection UI

---
