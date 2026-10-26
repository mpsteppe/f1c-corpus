## sub_4EE1E0_004ee1e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e56c6 | SEH_4EE1E0 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f1f34 | aSS | R | [LLM] |
| 0075b2c0 | off_75B2C0 | R | [LLM] |
| 0091ca88 | dword_91CA88 | R | [LLM] |
| 00be1d0c | dword_BE1D0C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 006308d8 | j_j__free | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
