## TireTemperatureSimStep_004c77d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IterateVehicles (004b3ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32C8 | R | — | [LLM] |
| this | 0x4894 | R | — | [LLM] |
| this | 0x48B8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x48B8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | [LLM] |
| 00462ff0 | ClampedPhysicsScaleWithThreshold | [LLM] |
| 004c71c0 | SetupCarLightingAndRender | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C8 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
