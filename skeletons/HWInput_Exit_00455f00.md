## HWInput_Exit_00455f00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x8 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x1B10 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1B10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString [DERIVED] |
| 005c5734 | aEnteredHwinput_4 | R | EnteredHwInputString [DERIVED] |
| 007d13a0 | byte_7D13A0 | R | RenderFlag_7D13A0 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044efe0 | CollisionCullCleanup | [LLM] |
| 0044f5f0 | CursorResourceCleanup | [LLM] |
| 0044fbe0 | CollisionObjectDestructor | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f8c90 | ModuleUnload | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
