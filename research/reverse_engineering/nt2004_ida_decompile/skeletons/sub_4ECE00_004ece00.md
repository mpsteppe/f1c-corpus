## sub_4ECE00_004ece00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4ED810 (004ed810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB4) | 0x0 | R | — | [LLM] |
| *(this+0xBC) | 0x4 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xBC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
