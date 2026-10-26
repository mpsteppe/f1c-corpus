## ServerSessionGateCheck_0042ae60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Overtaking (0042af70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4094 | R | — | lapOfRun [CONFIRMED] |
| this | 0x454C | R | — | callToBox [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4094 | == | 2 | lapOfRun [CONFIRMED] |
| this | 0x454C | != | 1 | callToBox [CONFIRMED] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
