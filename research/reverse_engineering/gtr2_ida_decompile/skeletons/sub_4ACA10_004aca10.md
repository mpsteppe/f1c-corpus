## sub_4ACA10_004aca10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | R | — | [LLM] |
| this | 0x114 | RW | 1084227584 → 5.0f | [LLM] |

**Written-by note (persistence):**
- this 0x114: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00b6f708 | dword_B6F708 | R | [LLM] |
| 00b6f724 | dword_B6F724 | R | [LLM] |
| 00b6f740 | dword_B6F740 | R | [LLM] |
| 00b72314 | dword_B72314 | R | [LLM] |
| 00be1bd0 | dword_BE1BD0 | W | [LLM] |
| 00be1cdc | unk_BE1CDC | R | [LLM] |
| 00be1ce0 | unk_BE1CE0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00538790 | sub_538790 | [LLM] |
| 00539600 | sub_539600 | [LLM] |
| 00539ff0 | sub_539FF0 | [LLM] |
| 0053a0e0 | sub_53A0E0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00631c76 | _atof | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
