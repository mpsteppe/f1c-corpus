## ResourceFileLoader_004f9d60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0), sub_496380 (00496380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004537b0 | sub_4537B0 | [LLM] |
| 00494fb0 | ShortComputation_4fb0 | [LLM] |
| 00494fd0 | ThunkToFUN0053cb90 | [LLM] |
| 00495080 | sub_495080 | [LLM] |
| 004950c0 | ShortComputation_50c0 | [LLM] |
| 00495150 | GlobalAccessor_5150 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 00543250 | ClippedRenderRegion | [LLM] |
| 00568ba0 | StructZeroInit_8ba0 | [LLM] |
| 00568be0 | QPCTimerInitialization | [LLM] |
| 00568d90 | PerformanceCounterDiffWithScaling | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
