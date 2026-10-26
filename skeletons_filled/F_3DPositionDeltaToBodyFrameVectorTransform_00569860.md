## F_3DPositionDeltaToBodyFrameVectorTransform_00569860 — AppendBodyFramePositionEntry

**Summary:** Transforms a world-space position delta (a2 minus vehicle position at offsets 0x4/0xC/0x14) into body frame using rotation matrix and appends it to a buffer at this[560]. Increments element count at this[556] (offset 0x22C). Each entry is 56 bytes with body-frame vector plus metadata.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | vehicle world position X |
| this | 0xC | R | — | vehicle world position Y |
| this | 0x14 | R | — | vehicle world position Z |
| this | 0x1C | R | — | rotation matrix row 0 col 0 |
| this | 0x24 | R | — | rotation matrix row 0 col 1 |
| this | 0x2C | R | — | rotation matrix row 0 col 2 |
| this | 0x34 | R | — | rotation matrix row 1 col 0 |
| this | 0x3C | R | — | rotation matrix row 1 col 1 |
| this | 0x44 | R | — | rotation matrix row 1 col 2 |
| this | 0x4C | R | — | rotation matrix row 2 col 0 |
| this | 0x54 | R | — | rotation matrix row 2 col 1 |
| this | 0x5C | R | — | rotation matrix row 2 col 2 |
| this | 0x22C | R | — | element count (incremented after append) |
| this | 0x230 | R | — | pointer to buffer base for body-frame entries |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional append with count increment.
