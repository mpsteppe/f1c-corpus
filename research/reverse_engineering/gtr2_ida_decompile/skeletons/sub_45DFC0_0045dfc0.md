## sub_45DFC0_0045dfc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** CollisionParameterClampAndStore [structural] (0045e120), sub_45EFE8 (0045efe8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x80)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x80)+0x0) | 0x24 | R | — | [LLM] |
| *(*(this+0x80)+0x0) | 0x64 | R | — | [LLM] |
| *(this+0x80) | 0x0 | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x2CC | R | — | [LLM] |
| this | 0x2DC | R | — | [LLM] |
| this | 0x400 | RW | 6271 | [LLM] |

**Written-by note (persistence):**
- this 0x400: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045e100 | jpt_45E07B | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045deb0 | CollisionResponseCompute [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
