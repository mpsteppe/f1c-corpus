## sub_5AACC0_005aacc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5AB3E0 (005ab3e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1160) | 0x90 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1160 | R | — | [LLM] |
| this | 0x2194 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00593e60 | sub_593E60 | [LLM] |
| 0059fdc0 | ClippedRenderRegion [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
