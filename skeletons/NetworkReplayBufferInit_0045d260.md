## NetworkReplayBufferInit_0045d260 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_463E20 (00463e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045d2d0 | sub_45D2D0 | R | [LLM] |
| 0059f0c4 | byte_59F0C4 | R | ObfuscationSourceData [DERIVED] |
| 005c5b68 | off_5C5B68 | R | [LLM] |
| 007d0fe8 | word_7D0FE8 | R | SessionPortBase [DERIVED] (also: Global state (used via uint cast) |
| 008d4680 | dword_8D4680 | RW | NetworkEncodeBuffer [DERIVED] (also: 8c` — Global state buffer) |
| 008d4684 | dword_8D4684 | W | XORPadData [DERIVED] |
| 008d4688 | dword_8D4688 | W | NetworkSaltBuffer [DERIVED] |
| 008d468c | dword_8D468C | W | XORKey_NetworkAuth [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562b50 | MemoryObjectAllocator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
