## UIPropertyValueSetter_0055d410 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), sub_55A500 (0055a500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005416a0 | DirectXVertexBufferTextureCoordinateSetup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
