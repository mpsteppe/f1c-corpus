## DriverAbbreviationNameFormatter_004c6a10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetDriverName (004c6980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4707 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4707: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005d3200 | aC11s | R | AbbreviationFormat ("%c. %-11s") [DERIVED] |
| 005d320c | a13s | R | FullNameFormatString [DERIVED] (also: ` — `"%-13s"` full-name format) |
| 005d3214 | aAbbreviation | R | AbbreviationSectionName [DERIVED] (also: ` — "Abbreviation" section name constant) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
