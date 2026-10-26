## FileEnumerationByExtension_00421b10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005c2ab0 | unk_5C2AB0 | R | ConfigDirectoryPath [DERIVED] |
| 005c2ab4 | asc_5C2AB4 | R | FileExtGDBBytes [DERIVED] |
| 005c2ab8 | dword_5C2AB8 | R | SceneExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565dc0 | AllocateStructWithDefaultValues | [LLM] |
| 00565e20 | LinkedListDestructorWithChildCleanup | [LLM] |
| 00565ed0 | LinkedListNodeDataPeek | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f50 | LinkedListPopFront_5f50 | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 0058803f | ThreadSafeReadWrapper_803f | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588678 | FileReadWrapperWithLock | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
