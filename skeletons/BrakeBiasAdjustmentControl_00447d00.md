## BrakeBiasAdjustmentControl_00447d00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1564 | RW | — | [LLM] |
| this | 0x156C | R | — | [LLM] |
| this | 0x1574 | R | — | [LLM] |
| this | 0x157C | R | — | [LLM] |
| this | 0x1580 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1564: recalc every frame — external poke does NOT persist
- this 0x1580: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005c4394 | aS41f41f | R | Str_S41F41F [DERIVED] |
| 005c43a4 | aBrakeBias | R | StringBrakeBias [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045bdf0 | ShortComputation_bdf0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
