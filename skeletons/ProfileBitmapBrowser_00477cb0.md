## ProfileBitmapBrowser_00477cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xF0) | 0x0 | R | — | [LLM] |
| *(this+0xF4) | 0x4 | R | — | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | RW | 0 | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0xFC | RW | 0 | [LLM] |
| this | 0x174 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6658 | lpExistingFileName | W | sProfileIconBmp [DERIVED] |
| 005c66f8 | aProfileiconDft | R | DefaultProfileIconPath [DERIVED] (also: ` — "ProfileIcon_DFT.bmp" default icon) |
| 005c715c | aBmp_0 | R | BmpString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3f8 | dword_5EC3F8 | R | FontIconPathPtr [DERIVED] |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ebd0 | UIDimensionCapture | [LLM] |
| 0048f5d0 | DoublyLinkedListAppend_f5d0 | [LLM] |
| 0048f640 | UIViewportLayoutCalculator | [LLM] |
| 0048fc50 | UIObjectConstructor_fc50 | [LLM] |
| 0048fc80 | StructFieldCopy_fc80 | [LLM] |
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
| this | 0xFC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
