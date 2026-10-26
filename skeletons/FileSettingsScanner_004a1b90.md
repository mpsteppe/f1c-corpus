## FileSettingsScanner_004a1b90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListWalker (004a1d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b0 | asc_5C30B0 | R | StringDelimiter_CStr [DERIVED] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c30b8 | unk_5C30B8 | R | QuoteDelimiter [DERIVED] (also: /b4/b0/ac` — delimiter/separator character constants) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00566db0 | sub_566DB0 | [LLM] |
| 00566e20 | ResourceLookupDispatcher | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00596c80 | sub_596C80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
