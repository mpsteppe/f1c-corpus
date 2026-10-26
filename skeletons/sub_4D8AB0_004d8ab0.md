## sub_4D8AB0_004d8ab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceInitWithConstants (004d8220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005d4a48 | off_5D4A48 | R | Ptr_Unknown_Table [DERIVED] |
| 005d4a4c | off_5D4A4C | R | Ptr_VTable_5D4A4C [DERIVED] |
| 005d4a50 | off_5D4A50 | R | TelemetryVTable [DERIVED] |
| 005d4a54 | off_5D4A54 | R | VTablePtr6 [DERIVED] |
| 005d4a58 | off_5D4A58 | R | VtablePtr_5D4A58 [DERIVED] |
| 005d4a5c | off_5D4A5C | R | VTablePtr_5D4A5C [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |
| 008ad388 | dword_8AD388 | R | File_MusicTrackPtr [DERIVED] |
| 008ad38c | dword_8AD38C | R | ResourceHandle_1 [DERIVED] |
| 008ad390 | dword_8AD390 | R | AudioHandleArray [DERIVED] |
| 008ad394 | dword_8AD394 | R | AudioEmitter3 [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8fb0 | sub_4D8FB0 | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 0053cfe0 | sub_53CFE0 | [LLM] |
| 00552fd0 | MaskedFieldSetter | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
