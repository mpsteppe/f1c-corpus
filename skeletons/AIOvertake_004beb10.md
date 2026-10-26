## AIOvertake_004beb10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BF10 (0046bf10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x342 | R | — | [LLM] |
| this | 0x350 | R | — | [LLM] |
| this | 0x354 | RW | — | [LLM] |
| this | 0x358 | R | — | [LLM] |
| this | 0x35C | RW | — | [LLM] |
| this | 0x360 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x354: [LLM: once/conditional? does external poke survive?]
- this 0x35C: [LLM: once/conditional? does external poke survive?]
- this 0x360: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bf0a0 | AIBehaviorInitialization | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
