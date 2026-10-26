## sub_4BDE20_004bde20 — GridCellAssignment

**Summary:** Computes 2D grid cell coordinates (0-7 range) from an object's bounding box using grid origin/scale fields at offsets 0x924-0x930, then assigns the object to all overlapping cells in the 8x8 grid.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_f0d0 (0040f0d0), SceneObjectLoaderStateMachine (0040f1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | R | — | grid X origin (used in coordinate computation) |
| this | 0x928 | R | — | grid X scale inverse |
| this | 0x92C | R | — | grid Y origin (used in coordinate computation) |
| this | 0x930 | R | — | grid Y scale inverse |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd860 | DynamicArrayPush | add object to grid cell's object list |
| 00587bdc | CRTFtol | convert float grid coordinate to integer cell index |

**Guard conditions:** none — always processes. Coordinates are clamped to 0-7 range. If bounding box is degenerate (v5 > v7 or v9 > v11), skips cell iteration. The sentinel flag v16 is set when any coordinate falls outside [0, 7) range, triggering a fallback push to this+576.
