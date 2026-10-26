## TickUpdateDispatch_0040e170 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50), sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x8)+0xAF4)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x8)+0xAF4) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0xAF4 | R | — | [LLM] |
| *(this+0x88) | 0x24 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | [LLM] |
| 004347c0 | EngineGuardedInitializer | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x88) | 0x24 | == | 10 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
