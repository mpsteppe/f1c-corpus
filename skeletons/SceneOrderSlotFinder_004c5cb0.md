## SceneOrderSlotFinder_004c5cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C5C80 (004c5c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0xC | RW | 2147483647 | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d28b4 | aSceneorder | R | SceneOrderStringConst [DERIVED] (also: ` — "SceneOrder" string constant) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | [LLM] |
| 005679a0 | NullCheckWrapper | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
