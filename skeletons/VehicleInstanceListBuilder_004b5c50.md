## VehicleInstanceListBuilder_004b5c50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x44)+0x0) | 0x88 | RW | — | [LLM] |
| *(this+0x10) | 0x84 | RW | — | [LLM] |
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x44) | 0x4 | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x44)+0x0) 0x88: [LLM: once/conditional? does external poke survive?]
- *(this+0x10) 0x84: [LLM: once/conditional? does external poke survive?]
- *(this+0x44) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd10 | flt_5ACD10 | R | EntityActiveDefault [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b5120 | VehicleIdentityStringComparison | [LLM] |
| 004b51e0 | DriverNameTeamCopy | [LLM] |
| 004ba830 | LinkedListNodeRemoval_a830 | [LLM] |
| 004baa50 | FixedSizeContainerConstructor | [LLM] |
| 004baf10 | sub_4BAF10 | [LLM] |
| 004bb0c0 | sub_4BB0C0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
