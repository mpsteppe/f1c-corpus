## UICustomRenderDispatch_00489fd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DSurfaceBlitWithViewportClipping (0048a240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x90)+0x8C)+0x0) | 0x34 | R | — | [LLM] |
| *(*(*(this+0x90)+0x8C)+0x8C) | 0x8C | R | — | [LLM] |
| *(*(this+0x90)+0x8C) | 0x0 | R | — | [LLM] |
| *(*(this+0x90)+0x8C) | 0x8C | R | — | [LLM] |
| *(*(this+0x90)+0x8C) | 0xA0 | R | — | [LLM] |
| *(*(this+0x90)+0x8C) | 0xE4 | RW | — | [LLM] |
| *(this+0xC8) | 0x40 | R | — | [LLM] |
| *(this+0xC8) | 0x48 | R | — | [LLM] |
| obj | 0x18 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x131 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x90)+0x8C) 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | [LLM] |
| 00497ec0 | DriverNameStringHandler | [LLM] |
| 00497f90 | StringArrayMatchSearch | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 0049a9c0 | ShortComputation_a9c0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x158 | < | 1 | [LLM] |
| this | 0x16C | < | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
