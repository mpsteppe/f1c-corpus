## WheelSurfaceContactFriction_004ce110 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelContactTransform (004ef180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |

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
| 004b9fb0 | ArithmeticComparison_9fb0 | [LLM] |
| 004cd6c0 | WheelContactParticle | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x40) | 0x4 | == | 6 | [LLM] |
| *(this+0x40) | 0x4 | == | 7 | [LLM] |
| *(this+0x40) | 0x4 | == | 8 | [LLM] |
| this | 0x3C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
