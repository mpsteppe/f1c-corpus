## sub_5FBCC0_005fbcc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FBCC0 (005fbcc0), sub_5FBFF0 (005fbff0), sub_608270 (00608270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x274)+0x0) | 0x0 | RW | — | [LLM] |
| *(*(this+0x27C)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x274) | 0x0 | R | — | [LLM] |
| *(this+0x27C) | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x274 | R | — | [LLM] |
| this | 0x27C | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x274)+0x0) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x27C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072d3ac | flt_72D3AC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005da650 | sub_5DA650 | [LLM] |
| 005dae90 | sub_5DAE90 | [LLM] |
| 005daf80 | sub_5DAF80 | [LLM] |
| 005db1e0 | sub_5DB1E0 | [LLM] |
| 005e4da0 | sub_5E4DA0 | [LLM] |
| 005fbb60 | sub_5FBB60 | [LLM] |
| 005fbcc0 | sub_5FBCC0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
