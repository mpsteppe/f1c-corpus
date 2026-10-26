## TGATextureFileScanner_004c3a00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileINILoader (004c38d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3074 | byte_5D3074 | R | TgaFileFilterString [DERIVED] (also: ` — "*.tga" filter string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565dc0 | AllocateStructWithDefaultValues | [LLM] |
| 00565e20 | LinkedListDestructorWithChildCleanup | [LLM] |
| 00565eb0 | sub_565EB0 | [LLM] |
| 00565ef0 | ReversePathSearchForBackslashSeparator | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f50 | LinkedListPopFront_5f50 | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00566380 | sub_566380 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566810 | sub_566810 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
