## PhysicsObjectListManager_004b4e10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QuadrupleListCleanup (004b46f0), PitstopActionSet (004b6940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x70) | 0x0 | R | — | [LLM] |
| *(this+0x70) | 0x4 | RW | — | [LLM] |
| *(this+0x70) | 0x8 | R | — | [LLM] |
| *(this+0x70) | 0xC | R | — | [LLM] |
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x35 | RW | 0 | [LLM] |
| this | 0x39 | RW | 0 | [LLM] |
| this | 0x3D | RW | 0 | [LLM] |
| this | 0x41 | RW | 0 | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x70) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x35: [LLM: once/conditional? does external poke survive?]
- this 0x39: [LLM: once/conditional? does external poke survive?]
- this 0x3D: [LLM: once/conditional? does external poke survive?]
- this 0x41: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab700 | dword_8AB700 | RW | FreeListHead [DERIVED] |
| 008ab704 | dword_8AB704 | W | FreeListTailPtr [DERIVED] |
| 008ab708 | dword_8AB708 | W | GlobalAllocPoolNode [DERIVED] (also: global pool/pre-allocated node) |
| 008ab70c | dword_8AB70C | RW | FreeNodeCount [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bac20 | ShortComputation_ac20 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
