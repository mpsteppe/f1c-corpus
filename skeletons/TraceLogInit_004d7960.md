## TraceLogInit_004d7960 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D7A00 (004d7a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c680c | aW | R | StringW [DERIVED] |
| 005d4a04 | aTraceLevelD | R | TraceLevelD [DERIVED] |
| 005d4a18 | aStraceTxt | R | StraceTxtFormat [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587db0 | sub_587DB0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 005887b1 | StringFormatWithNestedIO | [LLM] |
| 00589671 | CreateDirectoryAWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
