## sub_4EDF00_004edf00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EDDD0 (004eddd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x619B | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x619B: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fbebc | word_5FBEBC | R | [LLM] |
| 006110e4 | aC12s | R | [LLM] |
| 006110f0 | a15s | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | RW | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005beec8 | _sprintf | [LLM] |
| 005c0803 | __strupr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%c. %-.12s`
- `%-.15s`
