## AudioDSPStateUpdate_00448330 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b950 | SceneNodePositionGetter | [LLM] |
| 0054c210 | SceneGraphChildCount | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 005505a0 | LinkedListAnimationTimerDecrement | [LLM] |
| 00550620 | ScrollingDataOffsetAcrossLinkedEntries | [LLM] |
| 00551810 | ConditionalDispatchByFlag | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
