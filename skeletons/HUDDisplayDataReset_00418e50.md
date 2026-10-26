## HUDDisplayDataReset_00418e50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x350 | RW | 0 | [LLM] |
| this | 0x4F0 | RW | 0 | [LLM] |
| this | 0x4F4 | RW | 0 | [LLM] |
| this | 0x4F8 | RW | 0 | [LLM] |
| this | 0x4FC | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x69C | RW | 0 | [LLM] |
| this | 0x83C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x350: [LLM: once/conditional? does external poke survive?]
- this 0x4F0: [LLM: once/conditional? does external poke survive?]
- this 0x4F4: [LLM: once/conditional? does external poke survive?]
- this 0x4F8: [LLM: once/conditional? does external poke survive?]
- this 0x4FC: [LLM: once/conditional? does external poke survive?]
- this 0x69C: [LLM: once/conditional? does external poke survive?]
- this 0x83C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418ee0 | AITargetDriverSelection | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
