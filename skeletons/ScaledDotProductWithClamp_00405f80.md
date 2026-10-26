## ScaledDotProductWithClamp_00405f80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundPositioningUpdate (00405b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x7C | R | — | [LLM] |
| *(this+0x54) | 0x80 | R | — | [LLM] |
| *(this+0x54) | 0x84 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x48 | RW | 1040187392 → 0.125f | [LLM] |
| this | 0x54 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e4e4 | flt_59E4E4 | R | SmallEpsilon [DERIVED] (also: Small epsilon/prevent-division-by-zero (~0.0f) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
