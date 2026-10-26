## ShortComputation_8e30_00568e30 — ZeroInitFourFields

**Summary:** Zeros four struct fields at offsets 0x0, 0x230, 0x238, 0x240, then calls MultiFieldPointerCleanupWithNullChecks. Simple initialization routine.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_40FE50 (0040fe50), VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | field zeroed (likely pointer or counter) |
| this | 0x230 | RW | 0 | field zeroed (likely pointer or counter) |
| this | 0x238 | RW | 0 | field zeroed (likely pointer or counter) |
| this | 0x240 | RW | 0 | field zeroed (likely pointer or counter) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x230: recalc every frame — external poke does NOT persist
- this 0x238: recalc every frame — external poke does NOT persist
- this 0x240: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568f20 | MultiFieldPointerCleanupWithNullChecks | cleans up / frees pointers referenced by struct fields |

**Guard conditions:** None — unconditional assignments, no branches or early returns.
