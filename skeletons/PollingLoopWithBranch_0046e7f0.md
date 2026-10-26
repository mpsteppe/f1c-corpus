## PollingLoopWithBranch_0046e7f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x168 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004328f0 | StringEmptyCheck | [LLM] |
| 00432980 | PathNormalizerFileEnumeration | [LLM] |
| 00432a10 | DirectoryPathExtraction | [LLM] |
| 00489920 | UIScreenTextAccessor | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
