## InputCommandDispatchToEntities_0045f4a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionResponseStatus (00463cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x410 | R | — | [LLM] |
| this | 0x3C74 | R | — | [LLM] |
| this | 0x3E14 | R | — | [LLM] |
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] |
| 0083ee60 | dword_83EE60 | R | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461440 | ReferencesGlobalState | [LLM] |
| 00461470 | ThunkToFUN00461480 | [LLM] |
| 004614c0 | TwoStageCheck | [LLM] |
| 00461530 | FlagBitTest | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 00462300 | SingleFunctionDispatch | [LLM] |
| 00462310 | SingleFunctionForward | [LLM] |
| 00465300 | sub_465300 | [LLM] |
| 00465460 | EntityVisibilityGridManager | [LLM] |
| 00465c30 | LinkedListPopFront | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b3af0 | AdvanceRingBuffer | [LLM] |
| 004b3b30 | SessionDataCopy | [LLM] |
| 0057a730 | sub_57A730 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | > | 0 | [LLM] |
| this | 0x3FC4 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
