## SurfaceHeightfieldCollisionCallback_00404250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x170 | RW | — | [LLM] |
| this | 0x174 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x170: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004038e0 | SpatialNearestNeighborQueryWithPlaneTest | [LLM] |
| 004046b0 | MemoryAllocation | [LLM] |
| 00404790 | ShortComputation_4790 | [LLM] |
| 004047d0 | CountedLoopCallToElementUpdate | [LLM] |
| 004faf60 | sub_4FAF60 | [LLM] |
| 004fb260 | sub_4FB260 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | <= | 0 | [LLM] |
| this | 0x130 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
