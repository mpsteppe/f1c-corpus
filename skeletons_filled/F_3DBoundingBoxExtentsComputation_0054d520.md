## F_3DBoundingBoxExtentsComputation_0054d520 — 3D Bounding Box Extents Computation

**Summary:** Scans vertex buffer entries to compute axis-aligned bounding box min/max extents (X, Y, Z) and writes the 24 corner coordinates plus center point into the output struct. Optionally computes the bounding sphere radius.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), PhysicsAudioVectorUpdate (004e2ad0), VertexBufferTransform (0054c6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8 | R | — | vertex count in current buffer entry |
| *(this+0x11C) | 0xC | R | — | pointer to vertex position data (float3 array) |
| *(this+0x11C) | 0x10 | R | — | vertex stride or interleave flag (not directly accessed in this function) |
| *(this+0x11C) | 0x14 | R | — | secondary vertex data field (not directly accessed in this function) |
| this | 0x14 | RW | — | bounding box corner: min-X, min-Y, max-Z (corner 0 X) |
| this | 0x18 | RW | — | bounding box corner: min-X, min-Y, max-Z (corner 0 Y) |
| this | 0x1C | RW | — | bounding box corner: min-X, min-Y, max-Z (corner 0 Z) |
| this | 0x20 | RW | — | bounding box corner: max-X, min-Y, max-Z (corner 1 X) |
| this | 0x24 | RW | — | bounding box corner: max-X, min-Y, max-Z (corner 1 Y) |
| this | 0x28 | RW | — | bounding box corner: max-X, min-Y, max-Z (corner 1 Z) |
| this | 0x2C | RW | — | bounding box corner: max-X, max-Y, max-Z (corner 2 X) |
| this | 0x30 | RW | — | bounding box corner: max-X, max-Y, max-Z (corner 2 Y) |
| this | 0x34 | RW | — | bounding box corner: max-X, max-Y, max-Z (corner 2 Z) |
| this | 0x38 | RW | — | bounding box corner: min-X, max-Y, max-Z (corner 3 X) |
| this | 0x3C | RW | — | bounding box corner: min-X, max-Y, max-Z (corner 3 Y) |
| this | 0x40 | RW | — | bounding box corner: min-X, max-Y, max-Z (corner 3 Z) |
| this | 0x44 | RW | — | bounding box corner: min-X, min-Y, min-Z (corner 4 X) |
| this | 0x48 | RW | — | bounding box corner: min-X, min-Y, min-Z (corner 4 Y) |
| this | 0x4C | RW | — | bounding box corner: min-X, min-Y, min-Z (corner 4 Z) |
| this | 0x50 | RW | — | bounding box corner: max-X, min-Y, min-Z (corner 5 X) |
| this | 0x54 | RW | — | bounding box corner: max-X, min-Y, min-Z (corner 5 Y) |
| this | 0x58 | RW | — | bounding box corner: max-X, min-Y, min-Z (corner 5 Z) |
| this | 0x5C | RW | — | bounding box corner: max-X, max-Y, min-Z (corner 6 X) |
| this | 0x60 | RW | — | bounding box corner: max-X, max-Y, min-Z (corner 6 Y) |
| this | 0x64 | RW | — | bounding box corner: max-X, max-Y, min-Z (corner 6 Z) |
| this | 0x68 | RW | — | bounding box corner: min-X, max-Y, min-Z (corner 7 X) |
| this | 0x6C | RW | — | bounding box corner: min-X, max-Y, min-Z (corner 7 Y) |
| this | 0x70 | RW | — | bounding box corner: min-X, max-Y, min-Z (corner 7 Z) |
| this | 0x74 | RW | — | spare / padding |
| this | 0x78 | RW | — | MMX/vertex format flags — bit 0x10 set when box has valid 3D extents |
| this | 0xDC | RW | — | bounding box center X (midpoint of min-X/max-X) |
| this | 0xE0 | RW | — | bounding box center Y (midpoint of min-Y/max-Y) |
| this | 0xE4 | RW | — | bounding box center Z (midpoint of min-Z/max-Z) |
| this | 0x118 | R | — | number of vertex buffer entries (outer loop count) |
| this | 0x11C | R | — | pointer to vertex buffer list (array of buffer descriptors) |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE0: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005b8984 | flt_5B8984 | R | MeshBoundMaxInit [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x11C) | 0x8 | > | 0 | vertex count per buffer entry: positive count means that entry has vertices to scan |
| this | 0x118 | > | 0 | buffer entry count: at least one vertex buffer entry exists — if zero, skip all scanning |

**Guard interpretation:** PASSES when `this+0x118 > 0` (at least one vertex buffer entry exists) AND each entry has `*(entry+0x8) > 0` (that buffer has vertices). If `this+0x118 <= 0`, the entire loop is skipped — bounding box is left at sentinel min/max values (±1e12). Individual entries with count ≤ 0 are skipped within the loop.