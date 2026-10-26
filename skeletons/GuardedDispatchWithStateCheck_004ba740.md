## GuardedDispatchWithStateCheck_004ba740 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d005c | dword_7D005C | R | SessionCleanupFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b97e0 | RenderToggleRefresh | [LLM] |
| 004b9880 | sub_4B9880 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
