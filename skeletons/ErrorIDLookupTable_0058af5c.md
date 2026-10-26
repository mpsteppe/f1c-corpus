## ErrorIDLookupTable_0058af5c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CreateDirectoryAWrapper (00589671), FileDeleteWithErrorHandling (0058986e), MoveFileAWrapperWithErrorHandling (005898d3), ToggleFileReadOnlyAttributeViaWin32API (0058ba36), FileAttributeCheckWithErrorHandling (0058ba75), HandleCloseWithErrorReporting (0058c38e), FileSeekViaSetFilePointer (0058c789), sub_58CA19 (0058ca19), sub_58E290 (0058e290), sub_595AF9 (00595af9), FilePointerSeekWithErrorHandling (00595f82), sub_59B650 (0059b650), sub_59B760 (0059b760), sub_59B9F3 (0059b9f3), sub_59BA1D (0059ba1d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e65c0 | unk_5E65C0 | R | Unk_KeyCodeTable [DERIVED] |
| 005e65c4 | dword_5E65C4 | R | KeyCodeTable [DERIVED] |
| 005e6728 | dword_5E6728 | R | VKeyToAsciiTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | [LLM] |
| 0058afd8 | TLSOffsetGetter_afd8 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
