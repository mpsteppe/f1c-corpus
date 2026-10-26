## OSMan_Enter_004a18d0 — [LLM: short descriptive name]

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
| 0059e188 | GetLastError | R | [LLM] |
| 0059e1ac | CreateMutexA | R | [LLM] |
| 005cd0b4 | Name | R | s_Name [DERIVED] |
| 005cd0d4 | aEnteredOsmanEn | R | EnteredOsmanEn [DERIVED] |
| 005cd0ec | aDDevF119992002_19 | R | sBuildVersion [DERIVED] |
| 007ce2d8 | hObject | W | FileHandle_7CE2D8 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
