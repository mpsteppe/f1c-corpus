## sub_4AF4C0_004af4c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4A8B20 (004a8b20), sub_4AF330 (004af330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004afe40 | sub_4AFE40 | [LLM] |
| 004aff20 | sub_4AFF20 | [LLM] |
| 004b0090 | sub_4B0090 | [LLM] |
| 004b1540 | sub_4B1540 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
