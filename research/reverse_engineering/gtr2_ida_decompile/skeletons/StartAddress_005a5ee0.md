## StartAddress_005a5ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | [LLM] |
| obj | 0x50 | R | — | [LLM] |
| obj | 0x54 | R | — | [LLM] |
| obj | 0xA8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ea6b3 | SEH_5A5EE0 | R | [LLM] |
| 006f1184 | ReleaseMutex | R | [LLM] |
| 006f1188 | WaitForSingleObject | R | [LLM] |
| 006f11d4 | SleepEx | R | [LLM] |
| 006f1e9c | flt_6F1E9C | R | [LLM] |
| 006f4da8 | dbl_6F4DA8 | R | [LLM] |
| 00726388 | flt_726388 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | [LLM] |
| 005a3e40 | sub_5A3E40 | [LLM] |
| 005a4e50 | sub_5A4E50 | [LLM] |
| 00617e70 | sub_617E70 | [LLM] |
| 00617ed0 | sub_617ED0 | [LLM] |
| 00617f80 | sub_617F80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
