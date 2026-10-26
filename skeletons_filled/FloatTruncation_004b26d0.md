## FloatTruncation_004b26d0 — Byte/int16 to float unpack with truncation

**Summary:** Converts 2 signed bytes and 1 signed int16 to float by scaling (0.05, 0.002) and applying truncation via CRTFtol. Unpacks compact packed data to floating point for physics calculations.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Signed byte 0 (scaled * 0.05, truncated to float) |
| this | 0x25 | R | — | Signed byte 1 (scaled * 0.05, truncated to float) |
| this | 0x26 | R | — | Signed int16 (scaled * 0.002, truncated to float) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 005accb0 | flt_5ACCB0 | R | ClutchCatchSpeedScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Truncate float to integer (floor/round toward zero) |

**Guard conditions:** No guard conditions — all fields read directly.
