## LocalToWorldCoordinateTransform_004e2070 — LocalToWorldCoordinateTransform

**Summary:** Transforms local 3D coordinates to world space. Adds camera-relative offsets (this[573]+this[576] etc.), multiplies by rotation matrix (this[8..16] = offset 0x20-0x40), adds base position (this[2..4] = offset 0x8-0x10), copies 3x3 matrix, and calls sub_567120 with position vector. Camera world-space transform.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | base position X for output |
| this | 0xC | R | — | base position Y for output |
| this | 0x10 | R | — | base position Z for output |
| this | 0x20 | R | — | rotation matrix element [0][0] |
| this | 0x24 | R | — | rotation matrix element [0][1] |
| this | 0x28 | R | — | rotation matrix element [0][2] |
| this | 0x2C | R | — | rotation matrix element [1][0] |
| this | 0x30 | R | — | rotation matrix element [1][1] |
| this | 0x34 | R | — | rotation matrix element [1][2] |
| this | 0x38 | R | — | rotation matrix element [2][0] |
| this | 0x3C | R | — | rotation matrix element [2][1] |
| this | 0x40 | R | — | rotation matrix element [2][2] |
| this | 0x8F4 | R | — | camera-relative offset component X |
| this | 0x8F8 | R | — | camera-relative offset component Y |
| this | 0x8FC | R | — | camera-relative offset component Z |
| this | 0x900 | R | — | additional position offset X |
| this | 0x904 | R | — | additional position offset Y |
| this | 0x908 | R | — | additional position offset Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567120 | sub_567120 | unknown — processes position vector and integer parameter |

**Guard conditions:** None — full transform always applied.
