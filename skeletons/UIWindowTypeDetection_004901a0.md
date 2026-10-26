## UIWindowTypeDetection_004901a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_fec0 (0048fec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | R | — | [LLM] |
| this | 0xE4 | RW | 2 | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005cc210 | aC_0 | R | StrExtension_c [DERIVED] |
| 005cc21c | byte_5CC21C | R | Str_UI_Load [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
