## sub_4B7CA0_004b7ca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| obj | 0xA8 | R | — | [LLM] |
| obj | 0xAC | R | — | [LLM] |
| obj | 0xB0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x13C | RW | — | [LLM] |
| this | 0x140 | RW | — | [LLM] |
| this | 0x144 | RW | — | [LLM] |
| this | 0x154 | RW | 0 | [LLM] |
| this | 0x160 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x13C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x140: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x144: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x154: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b77f0 | sub_4B77F0 | [LLM] |
| 004cfc30 | sub_4CFC30 | [LLM] |
| 004cfc70 | sub_4CFC70 | [LLM] |
| 004d3b60 | sub_4D3B60 | [LLM] |
| 004d6060 | sub_4D6060 | [LLM] |
| 004e0080 | sub_4E0080 | [LLM] |
| 004e3df0 | sub_4E3DF0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00631c0d | __stricmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
