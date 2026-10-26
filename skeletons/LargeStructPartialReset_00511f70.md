## LargeStructPartialReset_00511f70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ThreeObjectCleanupChain (00512093)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x5D | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513cd3 | SafeDeleteGuardForThunkFUN00517ec8 | [LLM] |
| 00513d2f | ShortComputation_3d2f | [LLM] |
| 005179a2 | sub_5179A2 | [LLM] |
| 00517ec8 | ConditionalCall_7ec8 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
