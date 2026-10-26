## sub_4B2EE0_004b2ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xBC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x124: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f3f70 | aD | R | [LLM] |
| 00700720 | aDamage_0 | R | [LLM] |
| 00b6f530 | byte_B6F530 | R | [LLM] |
| 00b71dec | dword_B71DEC | RW | [LLM] |
| 00b71df4 | dword_B71DF4 | R | [LLM] |
| 00b71df8 | dword_B71DF8 | R | [LLM] |
| 00faec84 | byte_FAEC84 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d380 | sub_48D380 | [LLM] |
| 00501730 | sub_501730 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00616840 | FileStreamReader [structural] | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00631a35 | _atol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Damage`
- `Damage`
