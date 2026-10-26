## sub_5A3EA0_005a3ea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5A2CE0 (005a2ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB4) | 0x1C | R | — | [LLM] |
| *(this+0xB4) | 0x20 | R | — | [LLM] |
| *(this+0xB4) | 0x30 | R | — | [LLM] |
| *(this+0xB4) | 0x34 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xB4) 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a3ef8 | jpt_5A3EB4 | R | [LLM] |
| 005d54dc | flt_5D54DC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a3a90 | sub_5A3A90 | [LLM] |
| 005a3cc0 | sub_5A3CC0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
