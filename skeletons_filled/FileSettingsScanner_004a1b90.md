## FileSettingsScanner_004a1b90 — FileSettingsScanner

**Summary:** Scans a settings file buffer for configuration key-value pairs. Parses tokens delimited by separators, extracts the key portion by removing substrings, compares the key against a reference path, and calls a virtual callback to process matches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListWalker (004a1d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | next linked list node pointer |
| this | 0x0 | R | — | vtable pointer for callback dispatch |
| this | 0x4 | R | — | reference path string for key comparison |

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
| 00566cc0 | ConditionalDispatchBasedOnFlag | Reads config tokens conditionally into buffer |
| 00566db0 | sub_566DB0 | Cleans up/disposes resource lookup handle |
| 00566e20 | ResourceLookupDispatcher | Opens/looks up resource by filename |
| 00587c20 | sub_587C20 | Searches for substring within token buffer |
| 00596c80 | sub_596C80 | Compares two strings with length limit |

**Guard conditions:** First call to ConditionalDispatchBasedOnFlag must succeed (return non-zero) to enter parsing loop. Inside loop, if token starts with reference path (via sub_596C80 comparison), parsing succeeds. If ConditionalDispatchBasedOnFlag fails at any point, jumps to cleanup (LABEL_22). The virtual callback (this[0]+4) must succeed for the result to be valid. At end, if v3 (token count) != 1, falls through to cleanup.
