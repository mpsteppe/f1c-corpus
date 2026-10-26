## LapSplitTimeEvent_004bc390 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerFrameRateThrottle (004d3740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004bc340 | sub_4BC340 | [LLM] |
| 004bc4e0 | LapCompletion | [LLM] |
| 004d5900 | EncodedDataWriterWithXOR | [LLM] |
| 004efbd0 | RayTriangleIntersectionWithBarycentricCoordinate | [LLM] |
| 0054c150 | FlagPropertyGetter | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 2 | [LLM] |
| this | 0xC | == | 0 | [LLM] |
| this | 0xC | == | 1 | [LLM] |
| this | 0x60 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
