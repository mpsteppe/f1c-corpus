## ResourceListCleanup_00404d50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x40)+0x0) | 0x0 | R | — | [LLM] |
| *(*(obj+0x40)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x40) | 0x0 | R | — | [LLM] |
| *(obj+0x40) | 0x8 | R | — | [LLM] |
| obj | 0x24 | RW | — | [LLM] |
| obj | 0x40 | RW | 0 | [LLM] |
| obj | 0x44 | RW | 0 | [LLM] |
| obj | 0x48 | RW | 0 | [LLM] |
| obj | 0x4C | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x24: [LLM: once/conditional? does external poke survive?]
- obj 0x40: [LLM: once/conditional? does external poke survive?]
- obj 0x44: [LLM: once/conditional? does external poke survive?]
- obj 0x48: [LLM: once/conditional? does external poke survive?]
- obj 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be714 | FileName | R | serialization constant [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec410 | lpPathName | R | LoadPath / directory pointer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404e60 | LinkedListNodeInsertion | [LLM] |
| 00565dc0 | AllocateStructWithDefaultValues | [LLM] |
| 00565e20 | LinkedListDestructorWithChildCleanup | [LLM] |
| 00565f20 | LinkedListNodePeek | [LLM] |
| 00565f50 | LinkedListPopFront_5f50 | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
