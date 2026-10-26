## ClampedIndexAssignment_004a5bd0 — FloatToClampedIndex

**Summary:** Converts a float value `a2` into a zero-based integer index using parameters (base, step, upper bound). Computes `round((a2 - base) / step)`, then clamps to [0, max-1]. Stores the clamped result at offset 0x6C. Used by PitStopDecisionTireCompound for array indexing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopDecisionTireCompound (0042a3d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | Reference/base value (double) subtracted from input |
| this | 0x60 | R | — | Step/interval size (double) used as divisor |
| this | 0x68 | R | — | Upper bound (int); output clamped to [0, bound-1] |
| this | 0x6C | RW | 0 | Output clamped index (int); written with result 0 ≤ idx < bound |

**Written-by note (persistence):**
- this 0x6C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | CRT `ftol` — converts double to integer (truncation/rounding) |

**Guard conditions:** Checks `result >= 0` after computation. PASSES: clamp to [0, bound-1] and store. BLOCKED: when result < 0, forced to 0.