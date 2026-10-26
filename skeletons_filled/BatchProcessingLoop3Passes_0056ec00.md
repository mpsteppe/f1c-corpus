## BatchProcessingLoop3Passes_0056ec00 — BatchProcessMatrixTransform3Passes

**Summary:** Processes three batches of physics constraint data: 3x3 matrix-vector multiply, 3x3 matrix inverse coordinate transform, and constraint-specific solve (sub_56D2D0), each operating on arrays of 48 or 72-byte structs.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_56ECF0 (0056ecf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | First pass count (wheel body count) |
| this | 0xC | R | — | First pass array pointer (wheel body array, stride 48) |
| this | 0x10 | R | — | Second pass count (suspension body count) |
| this | 0x14 | R | — | Second pass array pointer (suspension body array, stride 48) |
| this | 0x18 | R | — | Third pass count (constraint count) |
| this | 0x1C | R | — | Third pass array pointer (constraint array, stride 72) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056cf70 | F_3x3MatrixVectorMultiply | Multiply 3x3 matrix by 3D vector for wheel body |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | Apply inverse coordinate transform for suspension body |
| 0056d2d0 | sub_56D2D0 | Constraint-specific solve step |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | > | 0 | Wheel body count (this[2]) |
| this | 0x10 | > | 0 | Suspension body count (this[4]) |

**Guard interpretation:** PASSES for each batch when its count > 0 — iterates calling the respective transform function. BLOCKED (skipped) when count <= 0. Third batch (this[6]) always enters loop body but loop condition checks v7 < result so effectively same guard.
