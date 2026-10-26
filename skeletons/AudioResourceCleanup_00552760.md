## AudioResourceCleanup_00552760 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCompareLinkedListSearch (0053d130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x64 | RW | 0 | [LLM] |
| this | 0x868 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x64: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053cb90 | sub_53CB90 | [LLM] |
| 00540eb0 | ObjectResetWithVirtualRelease | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
