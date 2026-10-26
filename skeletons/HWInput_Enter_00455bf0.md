## HWInput_Enter_00455bf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2c4 | ShowCursor | R | [LLM] |
| 005c5688 | aEnteredHwinput | R | EnteredHwinputString [DERIVED] |
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString [DERIVED] |
| 007d13a0 | byte_7D13A0 | R | RenderFlag_7D13A0 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f4e0 | sub_44F4E0 | [LLM] |
| 00455290 | InputActionRegistration | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f8ae0 | DualSourceAcquireWithFallback | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
