## PitStopOrderLoader_004d12c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** IndexedArrayAccessor (004d1410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A8 | RW | 0 | [LLM] |
| this | 0x1AC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1A8: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3a28 | aPitorder | R | String_PitOrder [DERIVED] |
| 005d3a34 | aTeam | R | TeamString [DERIVED] |
| 005d3bd8 | aFalse_0 | R | FalseString [DERIVED] |
| 005d3be0 | aReversepitorde | R | ReversepitordeString [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049adb0 | ShortComputation_adb0 | [LLM] |
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
