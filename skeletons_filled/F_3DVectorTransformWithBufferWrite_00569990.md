## F_3DVectorTransformWithBufferWrite_00569990 — WriteRelativeTransformedPosition

**Summary:** Transforms world-space position to local space using object position and rotation matrix, writes result plus metadata into a ring buffer with 88-byte stride. Part of vehicle physics constraint point batching.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | position x component |
| this | 0xC | R | — | position y component |
| this | 0x14 | R | — | position z component |
| this | 0x1C | R | — | rotation matrix row 0 col 0 |
| this | 0x24 | R | — | rotation matrix row 0 col 1 |
| this | 0x2C | R | — | rotation matrix row 0 col 2 |
| this | 0x34 | R | — | rotation matrix row 1 col 0 |
| this | 0x3C | R | — | rotation matrix row 1 col 1 |
| this | 0x44 | R | — | rotation matrix row 1 col 2 |
| this | 0x4C | R | — | rotation matrix row 2 col 0 |
| this | 0x54 | R | — | rotation matrix row 2 col 1 |
| this | 0x5C | R | — | rotation matrix row 2 col 2 |
| this | 0x23C | R | — | write index counter, post-incremented |
| this | 0x240 | R | — | ring buffer base pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — function always executes fully with no early-return branches.
