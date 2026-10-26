## AICollision_004bef60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | R | — | [LLM] |
| this | 0x341 | R | — | [LLM] |
| this | 0x344 | R | — | [LLM] |
| this | 0x35C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aeb0 | DriverSetupParamLookupByID | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
