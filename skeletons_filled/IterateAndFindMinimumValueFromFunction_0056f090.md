## IterateAndFindMinimumValueFromFunction_0056f090 — FindMinimumPenetrationDepth

**Summary:** Iterates over an array of 580-byte vehicle physics body structs, calls sub_569DE0 on each with a parameter, and returns the minimum result value (penetration depth), defaulting to 1.0 if no bodies exist.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of vehicle physics body structs |
| this | 0x4 | R | — | Pointer to vehicle physics body array (stride 580) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00569de0 | sub_569DE0 | Compute penetration/distance for a physics body |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Body count |

**Guard interpretation:** PASSES when *this > 0 — iterates bodies calling sub_569DE0, tracks minimum value, returns smallest. BLOCKED (returns default 1.0) when *this <= 0 (no bodies to evaluate).
