## sub_4DBB40_004dbb40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DC3C0 (004dc3c0), sub_4DD1F0 (004dd1f0), sub_4DD510 (004dd510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x308 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1508 | MessageBoxA | R | [LLM] |
| 006f2e64 | word_6F2E64 | R | [LLM] |
| 006f4910 | aS_12 | R | [LLM] |
| 006f6668 | word_6F6668 | R | [LLM] |
| 00712ac0 | Caption | R | [LLM] |
| 00712ad0 | aOscSOnLineD | R | [LLM] |
| 00712ae8 | aCriticalError | R | [LLM] |
| 00712af8 | aError | R | [LLM] |
| 00712b00 | aWarning | R | [LLM] |
| 00712b08 | aUndefinedError | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004de410 | StringBasedLookup [exact] | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00633e7f | _exit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s
`
- `OSC Read Error`
- `OSC %s on line %d : `
- `Critical Error`
- `Error`
- `Warning`
- `Undefined Error`
