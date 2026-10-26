## PathNormalizerFileEnumeration_00432980 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerNameSetup (004326e0), PollingLoopWithBranch (0046e7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00431db0 | DirectoryFileEnumerator | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00568620 | sub_568620 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
