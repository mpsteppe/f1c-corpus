## WheelSurfaceContactFriction_004ce110 — WheelContactFrictionParticle

**Summary:** Compute wheel contact friction and spawn surface particles. Compares velocity difference against threshold, computes perpendicular friction vectors, iterates contact surface types (6=grass/dirt, 7=?, 8=wet) to determine particle color and size, then spawns WheelContactParticle.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelContactTransform (004ef180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | R | — | surface type in each contact slot |
| this | 0x3C | R | — | contact slot count |
| this | 0x40 | R | — | pointer to contact slot array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 005acebc | flt_5ACEBC | R | RainDropAlphaMult [DERIVED] |
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |
| 005acec8 | flt_5ACEC8 | R | CollisionDistThresholdSq [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9fb0 | ArithmeticComparison_9fb0 | compare scoring gate value |
| 004cd6c0 | WheelContactParticle | spawn wheel contact particle with computed color/size |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x40) | 0x4 | == | 6 | surface type grass/dirt |
| *(this+0x40) | 0x4 | == | 7 | surface type (unknown) |
| *(this+0x40) | 0x4 | == | 8 | surface type wet |
| this | 0x3C | > | 0 | contact slot count |

**Guard interpretation:** Outer guard: ArithmeticComparison_9fb0 on scoring gate must pass, AND velocity difference squared > 0.01. Inner guard: iterates contact slots, processes each with type 6 (grass/dirt green channel), 7 (scale * 254 color), or 8 (scale * 63.5 color). Blocked when scoring gate fails, velocity below threshold, or velocity > 400 (too fast for detailed particles).
