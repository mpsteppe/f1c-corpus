## PitTimerStateInit_004d23d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | — | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC1 | RW | 0 | [LLM] |
| this | 0xC2 | RW | 0 | [LLM] |
| this | 0xD8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xB0: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]
- this 0xC1: [LLM: once/conditional? does external poke survive?]
- this 0xC2: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042d140 | sub_42D140 | [LLM] |
| 004bc2d0 | sub_4BC2D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
