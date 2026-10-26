## ShortToFloatVectorUnpack_004b2800 — Int16 vector 2-component unpack (scale 1/512)

**Summary:** Converts 2 int16 values to float by multiplying by 0.001953125 (1/512) and writes to X/Z float output with Y set to 0. Unpacks compact 2D vector data.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), AudioParameterInterpolation (004ff680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | Int16 X component (converted * 1/512 → output float) |
| this | 0x2A | R | — | Int16 Z component (converted * 1/512 → output float) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4d8 | flt_59E4D8 | R | physics constant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all fields read directly.
