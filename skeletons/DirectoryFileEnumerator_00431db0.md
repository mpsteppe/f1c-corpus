## DirectoryFileEnumerator_00431db0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSetupFileRead (00432180), Wrapper (004326d0), PathNormalizerFileEnumeration (00432980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x8 | R | — | [LLM] |
| *(this+0x30) | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | RW | 0 | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0e0 | FindFirstFileA | R | [LLM] |
| 0059e0e4 | FindNextFileA | R | [LLM] |
| 0059e0e8 | FindClose | R | [LLM] |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c2ab4 | asc_5C2AB4 | R | FileExtGDBBytes [DERIVED] |
| 005c2ab8 | dword_5C2AB8 | R | SceneExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| ff00000000005396 | byte_FF00000000005396 | R | [LLM] |
| ff0000000000539e | byte_FF0000000000539E | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | [LLM] |
| 00434030 | DoublyLinkedListAppend | [LLM] |
| 00434090 | LinkedListMergeSort | [LLM] |
| 00434290 | LinkedListMergeSort_4290 | [LLM] |
| 00434420 | DoublePointerFree | [LLM] |
| 004bac20 | ShortComputation_ac20 | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568910 | sub_568910 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
