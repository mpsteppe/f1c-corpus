## VelocityThresholdCheck_004f1aa0 — velocity / contact threshold gate

**Summary:** Checks vehicle velocity against range [2,4] with an additional distance comparison guard. Part of collision/contact detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_49B7A0 (0049b7a0), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | enable flag for velocity threshold check (zero = skip) |
| this | 0x3444 | R | — | velocity value compared against threshold range [2,4] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 007c9080 | byte_7C9080 | R | SystemDefaultReturnValue [DERIVED] (also: ` -- default return value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004effd0 | DistanceComparison | compares distance metric for contact validation |

**Guard conditions:** Field at 0x32BC: if 0 → early return byte_7C9080 (skip threshold check). Velocity at 0x3444 must be >= 2 and <= 4 to pass. Condition flags (C0/C2 from prior FPU compare) must be clear OR DistanceComparison must return false.
