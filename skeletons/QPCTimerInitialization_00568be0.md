## QPCTimerInitialization_00568be0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), AutoJoinRetryLoop (004637a0), LargeStructInitialization (00464c10), sub_4989E0 (004989e0), CarPhysicsStateInitializer (004b57f0), ResourceFileLoader (004f9d60), VidMan_Enter (004fa000), TimerInitWithSEH (005835f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x48 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | [LLM] |
| 0059e240 | QueryPerformanceFrequency | R | [LLM] |
| 005af448 | dbl_5AF448 | R | TimerFreqScale [DERIVED] (also: ` — timer frequency scaling constant) |
| ff00000000005406 | byte_FF00000000005406 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
