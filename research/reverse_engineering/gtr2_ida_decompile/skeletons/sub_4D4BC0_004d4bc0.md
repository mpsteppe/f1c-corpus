## sub_4D4BC0_004d4bc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f4dc8 | flt_6F4DC8 | R | [LLM] |
| 006f9500 | flt_6F9500 | R | [LLM] |
| 00b6e198 | dword_B6E198 | R | [LLM] |
| 00b6e2a0 | unk_B6E2A0 | R | [LLM] |
| 00fb1ce0 | dword_FB1CE0 | R | [LLM] |
| 00fb1e98 | unk_FB1E98 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ddfe0 | sub_4DDFE0 | [LLM] |
| 0058f290 | sub_58F290 | [LLM] |
| 0058f2c0 | sub_58F2C0 | [LLM] |
| 005dcfa0 | sub_5DCFA0 | [LLM] |
| 005e5050 | sub_5E5050 | [LLM] |
| 005e53e0 | sub_5E53E0 | [LLM] |
| 005e55e0 | sub_5E55E0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
