## CameraViewportRenderSetup_004fbd70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderScreenSave (004b40a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x44 | RW | 18446744073709551615 | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xB8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0xB8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cf938 | byte_7CF938 | R | RenderClearFlag [DERIVED] |
| 007cf950 | flt_7CF950 | R | Unknown_Float_Camera [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afec8 | flt_8AFEC8 | R | RenderStateChangeFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c910 | ShortComputation_c910 | [LLM] |
| 004fc550 | sub_4FC550 | [LLM] |
| 00542460 | TripleFieldGetter_2460 | [LLM] |
| 0054b3b0 | ThreeFieldSetterWithSubCall | [LLM] |
| 0054b3f0 | OffsetDispatch | [LLM] |
| 0054bf60 | PitCrewAnimationOffsetUpdate | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
