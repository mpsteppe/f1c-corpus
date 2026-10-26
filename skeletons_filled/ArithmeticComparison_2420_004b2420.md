## ArithmeticComparison_2420_004b2420 — Compact vector unpack (int16 to float)

**Summary:** Inverse companion to sub_4B2310 — copies 3 dword values and converts 3 int16 values to float by multiplying by 1/2048 (0.00048828125). Unpacks compact vertex/vector data back to floating point.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4B6360 (004b6360), VehiclePhysicsTimeStep (004c73f0), VehicleTelemetryPositionAccumulator (004ec080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Source dword 0 (copied to a2[0]) |
| this | 0x4 | R | — | Source dword 1 (copied to a2[1]) |
| this | 0x8 | R | — | Source dword 2 (copied to a2[2]) |
| this | 0xC | R | — | Int16 value 0 (converted to float via * 1/2048) |
| this | 0xE | R | — | Int16 value 1 (converted to float via * 1/2048) |
| this | 0x10 | R | — | Int16 value 2 (converted to float via * 1/2048) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all fields read directly.
