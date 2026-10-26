## sub_48AFF0_0048aff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_48B0D0 (0048b0d0), sub_48B110 (0048b110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x364 | R | — | [LLM] |
| this | 0x368 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x368: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0048b0b4 | jpt_48B061 | R | [LLM] |
| 00601efc | a4dX4dDBit | R | [LLM] |
| 0062a13c | dword_62A13C | W | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1ac0 | sub_4A1AC0 | [LLM] |
| 005a9590 | sub_5A9590 | [LLM] |
| 005a95e0 | sub_5A95E0 | [LLM] |
| 005a9800 | BoundedArrayAccessor_bfd0 [exact] | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%-4d x %-4d %d bit`
