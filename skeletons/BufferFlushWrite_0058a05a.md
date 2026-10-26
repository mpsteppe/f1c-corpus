## BufferFlushWrite_0058a05a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MSVCCRTFileClose (00587d33), FileTellSeekPositionQuery (00587f90), sub_5886A7 (005886a7), MemoryBlockValidationCheck (0058a02c), sub_58AFE1 (0058afe1), ClearStructFieldsIfFlagSet (0058e4a8), sub_59BB00 (0059bb00), FileSeekWithModeFlagValidation (0059c156)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058e22b | sub_58E22B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
