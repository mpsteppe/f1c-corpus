# Chain 201: Scene List Builder from Global Array — Scene File Enumeration

Seed: FUN_00415c40  |  System: docs/08-file-formats.md  |  Depth: 2  |  Functions: 6 callees

---

## Overview

FUN_00415c40 builds a linked list of scene entries from the global SceneArray (DAT_008ac490, stride 0x18c). It iterates DAT_008ac488 scene file count entries, allocates a 0x5c-byte node per scene, initializes sub-structs via FUN_00415520 (4x) and FUN_00414fe0, reads the scene name at stride offset +0x104, and calls FUN_00414e60 for each scene. The chain is similar to FUN_00415780 but for scene data. Triggered at startup. No documented callers.

## Call Tree

```
FUN_00415c40 — Scene List Builder from Global Array  [trigger: game startup]
  +-- FUN_00587bcf — Free Wrapper (clear existing list)  [leaf]
  +-- FUN_00418cf0 — Short Computation / Struct Init  [docs/20]
  |     +-- FUN_00415c30 — Null-safe Pointer Dereference  [leaf, docs/08]
  +-- FUN_00415520 — Small Entry Struct Init  [docs/19, called 4x]
  |     +-- FUN_00418b70 — Short Computation (Table Lookup with Sentinel)  [docs/20]
  +-- FUN_00414fe0 — Text Format Struct Initializer (Small)  [docs/19]
  |     +-- FUN_00418b90 — Score/Threshold Gate Check  [docs/06]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, docs/20]
  +-- FUN_00414e60 — Commentary TV/PWS Path Builder  [docs/09]
        +-- FUN_00417f60 — Track Name/Display ID Lookup  [docs/09]
        +-- FUN_004b0220 — Path Truncation Utility  [docs/20]
        +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00415c40 — Scene List Builder from Global Array

**Trigger:** Called during game startup to build scene list from global array.
**Called by:** No documented callers (callers.json empty)
**Purpose:** Builds linked list of scene entries from DAT_008ac490.

**Key actions:**
1. Clears existing scene list at +0x20
2. Loops over SceneFileCount (DAT_008ac488)
3. For each: allocates 0x5c-byte node
4. Initializes sub-structs (FUN_00415520 x4, FUN_00414fe0)
5. Reads scene name at stride offset +0x104
6. Calls FUN_00414e60 per scene for path building
7. Appends to linked list at +0x20

**Globals read:**
- DAT_008ac488 (SceneFileCount) — number of scenes
- DAT_008ac490 (SceneArray, stride 0x18c) — scene data array

### Level 1: FUN_00414e60 — Commentary TV/PWS Path Builder

**Trigger:** Called per scene entry to build path strings.
**Purpose:** Builds commentary/TV camera path strings for the scene.

**Key actions:**
1. Looks up track name/display ID via FUN_00417f60
2. Truncates path via FUN_004b0220
3. Copies strings via FUN_00566650

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| DAT_008ac490 | SceneArray | Iterate stride 0x18c | Per-scene data |
| FUN_00415c40 | Scene data at +0x104 | Name extraction | Scene name string |
| FUN_00414e60 | Scene data | Path building | TV/PWS path strings |
| Linked list | Nodes | Append at +0x20 | Scene linked list |

## Notes

- 6 callees, similar pattern to Vehicle List Builder (chain 200)
- Cross-system: FUN_00414e60 belongs to docs/09 (track system) — commentary/TV path building
- FUN_00415520 called 4x per scene (likely camera/viewport entries)
- Stride 0x18c vs VehicleArray stride 0x424 — scene data is smaller per entry

---
