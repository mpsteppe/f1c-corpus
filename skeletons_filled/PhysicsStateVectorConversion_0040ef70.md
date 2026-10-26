## PhysicsStateVectorConversion_0040ef70 — PhysicsStateVectorConversion

**Summary:** Converts physics state vector (13 floats) into sub-object fields: sets position + offset, copies components, applies rotation tensor matrix transform, and calls computation subroutine. Mode-based dispatch (0-5). Part of physics/vehicle state system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelControllerInputDecoder (00410bc0), ShortComputation_1330 (00411330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Position X component (this[3]) copied from input vector[1] |
| this | 0x10 | RW | — | Position Y component (this[4]) copied from input vector[2] |
| this | 0x14 | RW | — | Position Z component (this[5]) copied from input vector[3] |
| this | 0x1C | R | — | Mode selector (this[7], values 0-5) |
| this | 0x20 | R | — | Pointer to sub-object (this[8]) for data storage |
| this | 0x40 | RW | — | Field written during conversion pipeline |
| this | 0x44 | RW | — | Field written during conversion pipeline |
| this | 0xF4 | R | — | Field read during conversion pipeline |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f0b0 | jpt_40EF85 | R | Jump table for 6-case switch (0-5) |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f0d0 | ShortComputation_f0d0 | Final computation subroutine after conversion |
| 0054b4d0 | sub_54B4D0 | Processes first 3 vector components with 3 additional floats |
| 005691d0 | F_3x3RotationTensorMatrixTransform | Applies 3x3 rotation tensor matrix transform to vector[4-6] |
| 00569280 | Copy6DwordsToStructCall | Copies 6 DWORDs from vector[10-12] to struct |

**Guard conditions:** this[7] (mode) 0/2/4 → set sub-object[+32] = *a2 + 100, sub-object[+36] = *a2. Modes 1/3/5 → same operation (identical code path). default → skip sub-object write. Always copies position components and runs matrix transforms.
