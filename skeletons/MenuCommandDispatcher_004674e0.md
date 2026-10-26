## MenuCommandDispatcher_004674e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00467674 | jpt_467506 | R | [LLM] |
| 00467684 | byte_467684 | R | [LLM] |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |
| 007c7378 | byte_7C7378 | W | MenuStateFlag [DERIVED] (also: ` — menu state flag (written 0) |
| 007c737c | dword_7C737C | R | [LLM] |
| 007d048c | byte_7D048C | R | UIBypassFlag [DERIVED] (also: ` — conditional flag for menu path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ec00 | MessageStringFormatter | [LLM] |
| 00431950 | SetupIntegerFormatDS | [LLM] |
| 00431aa0 | SetupDateAngleDisplayFormat | [LLM] |
| 00489600 | UIMenuItemCreator | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x178 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
