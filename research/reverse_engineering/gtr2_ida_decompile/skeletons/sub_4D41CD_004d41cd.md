## sub_4D41CD_004d41cd — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | [LLM] |
| *(this+0x11C) | 0xA0 | R | — | [LLM] |
| this | 0x90 | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x248 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x90: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x94: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x248: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d4524 | jpt_4D4334 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd3e0 | sub_4CD3E0 | [LLM] |
| 004ce200 | sub_4CE200 | [LLM] |
| 004d4060 | sub_4D4060 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 006308d8 | j_j__free | [LLM] |
| 00631a35 | _atol | [LLM] |
| 00631c0d | __stricmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
