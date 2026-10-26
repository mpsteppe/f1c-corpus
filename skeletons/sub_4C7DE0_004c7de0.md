## sub_4C7DE0_004c7de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTickUpdate (004c8b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0xC)+0x8) | 0x0 | R | — | [LLM] |
| *(*(this+0xC)+0x8) | 0x4 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x8 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0xC | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xC) 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7f30 | UpdateCameraFOV | [LLM] |
| 004c8fc0 | sub_4C8FC0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
