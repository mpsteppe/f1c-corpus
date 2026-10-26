## UtilityFunction_2950_00542950 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70), MemoryAllocationWithFallback (00543a80), sub_544740 (00544740), sub_54FEC0 (0054fec0), sub_551FD0 (00551fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053f720 | sub_53F720 | [LLM] |
| 005426e0 | sub_5426E0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
