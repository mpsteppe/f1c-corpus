## sub_4A3FF0_004a3ff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_470540 (00470540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x114 | RW | 0 | [LLM] |
| this | 0x118 | RW | 0 | [LLM] |
| this | 0x11C | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x114: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x118: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9d40 | off_5E9D40 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049c450 | sub_49C450 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
