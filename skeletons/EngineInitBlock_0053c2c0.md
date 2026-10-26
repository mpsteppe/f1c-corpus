## EngineInitBlock_0053c2c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SystemInitAllocatorWrapper (0053d470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6bd0 | unk_8B6BD0 | R | UTF16_Buffer [DERIVED] |
| 008b6c20 | qword_8B6C20 | W | RendererStateFlag [DERIVED] |
| 008b8e40 | qword_8B8E40 | W | AudioMixFixedPointConst [DERIVED] |
| 008b8ed8 | qword_8B8ED8 | W | AudioPlaybackRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | [LLM] |
| 00556260 | sub_556260 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
