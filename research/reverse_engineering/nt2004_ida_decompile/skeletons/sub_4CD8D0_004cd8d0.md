## sub_4CD8D0_004cd8d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_49C1D0 (0049c1d0), sub_4CD8D0 (004cd8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x57A0 | RW | 1 | [LLM] |
| this | 0x57A1 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x57A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x57A1: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb7e8 | Format | R | [LLM] |
| 00601e14 | aPlayer | R | [LLM] |
| 00608634 | aPlr | R | [LLM] |
| 0060f750 | off_60F750 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a0d0 | dword_62A0D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd8d0 | sub_4CD8D0 | [LLM] |
| 004cd9c0 | StringCopyFileCheckDispatch [structural] | [LLM] |
| 004cded0 | sub_4CDED0 | [LLM] |
| 00578870 | AllocateStructWithDefaultValues [structural] | [LLM] |
| 005788d0 | sub_5788D0 | [LLM] |
| 00578a30 | sub_578A30 | [LLM] |
| 00578d80 | DirectoryEntryIterator [structural] | [LLM] |
| 00578e30 | sub_578E30 | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `Player`
- `.PLR`
- `*%s`
