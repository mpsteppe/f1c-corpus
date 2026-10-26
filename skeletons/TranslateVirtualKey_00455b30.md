## TranslateVirtualKey_00455b30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIEventShortcutHandler (0048b600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2b4 | ToAsciiEx | R | [LLM] |
| 0059e2b8 | MapVirtualKeyExA | R | [LLM] |
| 0059e2bc | GetKeyboardState | R | [LLM] |
| 0059e2c0 | GetKeyboardLayout | R | [LLM] |
| 007ca508 | dwhkl | RW | KeyboardLayoutHandle [DERIVED] |
| 007ccab0 | KeyState | R | KeyboardStateBuffer [DERIVED] |
| 007ccbc0 | word_7CCBC0 | W | KeyboardCharBuffer [DERIVED] |
| 007ccc04 | byte_7CCC04 | RW | KeyboardLayoutInitGate [DERIVED] |
| 007ccfc0 | Char | RW | KeyboardCharBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455580 | sub_455580 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
