## LinkedListDestructorWithChildCleanup_00565e20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), FileEnumerationByExtension (00421b10), PlayerNameNeverUsedProfileFileCreateRead (004b03f0), TGATextureFileScanner (004c3a00), sub_4C84A0 (004c84a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(obj+0x0) | 0x8 | R | — | [LLM] |
| obj | 0x0 | RW | 0 | [LLM] |
| obj | 0x4 | RW | 0 | [LLM] |
| obj | 0x8 | RW | 0 | [LLM] |
| obj | 0xC | RW | 0 | [LLM] |
| obj | 0x210 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x0: [LLM: once/conditional? does external poke survive?]
- obj 0x4: [LLM: once/conditional? does external poke survive?]
- obj 0x8: [LLM: once/conditional? does external poke survive?]
- obj 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | [LLM] |
| 00565d50 | EnhancedListCleanupWithSubObjectDelete | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
