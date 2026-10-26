## RandomWeightedAudioMix_0043ec00 — RandomWeightedForceSplitter

**Summary:** Reads a pseudo-random noise value from a trig lookup table using a ring buffer counter, then splits the input force between ClampedSpringIntegrator (weighted by noise) and DoubleAccumulatorClamp (weighted by 1.0-noise). Part of vehicle physics noise/variation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ForceApplicationRouter (004ed1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e980 | ClampedSpringIntegrator | receives noise-weighted portion of input force |
| 0043ea70 | DoubleAccumulatorClamp | receives (1-noise)-weighted portion of input force |

**Guard conditions:** no branches — always executes weighted split
