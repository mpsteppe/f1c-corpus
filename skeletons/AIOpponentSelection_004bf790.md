## AIOpponentSelection_004bf790 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIDriverCountSetup (004bfd90), GameFilterDataLoader (004c0db0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x4) | 0x4 | RW | 0 | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(obj+0x4) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d266c | aSNotNotai | R | String_SNotNotai [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac36c | dword_8AC36C | R | Unknown_VehicleSetup_8AC36C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bf6a0 | sub_4BF6A0 | [LLM] |
| 004bf730 | sub_4BF730 | [LLM] |
| 004bfa00 | AIPathPerformanceFunction | [LLM] |
| 004c2e20 | MergeSortLinkedListByFloat | [LLM] |
| 004c4d50 | sub_4C4D50 | [LLM] |
| 004c5070 | RandomVehicleSelector | [LLM] |
| 004c50e0 | GuardedListAccessor | [LLM] |
| 005871f0 | ReadFieldAtOffset0x14 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
