## sub_5BD3F0_005bd3f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x0 | R | — | [LLM] |
| *(this+0x74) | 0x2 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x4A0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bd4d8 | jpt_5BD437 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bca10 | sub_5BCA10 | [LLM] |
| 005bd4f0 | sub_5BD4F0 | [LLM] |
| 005bd5c0 | StateGetSetWrapper [structural] | [LLM] |
| 005bd600 | sub_5BD600 | [LLM] |
| 005c2590 | _memcpy | [LLM] |
| 005d26d4 | ntohs [exact] | [LLM] |
| 005d2710 | send [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x78 | < | 3 | [LLM] |
| this | 0x78 | >= | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
