## MediaBufferPlaybackManager_0048d9d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE8) | 0x0 | R | — | [LLM] |
| *(this+0xEC) | 0x4 | R | — | [LLM] |
| *(this+0xF0) | 0x0 | R | — | [LLM] |
| obj | 0x10 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x114 | RW | — | [LLM] |
| this | 0x118 | RW | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x120 | RW | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x10C: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]
- this 0x11C: [LLM: once/conditional? does external poke survive?]
- this 0x120: [LLM: once/conditional? does external poke survive?]
- this 0x124: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004862c0 | UIStringAccessor_62c0 | [LLM] |
| 004862e0 | UIStringAccessor_62e0 | [LLM] |
| 00486460 | ConditionalDelegation_6460 | [LLM] |
| 00486720 | ShortComputation_6720 | [LLM] |
| 00487060 | sub_487060 | [LLM] |
| 004870e0 | sub_4870E0 | [LLM] |
| 00490920 | Accessor | [LLM] |
| 004918d0 | RenderSurfaceFillCopy | [LLM] |
| 00494f00 | ShortComputation_4f00 | [LLM] |
| 00494f10 | UIMessageDispatch | [LLM] |
| 00495150 | GlobalAccessor_5150 | [LLM] |
| 00498880 | DualFieldRead | [LLM] |
| 0049adb0 | ShortComputation_adb0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
