## PitCrewAnimationOffsetUpdate_0054bf60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewportRenderSetup (004fbd70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x32C | R | — | [LLM] |
| this | 0x330 | R | — | [LLM] |
| this | 0x338 | R | — | [LLM] |
| this | 0x33C | R | — | [LLM] |
| this | 0x368 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x368: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C | > | 0 | [LLM] |
| this | 0x338 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
