## PlayerProfileScanner_00468ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_92a0 (004692a0), ProfileIconBmpLoader (004692b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x448) | 0x4 | R | — | [LLM] |
| this | 0x444 | RW | 0 | [LLM] |
| this | 0x448 | RW | 0 | [LLM] |
| this | 0x44C | RW | 0 | [LLM] |
| this | 0x450 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x444: [LLM: once/conditional? does external poke survive?]
- this 0x448: [LLM: once/conditional? does external poke survive?]
- this 0x44C: [LLM: once/conditional? does external poke survive?]
- this 0x450: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c66f8 | aProfileiconDft | R | DefaultProfileIconPath [DERIVED] (also: ` — "ProfileIcon_DFT.bmp" default icon) |
| 005c6950 | aProfileiconBmp | R | ProfileIconBmpStr [DERIVED] (also: ` — "ProfileIcon.bmp" string) |
| 005c6960 | aPlr_0 | R | PLRSearchPattern (*.PLR) [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00469630 | SetupFileLoadAndFinalize | [LLM] |
| 0048d230 | LinkedListDestructionWithVTableCall | [LLM] |
| 0048d2b0 | LinkedListNodeAppend | [LLM] |
| 00497ad0 | sub_497AD0 | [LLM] |
| 00565eb0 | sub_565EB0 | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00566380 | sub_566380 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44C | == | 0 | [LLM] |
| this | 0x450 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
