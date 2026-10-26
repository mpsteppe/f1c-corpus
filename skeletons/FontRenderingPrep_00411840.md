## FontRenderingPrep_00411840 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextOverlayDisplayTimer (004186f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004119b0 | sub_4119B0 | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5d0 | dword_5EA5D0 | RW | TrackLoadState [DERIVED] |
| 005ea5d4 | dword_5EA5D4 | W | FileLoadSentinel [DERIVED] |
| 005ea5d8 | dword_5EA5D8 | W | FileEnumSentinel [CONFIRMED] |
| 005ea5dc | dword_5EA5DC | W | FileEnumSentinel [DERIVED] |
| 005ea5e0 | byte_5EA5E0 | RW | InitGateFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004119d0 | ShortComputation_19d0 | [LLM] |
| 00411a00 | ShortComputation_1a00 | [LLM] |
| 00411a50 | ShortComputation_1a50 | [LLM] |
| 00411b50 | CharacterCodeMapper | [LLM] |
| 00411bf0 | RaceEventMessageDispatcher | [LLM] |
| 00411db0 | FontCharacterRenderDispatcher | [LLM] |
| 00411e90 | SoundEventDispatcher | [LLM] |
| 00414140 | DecrementCounterWithFloorAtZero | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587b3e | BooleanToIntConversion | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
