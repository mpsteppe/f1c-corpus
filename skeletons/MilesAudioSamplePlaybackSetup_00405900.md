## MilesAudioSamplePlaybackSetup_00405900 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | 0 | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3e0 | _AIL_set_sample_file@12 | R | [LLM] |
| 0059e3e8 | _AIL_set_sample_loop_count@8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405b90 | F_3DSoundPositioningUpdate | [LLM] |
| 00405e60 | PhysicsCollisionResponseComputation | [LLM] |
| 004060c0 | MilesSoundSampleProcessorSetup | [LLM] |
| 004070e0 | SpatialQueryWithWeightedDistanceSelection | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
