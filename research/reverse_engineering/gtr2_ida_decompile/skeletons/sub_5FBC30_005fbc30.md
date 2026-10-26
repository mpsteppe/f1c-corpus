## sub_5FBC30_005fbc30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FC390 (005fc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fbb50 | ??0_ReaderWriterLock@details@Concurrency@@QAE@XZ | R | [LLM] |
| 006eccfb | SEH_5FBC30 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d1b0 | sub_41D1B0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
