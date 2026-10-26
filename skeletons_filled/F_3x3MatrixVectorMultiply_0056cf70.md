## F_3x3MatrixVectorMultiply_0056cf70 — Matrix3x3VectorMultiply

**Summary:** Performs two independent 3x3 matrix-vector multiplications. Each reads 3-component input vector and writes 3-component result to same buffer (6-double workspace). Used in vehicle physics system (suspension/joint force transforms).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), VehiclePhysicsJointSystemLoader (0056d930), BatchProcessingLoop3Passes (0056ec00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Pointer to first 3x3 matrix data block (28-byte header before 9 doubles) |
| this | 0x8 | R | — | Pointer to first vector buffer (6 doubles: input [0..2], output [3..5]) |
| this | 0xC | R | — | Pointer to second 3x3 matrix data block |
| this | 0x10 | R | — | Pointer to second vector buffer |
| this | 0x18 | R | — | Header/padding field within matrix data block before 9 matrix doubles |
| this | 0x20 | RW | — | Output vector component X (result element 0 of first multiply) |
| this | 0x28 | RW | — | Output vector component Y (result element 1 of first multiply) |
| this | 0x30 | RW | — | Output vector component Z (result element 2 of first multiply) |
| this | 0x38 | RW | — | Output vector component X (result element 0 of second multiply) |
| this | 0x40 | R | — | Matrix element [0][0] read for multiplication |
| this | 0x48 | R | — | Matrix element [0][1] read for multiplication |
| this | 0x50 | R | — | Matrix element [0][2] read for multiplication |
| this | 0x58 | R | — | Matrix element [1][0] read for multiplication |
| this | 0x60 | R | — | Matrix element [1][1] read for multiplication |
| this | 0x68 | R | — | matrix element (double) read for multiplication |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no conditional branches; always performs both multiplies.
