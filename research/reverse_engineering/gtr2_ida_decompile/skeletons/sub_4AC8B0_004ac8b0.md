## sub_4AC8B0_004ac8b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x24 | R | — | [LLM] |
| obj | 0x28 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x128 | RW | — | [LLM] |
| this | 0x12C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x128: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x12C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006ff7d4 | aCatsteer | R | [LLM] |
| 006ff7e0 | aArms | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00b6e070 | dword_B6E070 | R | [LLM] |
| 00b6e198 | dword_B6E198 | R | [LLM] |
| 00b6f530 | byte_B6F530 | R | [LLM] |
| 00b6f708 | dword_B6F708 | R | [LLM] |
| 00b71cf0 | byte_B71CF0 | R | [LLM] |
| 00be1bd0 | dword_BE1BD0 | R | [LLM] |
| 00be1ce0 | unk_BE1CE0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df3f0 | sub_4DF3F0 | [LLM] |
| 00501cc0 | sub_501CC0 | [LLM] |
| 00539ff0 | sub_539FF0 | [LLM] |
| 0053bde0 | sub_53BDE0 | [LLM] |
| 005da9a0 | sub_5DA9A0 | [LLM] |
| 005f12d0 | sub_5F12D0 | [LLM] |
| 005f1530 | sub_5F1530 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `CATSTEER`
- `ARMS`
