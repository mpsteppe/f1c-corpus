## sub_4DEB20_004deb20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4612C0 (004612c0), sub_464830 (00464830), sub_4D0D50 (004d0d50), sub_4D6A80 (004d6a80), sub_4E2190 (004e2190), sub_4E2DB0 (004e2db0), sub_4E2FD0 (004e2fd0), sub_4E3B00 (004e3b00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629328 | flt_629328 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419f80 | sub_419F80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
