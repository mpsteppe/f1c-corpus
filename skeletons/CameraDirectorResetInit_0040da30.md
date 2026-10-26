## CameraDirectorResetInit_0040da30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0), Steward_Post (004d4600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x24 | RW | 0 | [LLM] |
| this | 0x0 | RW | 18446744073709551615 | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x84 | RW | 0 | [LLM] |
| this | 0x88 | RW | — | [LLM] |
| this | 0x8C | RW | 0 | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |
| this | 0x94 | RW | 18446744073709551615 | [LLM] |
| this | 0x98 | RW | 0 | [LLM] |
| this | 0x9C | RW | 0 | [LLM] |
| this | 0xA0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x4) 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x8C: [LLM: once/conditional? does external poke survive?]
- this 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x98: [LLM: once/conditional? does external poke survive?]
- this 0x9C: [LLM: once/conditional? does external poke survive?]
- this 0xA0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54dc | dword_7C54DC | W | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | W | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d1b0 | SessionPhaseDispatchWithCascadeChecks | [LLM] |
| 0040d470 | SimpleSetterWithSubCall | [LLM] |
| 0040d490 | StructFieldInit | [LLM] |
| 00567f10 | F_9PointerArrayCleanup | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
