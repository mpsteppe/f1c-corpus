## ResourceTeardownWithStateArrayReset_00558990 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureFlagTestWithDispatch (00557630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x6C | RW | 0 | [LLM] |
| this | 0x74 | RW | 0 | [LLM] |
| this | 0xAC | RW | 0 | [LLM] |
| this | 0xB0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0xAC: [LLM: once/conditional? does external poke survive?]
- this 0xB0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | [LLM] |
| 00541040 | DrainingLoopFinalizer | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
