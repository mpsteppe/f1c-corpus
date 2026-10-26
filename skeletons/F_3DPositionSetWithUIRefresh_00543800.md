## F_3DPositionSetWithUIRefresh_00543800 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | RW | — | [LLM] |
| this | 0x180 | RW | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x17C: [LLM: once/conditional? does external poke survive?]
- this 0x180: [LLM: once/conditional? does external poke survive?]
- this 0x184: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541670 | VTableDispatchWithFieldCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
