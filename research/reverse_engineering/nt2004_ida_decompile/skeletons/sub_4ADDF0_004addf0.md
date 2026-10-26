## sub_4ADDF0_004addf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_476B30 (00476b30), sub_4A01C0 (004a01c0), sub_4A9940 (004a9940), sub_4AE2C0 (004ae2c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C | RW | — | [LLM] |
| this | 0x160 | RW | — | [LLM] |
| this | 0x164 | RW | — | [LLM] |
| this | 0x168 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x15C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x160: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x164: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004adef0 | sub_4ADEF0 | [LLM] |
| 004b0b30 | sub_4B0B30 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
